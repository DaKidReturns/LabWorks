/*******************************************
 * Stack Implementation using a Linked List
 * Done By: Rohit Karunakaran
 * *****************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Linked_List_Node
{
    struct Linked_List_Node *link;
    int data;
}Node;

typedef struct Linked_Stack
{
    Node *Top;
}Stack;

Stack* initStack()
{
    Stack *s = (Stack*) malloc (sizeof(Stack));
    s->Top = NULL;
    return s;
}


//Insertion Algorithms
void push(Stack *s,int val)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node!=NULL)
    {
        new_node->data = val; 
        new_node->link = s->Top;
        s->Top = new_node;
    }
    else
    {
        printf("Stack Is Full");
        exit(1);
    }
    return ;
}

//Deletion Algorithms
int pop(Stack *s)
{
    if(s->Top == NULL)
    {
        printf("Stack Is Empty");
        exit(0);
        return 0;
    }
    else
    {
        Node* ptr = s->Top;
        s->Top = s->Top->link;
        int elem = ptr->data;
        free(ptr);
        return elem;
    }
}

void displayStack(Stack *s)
{
    Node* ptr = s->Top;
    if(ptr!=NULL)
    {
        printf("The Stack is: Top -> ");
        while(ptr!=NULL)
        {
            if(ptr==s->Top){
                printf("%d\n",ptr->data);
            }
            else{
                printf("                     %d\n",ptr->data);
            } 
            ptr=ptr->link;
        }
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }
}

int menu(Stack* s)
{
    int RUN = 1;
    while(RUN)
    {
        printf("\n");
        printf("=============================\n");
        printf("            MENU             \n");
        printf("=============================\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display the stack\n");
        printf("4.Exit\n");
        printf("Enter Choice: ");
        int choice;
        int elem;
        scanf("%d%*c",&choice);
        
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%d%*c",&elem);
                    push(s,elem);
                    printf("\n");
                    break;
            case 2: elem = pop(s);
                    printf("The Element removed is %d",elem);
                    printf("\n");
                    break;
            case 3: displayStack(s);
                    break;
            case 4: RUN=0;
                    break;
            default: printf("Enter a valid choice\n");
                     printf("\n");
                     break;

        }

    }
    printf("Exiting........");
    return RUN;
}


int main()
{
    Stack *s = initStack();
    return menu(s);

}
