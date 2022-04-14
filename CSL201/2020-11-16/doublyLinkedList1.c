/***************************************
 * Program to check whether the given 
 * string is palindrome using doubly linked list
 * Done By: Rohit Karunaran
 * *************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct char_doubly_linked_list
{
    struct char_doubly_linked_list *next;
    struct char_doubly_linked_list *prev;
    char data;
} ddchar;

void initString(ddchar **Header)
{
    *Header = (ddchar*)malloc(sizeof(ddchar));
    (*Header)->next = NULL;
    (*Header)->prev = NULL;
}

void insert(ddchar *Header,char ch)
{
    ddchar *newNode = (ddchar*)malloc(sizeof(ddchar));
    
    if(newNode!=NULL)
    {
        ddchar *Tail = Header;
        newNode->data = ch;
        if(Header->next == NULL) //That is the string is empty
        {
            Tail = NULL;
            Header->next = newNode;   
            newNode->prev = Header;
            newNode->next=NULL;
        }
        else
        {
            while(Tail->next!=NULL) Tail = Tail->next;
            Tail->next = newNode;
            newNode->prev = Tail;
            newNode->next=NULL;
        }
        
    }
}
 void stringToList(ddchar *Header,char *s)
{
    for(int i=0;s[i]!='\0';i++)
        insert(Header,s[i]);
}

int checkPalindrome(ddchar *Header)
{
    ddchar *i,*j;
    if(Header->next!=NULL)
    {
        i=Header->next;
        j=Header;
        while(j->next!=NULL)j=j->next; //j becomes the tail pointer

        while(i!=NULL&&j!=Header)
        {
            if(i->data!=j->data)
                break;
            i=i->next;
            j=j->prev;
        }
        if(i==NULL && j==Header)
        {
            return 1;
        }
        return 0;
    }
    else{
        return 0;
    }
}

int main()
{
    ddchar *str = (ddchar*) malloc(sizeof(ddchar));
    initString(&str);
    char input[50];
    printf("Enter the string to be checked : ");
    scanf("%[^\n]%*c",input);
    stringToList(str,input);
    if(checkPalindrome(str))
    {
        printf("The String is palindorme\n");
    }
    else
    {
        printf("The String is not palindorme\n");
    }
    return 0;
}
