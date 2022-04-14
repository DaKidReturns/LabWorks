#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define SYM_TAB_MAX_SIZE 64
#define DEBUG 1


struct symTabEntry{
    char name[64];
    char address[8];
}ste;

struct opcode
{
    char name[8];
    char code[4];
};


char* AssemblerDirectives[] ={"START", "WORD", "RESW", "RESB","BYTE","END"};
struct opcode operandList[26] =
{
{"ADD", "18"},
{"AND",	"40"},
{"COMP","28"},
{"DIV",	"24"},
{"J","3C"},
{"JEQ","30"},
{"JGT","34"},
{"JLT","38"},
{"JSUB","48"},
{"LDA","00"},	
{"LDCH","50"},
{"LDL","08"},
{"LDX","04"},
{"MUL","20"},
{"OR","44"},
{"RD","D8"},
{"RSUB","4C"},
{"STA","0C"},
{"STCH","54"},
{"STL","14"},
{"STSW","E8"},
{"STX","10"},
{"SUB","1C"},
{"TD","E0"},
{"TIX" , "2C"},
{"WD",	"DC"}
};

int operandListSize = 26;

struct symTabEntry symTab[SYM_TAB_MAX_SIZE];
int symTabPointer = -1;

int isoperand(char* _opcode);
void clear_input(FILE*);
char* readLine(FILE*,char*);
int is_number(char*,int); 
int write_error(FILE*,const char*);
int findByteLength(char*);
void findByteValue(char* _input, char* _output);
int searchSymTab(char* label);
int firstPass(FILE*, FILE*);
int secondPass(FILE* , FILE*,FILE*,int);
int readHexdecimal(const char*);
int getInstruction(char*, int, int, char*);
void writeCurrentTextRecord(char* recordWriter, int* recordStartAddress,int* recordLength, FILE* objectFile );
void openNewTextRecord(char* recordWriter, int* recordStartAddress,int* recordLength);


int main(int argc, char* argsv[]){
    char interm_filename[256]; 
    char obj_filename[256];

    if (argc < 2){
        printf("Useage: \n output.o [filename to be assembled]\n");
        return 0;
    }

    if (DEBUG)
        printf("File is : %s\n",argsv[1]);

    FILE* input =  fopen(argsv[1],"rb");
    strcpy(interm_filename,argsv[1]);
    strcat(interm_filename,".interm");

    FILE* interm_file = fopen(interm_filename,"w");
    int file_size = firstPass(input,interm_file);
    
    fopen(interm_filename,"r");
    strcpy(obj_filename,argsv[1]);
    strcat(obj_filename,".obj");
    FILE* obj_file = fopen(obj_filename,"w");
    FILE* intem = fopen("intemfile","wb");

    secondPass(interm_file,obj_file,intem,file_size);


    return 0;
}

