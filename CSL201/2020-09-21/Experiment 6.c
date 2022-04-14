#include<stdio.h>
#include<stdlib.h>

/*  Input : 2 polynomials of the form
 *          a0*X^n + a1*X^n-1 + a2*X^n-2 ..... an
 *  Output: First polynomial the second polynomial and there sum
 */

/* Funtion to print the polynomials*/
void printPoly(int** a){
    int iterCount = a[0][0];
    int i; 
    for(i = 1;i<iterCount;i++)
        printf("%d*X^%d + ",a[i][1],a[i][0]);
    printf("%d*X^%d\n",a[i][1],a[i][0]);
}

/* Funtion to convert the polynomial into tuple*/
int** createPolyFromString(char* s){
    int** a;
    int i;
    int maxPolySize = 10;
    
    int count = 0;
    int numberStack[10];
    int numberStackTop = -1;

    int number = 0;
    int negative = 0;

    //parsing the string

    a = (int**) malloc(maxPolySize*sizeof(int*));
    for(i = 0;i<maxPolySize;i++){
        a[i] = (int*)malloc(2*sizeof(int));
    }

    for(i = 0; s[i]!='\0'; i++){
        if(s[i] == '-'){
            negative = 1;
        }
        
        if(s[i]>='0'&&s[i]<='9'){
            while((s[i]!= 'X'||s[i]!='x'||s[i]!=' '||s[i]!='^') && (s[i]>='0'&&s[i]<='9')){
                 // here s[i] will only be numbers
                number = number*10+(s[i]-'0');
                i++;
            }

            if(negative) numberStack[++numberStackTop] = -1*number;
            else numberStack[++numberStackTop] = number;
            
            i--;
            negative = 0;
            number = 0;
        }

        if(i!=0&&(s[i]=='-'||s[i]=='+'||s[i]=='\0')){//&&s[i-1]!='^'){
            if(numberStackTop==0)
            {
                if(s[i-1]=='X')
                    numberStack[++numberStackTop] = 1;
                else
                    numberStack[++numberStackTop] = 0;
            }

                count++;
                a[count][0] = numberStack[numberStackTop--];
                a[count][1] = numberStack[numberStackTop--];
        }
    }

    if(numberStackTop==0)
    {
        if(s[i-1]=='X')
            numberStack[++numberStackTop] = 1;
        else
            numberStack[++numberStackTop] = 0;
    }
    count++;
    a[count][0] = numberStack[numberStackTop--];
    a[count][1] = numberStack[numberStackTop--];

    a[0][0] = count;

    return a;
}

/*Funtion to find the sum of the polynomials*/
int** sumOfPoly(int** a, int** b){
    int totalSize = a[0][0] + b[0][0]+2;
    int **c;
    int count = 0;
    c = (int**) malloc(totalSize*sizeof(int*));
    
    int i,j;
    for(i = 0;i<totalSize;i++){
        c[i] = (int*) malloc(2*sizeof(int));   
    }
    
    i=1,j=1;
    while(i<=a[0][0]&&j<=b[0][0]){
        //If the powers are same then add the coefficients
        if(a[i][0]==b[j][0]){
            if(a[i][1]+b[j][1]==0){
                i++;j++;
                continue;
            }
            else{
                count++;
                c[count][0] = a[i][0];
                c[count][1] = a[i][1]+b[j][1];
                i++;j++;
            }
        }
        //If the powers arent same then push the one with the highest power into polynomial c
        else if(a[i][0]<b[j][0]){
            count++;
            c[count][0] = b[j][0];
            c[count][1] = b[j][1];
            j++;
        }
        else if(b[j][0]<a[i][0]){
            count++;
            c[count][0] = a[i][0];
            c[count][1] = a[i][1];
            i++;
        }
    }

    /* If the while loop abve terminates prematurely i.e. after the elements of the shorter of the two
       polynomial is added to the c polynomial*/

    while(i<=a[0][0]){
        count++;
        c[count][0] = a[i][0];
        c[count][1] = a[i][1];
        i++;
    }

    while(j<=b[0][0]){
        count++;
        c[count][0] = b[j][0];
        c[count][1] = b[j][1];
        j++;
    }
    
    c[0][0] = count;
    return c;
}

void main(){
    int** a;
    int** b;
    int** c;
    int strLength = 100;
    char* polyString = (char*) malloc(strLength*sizeof(char));

    /*Read the polynomials*/
        fflush(stdin);
        printf("Enter polynomial 1 in the form : a0*X^n + a1*X^n-1 + a2*X^n-2 ..... an*X^0 --> ");
        scanf("%[^\n]",polyString);
        scanf("%*c"); //remove the \n charecter from the input stream
        a  = createPolyFromString(polyString);    
        free(polyString);
    
        fflush(stdin);
        fflush(stdout);
    
        polyString = (char*) malloc(strLength*sizeof(char));

        printf("Enter polynomial 2 in the form : a0*X^n + a1*X^n-1 + a2*X^n-2 ..... an*X^0 --> ");
        scanf("%[^\n]",polyString);
        b  = createPolyFromString(polyString);    
        free(polyString);
    /*Finish reading Polynomials*/

    printf("\nPolynomial 1 is: ");
    printPoly(a);
    printf("\nPolynomial 2 is: ");
    printPoly(b);
    
    c = sumOfPoly(a,b); //Find the sum of the polynomials 

    printf("\nSum is ");
    printPoly(c);
    free(a);
    free(b);
    free(c);
}
