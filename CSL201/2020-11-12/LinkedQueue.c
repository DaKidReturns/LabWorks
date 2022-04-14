/******************************************
 * Queue Implementation Using Linked List
 * Done By: Rohit Karunakaran
 * ****************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Linked_List_Node
{
    struct Linked_List_Node *link;
    int data;
}Node;

typedef struct Linked_Queue
{
    Node* Front;
    Node* Rear;
}Queue;

Queue* initQueue()
{
    Queue *q = (Queue*) malloc (sizeof(Queue));
    q->Front = NULL;
    q->Rear = NULL;
    return q;
}


//Insertion Algorithm
void enQueue(Queue *q,int val)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node!=NULL)
    {
        new_node->link=NULL;
        new_node->data = val;
        if(q->Rear == NULL)
        {
            q->Front = new_node;
        }
        else
        {
             q->Rear->link = new_node;
        }
        q->Rear = new_node;
    }
    else
    {
        printf("Queue Is Full");
        exit(1);
    }
    return ;
}

//Deletion Algorithm
int deQueue(Queue *q)
{
    if(q->Front == NULL)
    {
        printf("Queue Is Empty");
        exit(0);
        return 0;
    }
    else
    {
        Node* ptr = q->Front;
        q->Front = q->Front->link;
        int elem = ptr->data;
        free(ptr);
        return elem;
    }
}

void displayQueue(Queue *q)
{
    Node* ptr = q->Front;
    if(ptr!=NULL)
    {
        printf("The Queue is: ");
        while(ptr!=NULL)
        {
            if(ptr->link!=NULL)
                printf("%d -> ",ptr->data);
            else
                printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
    else
    {
        printf("The Queue is empty\n");
    }
}

int menu(Queue* q)
{
    int RUN = 1;
    while(RUN)
    {
        printf("\n");
        printf("=============================\n");
        printf("            MENU             \n");
        printf("=============================\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter Choice: ");
        int choice;
        int elem;
        scanf("%d%*c",&choice);
        
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%d%*c",&elem);
                    enQueue(q,elem);
                    printf("\n");
                    break;
            case 2: elem = deQueue(q);
                    printf("The Element removed is %d",elem);
                    printf("\n");
                    break;
            case 3: displayQueue(q);
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
    Queue *q = initQueue();
    return menu(q);

}
