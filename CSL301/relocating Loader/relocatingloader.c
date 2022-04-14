#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void convert(char h[12]);
char bitmask[13];
char bit[12]={0};

void main()
{
    char add[8],length[10],input[256],binary[12],relocbit,ch,pn[7],addressStr[7],tlenStr[4],opcodeStr[4],addrStr[6];
    int j;
    char* substr;
    int start,inp,len,i,address,opcode,addr,actualadd,tlen,recPtr;
    FILE *fp1,*fp2;

    printf("\n\n Enter the actual starting address : ");
    scanf("%x",&start);
    
    fp1=fopen("RLIN.txt","r");
    fp2=fopen("RLOUT.txt","w");
    
    fscanf(fp1,"%s",input);
    
    if (input[0] == 'H'){ // Header record
        for(i=2,j=0; i<8 ;i++,j++)pn[j] = input[i];
        pn[j] = '\0';
        i++;
        for(j=0; j<6&&input[i]!='^';j++,i++)add[j] = input[i];
        add[j] ='\0';
        i++;
        for(j=0; j<6&&input[i]!='^';j++,i++)length[j] = input[i];
        length[j] = '\0';  
        printf("Length of the program = %s\n",length);
        
    }
    
    fprintf(fp2," ----------------------------\n");
    fprintf(fp2," ADDRESS\tCONTENT\n");
    fprintf(fp2," ----------------------------\n");
    
    while(input[0] != 'E')
    {
        fscanf(fp1,"%s",input);
        if(input[0] == 'T')
        {
            i=2;
            
            for(j=0;j<6; i++,j++) addressStr[j] = input[i];
            addressStr[j] = '\0';
            i++;
            
            sscanf(addressStr,"%x",&address);
            
            for(j=0; j<2;j++,i++) tlenStr[j] = input[i];
            tlenStr[j] = '\0';            
            i++;
            
            sscanf(tlenStr,"%x",&tlen);
            
            for(j=0; j<3;j++,i++) bitmask[j] = input[i];
            bitmask[j] = '\0';            
            i++;
 
            address+=start;
            convert(bitmask);
            len=strlen(bit);
            if(len>=11)
                len=10;
            recPtr =16;    
            for(i=0;i<len;i++)
            {
                for(j=0; j<2;j++,recPtr++)opcodeStr[j] = input[recPtr];
                opcodeStr[2] = '\0';
                
                for(j=0; j<4;j++,recPtr++)addrStr[j] = input[recPtr];
                addrStr[4] = '\0';
                recPtr++;
                
                sscanf(opcodeStr,"%x",&opcode);
                sscanf(addrStr,"%x",&addr);
                relocbit=bit[i];
                if(relocbit=='0')
                    actualadd=addr;
                else
                    actualadd=addr+start;
                fprintf(fp2,"  %x\t\t%x%x\n",address,opcode,actualadd);
                address+=3;
            }
        }
    }
    fprintf(fp2," ----------------------------\n");
    fclose(fp2);
    fclose(fp1);
    printf("\n\n The contents of output file (RLOUT.TXT)\n");
    fp2=fopen("RLOUT.txt","r");
    ch=fgetc(fp2);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(fp2);
    }
    fclose(fp2);
    getc(stdin);
}


void convert(char h[13])
{
    int i,l;
    strcpy(bit,"");
    l=strlen(h);
    for(i=0;i<l;i++)
    {
        switch(h[i])
        {
            case '0':
                strcat(bit,"0");
                break;
            case '1':
                strcat(bit,"1");
                break;
            case '2':
                strcat(bit,"10");
                break;
            case '3':
                strcat(bit,"11");
                break;
            case '4':
                strcat(bit,"100");
                break;
            case '5':
                strcat(bit,"101");
                break;
            case '6':
                strcat(bit,"110");
                break;
            case '7':
                strcat(bit,"111");
                break;
            case '8':
                strcat(bit,"1000");
                break;
            case '9':
                strcat(bit,"1001");
                break;
            case 'A':
                strcat(bit,"1010");
                break;
            case 'B':
                strcat(bit,"1011");
                break;
            case 'C':
                strcat(bit,"1100");
                break;
            case 'D':
                strcat(bit,"1101");
                break;
            case 'E':
                strcat(bit,"1110");
                break;
            case 'F':
                strcat(bit,"1111");
                break;
        }
    }
}
