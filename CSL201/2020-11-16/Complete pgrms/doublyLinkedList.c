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
    (*Header)->next = *Header;
    (*Header)->prev = *Header;
}

void insert(ddchar *Header,char ch)
{
    ddchar *newNode = (ddchar*)malloc(sizeof(ddchar));
    
    if(newNode!=NULL)
    {
        newNode->data = ch;
        newNode->next=Header;
        newNode->prev = Header->prev;
        if(Header->next == Header) //That is the string is empty
        {
            Header->next = newNode;   
        }
        else
        {
            Header->prev->next = newNode;
        }
        Header->prev=newNode;
        
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
    if(Header->next!=Header)
    {
        i=Header->next;
        j=Header->prev;
        while(i!=Header&&j!=Header)
        {
            if(i->data!=j->data)
                break;
            i=i->next;
            j=j->prev;
        }
        if(i==Header && j==Header)
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
        printf("The String is palindorme");
    }
    else
    {
        printf("The String is not palindorme");
    }
    return 0;
}