int secondPass(FILE* input, FILE* output, FILE* intem, int file_size){
    char* line_buffer = (char*) malloc(1024*sizeof(char));
    char* buffer_start = line_buffer;
    char record_writer[1024];
    char temp[256];
    char r_operand[64];
    char r_opcode[64];
    char label[64];
    char column_values[3][32];
    
    int startAddress = 0;
    int column_count = 0;
    int startFound = 0;
    int endFound = 0;
    int operandFound = 0;
    int instruction = 0;
    int textRecordLength = 0;
    int textRecordStartAddress = 0;
    int textRecordOpened = 0;

    do{
         // buffer_start prevents the memory leak caused by readLine.
        line_buffer = readLine(input,buffer_start); /// this function can cause memory leaks take care while re-using it.
    }while(line_buffer == NULL || (line_buffer[0] == '/'&&line_buffer[1]=='/') );

    // A line has been found and now to write the header record
    strcpy(record_writer,"H,");
    
    //fprintf(intem,"%s\n", line_buffer);
    
    char *token = strtok(line_buffer, " \t");
    while(token&&column_count <4) {
        strcpy(column_values[column_count],token);
        token = strtok(NULL, " ");
        column_count ++;
    }

    if(column_count == 4 && strcmp(column_values[2],"START") == 0){
        //startAddress = readHexdecimal(column_values[0]);
        sscanf(column_values[0],"%X",&startAddress);
        startFound = 1;
        line_buffer = readLine(input,buffer_start);
        sprintf(temp,"%-6s,",column_values[1]);
        strcat(record_writer,temp);

    }
    if(!startFound) {
        // if start is not found
        sscanf(column_values[0],"%X",&startAddress);
        strcat(record_writer,"pg1   ,");
    }

    //Write the header record to the file;
    sprintf(temp,"%06X,%06X",startAddress,file_size);
    fprintf(output,"%s%s\n",record_writer,temp);

    //Initialize the header record
    sprintf(record_writer,"T,%06x,  ",startAddress);
    textRecordLength = 0;
    textRecordStartAddress = startAddress;
    textRecordOpened = 1;

    while(!endFound){
        // if it is a comment line

        column_count = 0;
        operandFound = 0;
        instruction = 0;
        if(line_buffer[0] == '/' && line_buffer[1] == '/'){
            line_buffer = readLine(input, buffer_start);
            continue;
        }

        token = strtok(line_buffer, " \t");
        while(token&&column_count <4) {
            strcpy(column_values[column_count],token);
            token = strtok(NULL, " ");
            column_count ++;
        }
        
        switch(column_count){
            case 2: // only opcode
                    strcpy(r_opcode,column_values[1]);
                    break;
            case 3: // opcode and operand
                    strcpy(r_opcode,column_values[1]);
                    strcpy(r_operand,column_values[2]);
                    operandFound = 1;
                    break;
            case 4: // opcode operand and a label
                    strcpy(r_opcode,column_values[2]);
                    strcpy(r_operand,column_values[3]);
                    operandFound = 1;
                    break;
        }

        int opCode = isoperand(r_opcode);

        if(opCode != -1){ // if it is an instruction
            if(!textRecordOpened){ // check if a text record is opened.
                openNewTextRecord(record_writer,&textRecordStartAddress,&textRecordLength);
                textRecordOpened = 1;
            }
            instruction = getInstruction(r_opcode,opCode,operandFound,r_operand);
            sprintf(temp,",%06X",instruction);

            if(textRecordLength+3 > 30){
                // write the current record and start a new record
                writeCurrentTextRecord(record_writer,&textRecordStartAddress,&textRecordLength, output);
                textRecordOpened = 0;
            }
            else{
                if(!textRecordOpened){
                    openNewTextRecord(record_writer,&textRecordStartAddress,&textRecordLength);
                    textRecordOpened = 1;
                }
            }
            //append the current record
            strcat(record_writer,temp);
            textRecordLength += 3;

        }else if(!strcmp(r_opcode,"WORD")){
                int operand;
                sscanf(r_operand,"%X",&operand);
                sprintf(temp,",%06X", operand);
                if(textRecordLength + 3>30){ //check if adding the byte will increase the text record length more than 30
                    writeCurrentTextRecord(record_writer,&textRecordStartAddress,&textRecordLength,output);
                    textRecordOpened = 0;
                }
                if(!textRecordOpened){
                    openNewTextRecord(record_writer,&textRecordStartAddress,&textRecordLength);
                    textRecordOpened = 1;
                }
                strcat(record_writer,temp);
                textRecordLength += 3;

        }else if(!strcmp(r_opcode,"BYTE")){
                findByteValue(r_operand,temp);
                int length = findByteLength(r_operand);
                if(textRecordLength + length >30){
                    writeCurrentTextRecord(record_writer,&textRecordStartAddress,&textRecordLength,output);
                    textRecordOpened = 0;
                }
                if(!textRecordOpened){
                    openNewTextRecord(record_writer,&textRecordStartAddress,&textRecordLength);
                    textRecordOpened = 1;
                }
                strcat(record_writer,temp);
                textRecordLength += length;
        }else if(!strcmp(r_opcode,"RESW")){
            int length;
            sscanf(r_operand,"%X",&length);
            
            if(textRecordOpened){
                writeCurrentTextRecord(record_writer,&textRecordStartAddress,&textRecordLength,output);
                textRecordOpened = 0;
            }
            textRecordStartAddress += (3*length);
        }
        else if(!strcmp(r_opcode,"RESB")){
            int length;
            sscanf(r_operand,"%X",&length);
            if(textRecordOpened){
                writeCurrentTextRecord(record_writer,&textRecordStartAddress,&textRecordLength,output);
                textRecordOpened = 0;
            }
            textRecordStartAddress += (length);
        }
        else if(!strcmp(r_opcode,"END")){
                endFound = 1;
        }

        if(!endFound)
            line_buffer = readLine(input,buffer_start);
    }

    if(textRecordOpened)
        writeCurrentTextRecord(record_writer,&textRecordStartAddress,&textRecordLength, output);
    // Put the end record here
    fprintf(output,"E,%06X",startAddress);
return 0;
}

