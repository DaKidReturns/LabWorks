#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void main()
{
  FILE *inputFilePointer, *outputFilePointer;
  int i,l,j,staddrInt;
  char recordLine[50],objcodeName[10],staddr[10];

  
  inputFilePointer = fopen("abssrc.txt","r");
  outputFilePointer = fopen("memorydump.txt","w");
  
  fscanf(inputFilePointer,"%s",recordLine);
  
  for(i=2,j=0;i<8,j<6;i++,j++)
    	objcodeName[j]=recordLine[i];
  objcodeName[j]='\0';
  
  printf("Program name from object code %s\n\n",objcodeName);
  
  do
    {
        fscanf(inputFilePointer,"%s",recordLine);
        if(recordLine[0]=='T')
        {
	        for(i=2,j=0;i<8,j<6;i++,j++)
	        	staddr[j]=recordLine[i];
	        	
	        staddr[j]='\0';
	        staddrInt=atoi(staddr);
	        i=12;
	        while(recordLine[i]!='\0')
	        {
	          if(recordLine[i]!='^')
	          {
		    fprintf(outputFilePointer,"%06d \t %c%c\n", staddrInt,recordLine[i],recordLine[i+1]);
		    printf("00%d \t %c%c\n", staddrInt,recordLine[i],recordLine[i+1]);
		    staddrInt++;
		    i=i+2;
	          }
	          else i++;
	        }
        }
        else if(recordLine[0]='E'){
        		printf("\nProgram loaded to memeory successfully\n");
        		break;
        	}
   }while(!feof(inputFilePointer));
   
   fclose(inputFilePointer);
   fclose(outputFilePointer);
}
