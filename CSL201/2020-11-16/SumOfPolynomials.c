/***************************************
 * Sum And Product of a Polynomial
 * Done By Rohit Karunakaran
 **************************************/

#include<stdio.h>
#include<stdlib.h>

/*  Input : 2 polynomials of the form
 *          a0*X^n + a1*X^n-1 + a2*X^n-2 ..... an
 *  Output: First polynomial the second polynomial and there sum
 */

typedef struct Node
{
   int coeff;
   int pow; 
   struct Node* link;
}PolyNode;

typedef struct Polynomial
{
    int numberOfTerms;
    PolyNode* Head; //Header contians the first polynomial, so it has to be printed
    PolyNode* Trail;
}Poly;

//UTILITY FUNCTIONS START

void initPoly(Poly **a)
{
    *a = (Poly*)malloc(sizeof(Poly));
    (*a)->Head = NULL;
    (*a)->Trail= NULL;
    (*a)->numberOfTerms=0;
}

void addNode(Poly *a,int pow, int coeff)
{
    PolyNode* n = (PolyNode*) malloc(sizeof(PolyNode));
    if(n!=NULL){
        n->coeff = coeff; n->pow = pow; n->link=NULL;
        if(a->Trail ==NULL)
        {
            a->Head = n;    
        }
        else
        {
            a->Trail->link = n;   
        }
        a->Trail = n;
    }
    else
    {
        return;
    }
}

void deleteNode(Poly *a,PolyNode *b)
{
    PolyNode *ptr=a->Head;
    if(ptr==NULL)return;

    while(ptr->link!=b&&ptr!=NULL){ptr=ptr->link;} //Traverse till you find the node b

    if(ptr==NULL){return;} //If there is no such node then, return

    else 
    {
        if(ptr->link->link==NULL)
        {
            free(ptr->link);
            ptr->link=NULL;
        }
        else
        {
            PolyNode *tmp = ptr->link;
            ptr->link = tmp->link;
            free(tmp);
        }
    }
}

void freePoly(Poly **poly)
{
    if(*poly !=NULL)
    {
        PolyNode *i,*tmp;
        i=(*poly)->Head;
        while(i!=NULL)
        {
            tmp=i;
            i=i->link;
            free(tmp);
        }
        free (*poly);
    }
    return;
}

//UTILITY FUNCTIONS END

/* Funtion to print the polynomials*/
void printPoly(Poly* a){
    /* Input: Polynomial stored in the structure Polynomial
     * Ouput: prints the polynomial
     */

    //int iterCount = a->numberOfTerms;
    //int i; 
    PolyNode *ptr=a->Head;
    while(ptr!=a->Trail){
        printf("%d*X^%d + ",ptr->coeff,ptr->pow);
        ptr = ptr->link;
    }
    printf("%d*X^%d",ptr->coeff,ptr->pow);
}

/* Funtion to convert the polynomial into tuple*/
Poly* createPolyFromString(char* s){
    /* Input: String of charecters
     * 
     * Output: the Head node of the linked list contating the polynomial
     * */

    Poly* a=NULL;initPoly(&a);
    int i;

    int count = 0;
    int numberStack[2];
    int numberStackTop = -1;

    int number = 0,pow,coeff;
    int negative = 0;

    //parsing the string
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
                pow = numberStack[numberStackTop--];
                coeff = numberStack[numberStackTop--];
                addNode(a,pow,coeff);
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
    pow = numberStack[numberStackTop--];
    coeff = numberStack[numberStackTop--];
    addNode(a,pow,coeff);

    a->numberOfTerms = count;

    return a;
}

/*Funtion to find the sum of the polynomials*/
Poly* sumOfPoly(Poly* a, Poly* b)
{
    Poly* c = (Poly*)malloc(sizeof(Poly));
    initPoly(&c);

    PolyNode *i=a->Head;
    PolyNode *j=b->Head;

    while(i!=NULL&&j!=NULL)
    {

        if(i->pow==j->pow)
        {
            if(i->coeff+j->coeff!=0)
                addNode(c,i->pow,i->coeff+j->coeff);
            
            i=i->link;
            j=j->link;
        }
        else if(i->pow>j->pow)
        {
            addNode(c,i->pow,i->coeff);
            i=i->link;
        }
        else if(i->pow<j->pow)
        {
            addNode(c,j->pow,j->coeff);
            j=j->link;
        }
        c->numberOfTerms++;
    }

    while(i!=NULL)
    {
        addNode(c,i->pow,i->coeff);
        i=i->link;
        c->numberOfTerms++;
    }
    while(j!=NULL)
    {
        addNode(c,j->pow,j->coeff);
        j=j->link;
        c->numberOfTerms++;
    }

    return c;
}

Poly* productOfPolynomials(Poly* a,Poly*b)
{
    Poly *c=NULL;
    Poly *temp=NULL;
    //intiPoly(Temp);

    int k = 0;
    PolyNode *i = a->Head;
    PolyNode *j = b->Head;

    while(k<a->numberOfTerms)
    {
        //i=a->Head;
        j=b->Head;
        if(c==NULL)
        {
            initPoly(&c);
            while(j!=NULL)
            {
                addNode(c,i->pow+j->pow,i->coeff*j->coeff);
                j=j->link;
            }
        }
        else
        {
            initPoly(&temp);
            while(j!=NULL)
            {
                addNode(temp,i->pow+j->pow,i->coeff*j->coeff);
                j=j->link;
            }
            c=sumOfPoly(c,temp);
        }
        i=i->link;
        freePoly(&temp);
        k++;
    }
    return c;
}

int main(){
    Poly* a;
    Poly* b;
    Poly* c;
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

    c = productOfPolynomials(a,b);
    printf("\nProduct is ");
    printPoly(c);
    printf("\n");

    freePoly(&a);
    freePoly(&b);
    freePoly(&c);
    return 0;
}