void findByteValue(char* _input, char* _output){
    int operand = 0;
    char* pointer = _input;
    int length = findByteLength(_input);
    int i;
    if(pointer[0] == 'c' || pointer[0] == 'C'){
        pointer += 2;
        for(i = 0; i<length; i++){
            //printf("value of pointer %p\n",pointer);
            operand = operand <<8 | pointer[i];
        }
        sprintf(_output,",%X",operand);
    }else if(pointer[0] == 'h' || pointer[0] == 'H'){
        pointer += 2; //pointing to the first hexadeimal charecter;
        i = strlen(pointer);
        //printf("%d\n",i);
        pointer[i] = '\0';
        int digitLength = i -1;
        int pos;
        char* endPointer = _output +  2*length +1;
        (*endPointer) = '\0';
        endPointer --;
        for(i=0; i<2*length ;i++){
            if(i<digitLength){
                pos = digitLength - i - 1;
                if(pointer[pos] >='0' && pointer[pos]<='9'){
                    (*endPointer) = pointer[pos];
                }else if(pointer[pos] >='A' && pointer[pos]<='F'){
                    (*endPointer) = pointer[pos];
                }else if(pointer[pos] >='a' && pointer[pos] <= 'f'){
                    (*endPointer) = pointer[pos] - 'a' + 'A';
                }
            }
            else
                (*endPointer) = '0' ;
            endPointer--;
        }
    }
}

void writeCurrentTextRecord(char* recordWriter, int* recordStartAddress,int* recordLength, FILE* outputFile){
    char temp[3];
    sprintf(temp,"%02X",*recordLength);
    for(int i=9; i<=10; i++){
        recordWriter[i] =temp[i-9];
    }
    fprintf(outputFile,"%s\n",recordWriter);
    (*recordStartAddress) += (*recordLength);
}

void openNewTextRecord(char* recordWriter, int* recordStartAddress,int* recordLength){
    sprintf(recordWriter,"T,%06X,  ",(*recordStartAddress));
    (*recordLength) = 0;
}

int getInstruction(char* _opcode, int _opLoc, int _operandFlag, char* _operand){
    int inst = 0;
    int indexed = 0;
    int address;
    int symPos;
    int operandLength;
    sscanf(operandList[_opLoc].code,"%x",&inst);
    inst = inst << 16;
    if(_operandFlag){
        operandLength = strlen(_operand); // last two charecters of operand
        if(_operand[operandLength - 1] =='X'&& _operand[operandLength - 2] ==',' ){
            inst = inst | 1<<15;
            indexed = 1;
            _operand[operandLength-2] = '\0';
            //INST\0X
        }

        symPos = searchSymTab(_operand);
        if(symPos != -1){
            sscanf(symTab[symPos].address,"%X",&address);
            inst = inst | (address);
        }else{
            printf("[Error]: Operand %s is not found in symbol table!!",_operand);
        }
    }
    //printf("%06x\n",inst);
    return inst; 
}

int firstPass(FILE* input ,FILE* output){
    int startLoc = 0, counter = 0;
    char* line_buffer = (char*) malloc(1024*sizeof(char));
    char* buff_start = line_buffer;
    char column_values[3][32];
    int startFound = 0;
    int line = 0;

    int column_count;  // number of column read.
    int instrt_flag;   // if an instruction found or not.
    int psudo_inst_flag; // if a psudo opcode is found or not.
    int label_found;
    int error;
    int fileLength = -1;
    
    if(input == NULL){
        printf("[ERROR]: File Pointer returned null.\tExiting.....\n");
        fclose(input);
        fclose(output);
        exit(1);
    }

    //Put while loop here;  // done :-P 
    int i=0; // i is used just for debugging purposes
    do{
        line_buffer = buff_start;
        //printf("line_buffer %p\n",line_buffer);
        char label[32];
        char r_operand[32];
        char r_opcode[32]; // opcode read from file
        int labelLenght = 0;
        column_count =0;
        label_found = 0;
        instrt_flag = 0;
        psudo_inst_flag = 0;
        error = 0;
        line ++;
        if ((line_buffer = readLine(input, line_buffer)) == NULL) continue; // read a line to the string buffer // returns -1 if EOF is encounterd or the line is empty
        if(DEBUG == 1)
            printf("%s\n",line_buffer);

        char *token = strtok(line_buffer, " \t");
        while(token&&column_count <3) {
            strcpy(column_values[column_count],token);
            token = strtok(NULL, " ");
            column_count ++;
        }

        if (DEBUG == 2){
            for(int i=0; i<column_count;i++){
                printf("Column %d: %s ",i+1,column_values[i]) ;
            }
            printf("\n");
        }

        if(column_values[0][0] == '/' && column_values[0][1]=='/') continue;
        
        switch(column_count){
            case 1: strcpy(r_opcode, column_values[0]);
                    break;
            case 2: strcpy(r_opcode,column_values[0]);
                    strcpy(r_operand,column_values[1]);
                    break;
            case 3: strcpy(r_opcode,column_values[1]);
                    strcpy(r_operand,column_values[2]);
                    strcpy(label,column_values[0]);
                    //set label flag
                    label_found = 1;
                    int labelLength = strlen(label);
                    if(label[labelLength - 1] =='X'&& label[labelLength - 2] ==',' )
                        label[labelLength -2] = '\0';
                    if(searchSymTab(label) == -1){
                        symTabPointer++;
                        strcpy(symTab[symTabPointer].name,label);
                        sprintf(symTab[symTabPointer].address,"%x",counter);                    
                    }
                    else{
                        char msg[64];
                        sprintf(msg,"Symbol %s already defined.",label);
                        write_error(output,msg);
                    }
                    break;
        }
        
        instrt_flag = isoperand(r_opcode);

        if(instrt_flag != -1){
            // process as regular instruction;
            switch(column_count){
                case 1: fprintf(output,"%X\t%s\n",counter,r_opcode);
                        break;
                case 2: fprintf(output,"%X\t%s %s\n",counter,r_opcode,r_operand);
                        break;
                case 3: fprintf(output,"%X %s %s %s\n",counter,label,r_opcode,r_operand);
                        break;
            }
            counter += 3;
        }
        else{
            // check for assembler directives; 
            if (strcmp(r_opcode,"START")==0){
                if(!startFound){
                    counter = strtol(r_operand,NULL,16); //convert the operand to hexadecimal and store it as the counter.
                    startLoc = counter;
                    //printf("Starting at : %d\n",counter);
                    if(label_found)
                        fprintf(output,"%X %s %s %s\n",counter, label,r_opcode,r_operand);       
                    else
                        fprintf(output,"%X %s %s %s\n",counter, "pg1",r_opcode,r_operand);       
                    psudo_inst_flag = 1;
                    startFound = 1;
                }
                else{
                    write_error(output,"START directive can only be used once!!!");
                    error = 1;
                }
            }
            else if(strcmp(r_opcode,"WORD")== 0){
                if(!label_found){
                    write_error(output,"Error: Assembler directive WORD can't have an empty label field");
                    error = 1;
                }
                if(!error){
                    fprintf(output,"%X %s %s %s\n",counter, label,r_opcode,r_operand);
                    counter +=3;
                }
                psudo_inst_flag = 1;
            }
            else if(strcmp(r_opcode,"BYTE")== 0){
                if(!label_found){
                    write_error(output,"Error: Assembler directive BYTE can't have an empty label field");
                    error = 1;
                }
                if(!error){
                    int len = findByteLength(r_operand);
                    fprintf(output,"%X %s %s %s\n", counter,label,r_opcode,r_operand);
                    counter += len;
                }
                psudo_inst_flag = 1;

            }
            else if(strcmp(r_opcode,"RESW")== 0){
                if(!label_found){
                    write_error(output,"Error: Assembler directive RESW can't have an empty label field");
                    error = 1;
                }
                if(!error){
                    fprintf(output,"%X %s %s %s\n", counter,label,r_opcode,r_operand);
                    counter += 3*strtol(r_operand,NULL,10);
                }
                psudo_inst_flag = 1;
            }
            else if(strcmp(r_opcode,"RESB")== 0){
                if(!label_found){
                    write_error(output,"Error: Assembler directive RESB can't have an empty label field");
                    error = 1;
                }
                if(!error){
                    fprintf(output,"%X %s %s %s\n", counter,label,r_opcode,r_operand);
                    counter += strtol(r_operand,NULL,10);
                }
                psudo_inst_flag = 1;
            }
            else if(strcmp(r_opcode,"END")== 0){
                fprintf(output,"%X %s \n", counter,r_opcode);
                psudo_inst_flag = 1;
                break;
            }
        }
        if(!startFound) startFound  =1;
    }while(!feof(input));
    fileLength = counter - startLoc;
    
    if(DEBUG){
        printf("File Length = %d\n",fileLength);
        printf("%d lines read\n",line);
    }

    if(DEBUG){
        printf("\nSYMBOL TABLE\n");
        for(int i=0; i<=symTabPointer;i++){
            printf("%s %s\n", symTab[i].name,symTab[i].address);
        }
    }

    fclose(input);
    fclose(output);
    free(line_buffer);
    return fileLength;
}

int isoperand(char* _opcode){
    for(int i=0; i<operandListSize; i++)
        if(strcmp(_opcode,operandList[i].name)==0)
            return i;
return -1;
}

int searchSymTab(char* label){
    int i=0;
    int found = 0;
    for(i = 0;i<=symTabPointer;i++){
        if(strcmp(symTab[i].name,label) == 0) return i;
    }
    return -1;
}

char* readLine(FILE* input,char* line){
    int b, wc;
    fgets(line,1024,input); // Read a single line from the file (max length 1024)
    if(DEBUG == 3){
        printf("In function readLine\n%s",line);
    }

    // BEGIN THE SACRED TRIMMING PROCESS (warning!! can cause memory leaks use with caution. TOOOOOOO POWERFULLLLLLL)
    while(isspace(*line)) line++; 
    b = strlen(line);

    char* end = line + b - 1;
    while((isspace(*end))&& end != line){ end--; }
    *(end+1) = '\0';

    if((*line) == '\0') return NULL;
    return line; // retruns the starting location of the trimmed string.
}

int is_number(char* str, int base){
    int i;
    if (base == 10){
        for(i=0; str[i]!='\0'; i++){
            if(!isdigit(str[i])){
                return 0;
            }
        }
    }
    if(base == 16){
        int len = strlen(str);
        str[len-1] = '\0';
        for(i=0; str[i]!='\0'; i++){
            if(!isxdigit(str[i])){
                return 0;
            }
        }
    }
    return 1;
}

int write_error(FILE* output, const char* str){
    return fprintf(output,"//%s\n",str);
}

int findByteLength(char* str){
    int number = -1;
    int num_chars=0;
    int sp_chr = 0;
    int ret_value;

    char* start = strchr(str,'\'');
    char* end = strrchr(str,'\'');
    char* i;

    if(str[0] == 'c' || str[0] == 'C'){
        number = 0;
    }
    else if(str[0] == 'h' || str[0] == 'H'){
        number = 1;
    }
    for(i=(start+1);i!= end; i++){
        if(!number && !sp_chr &&*i == '\\'){ 
            sp_chr = 1;
            continue;
        }
        num_chars ++;
    } 
    if(number){
        ret_value = (int)(ceil((num_chars/2.0)));
    }else{
        ret_value = num_chars;
    }
    return ret_value;
}

int readHexdecimal(const char* hexstring){
    unsigned int a;
    int number = 0;
    int i = 0;
    while(hexstring[i] != '\0'){
        a = hexstring[i];
        if(a>= '0' && a<='9'){
            a -='0';
        }
        else if(a>='A' && a<='F'){
            a = a - 'A' +10; 
        }
        number = number << 4 | a;
        
        i++;
    }
    return number;
}