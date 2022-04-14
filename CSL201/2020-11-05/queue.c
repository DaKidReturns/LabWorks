/* Queue implemetation using dynamic array
 *  Done By : Rohit Karuankaran
 * */


#include <stdlib.h>
#include <stdio.h>
//#define SIZE 50


typedef struct queue_structure_datatype
{
    int *Q;
    int size;
    int front;
    int rear;
}queue;

void initQueue(queue *q)
{
    q->size = 16;
    q->Q = (int*) malloc(q->size*sizeof(int));
    q->front = -1;
    q->rear = -1;
}

void delQueue(queue *q)
{
    free(q->Q);
}

void incrSize(queue *q)
{
    q->size = 2*(q->size);
    int *tmp = (int*) realloc (q->Q,q->size*sizeof(int));
    if(tmp==NULL)
    {
        printf("Heap is full memory not available");
    }
    else
    {
        q->Q = tmp;
    }
}


void enQueue(queue *q,int elem)
{
    if(q->rear>=q->size)
    {
       // printf("The Queue is full Inseriton not possible\n");
        incrSize(q);

    }
    else
    {
        if(q->front==-1)
        {
            q->front=q->front+1;
        }
        q->rear = q->rear+1;
        q->Q[q->rear] = elem;
        return;
    }
}

int deQueue(queue *q)
{
    if(q->front == -1)
    {
        printf("QUEUE IS EMPTY THERE IS NO ELEMENT TO DELETE\n");
        return -1;
    }
    
    else
    {
        int elem = q->Q[q->front];

        if(q->front==q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }

        else
            q->front=q->front+1;
        return elem;
    }
}

void displayQueue(queue *q)
{
    int i = q->front;
    if(q->front)
    {
        printf("EMPTY");
        return;
    }
    while(i>=0&&i<=q->rear)
    {
        printf("%d ",q->Q[i]);
        i++;
    }

}

int main()
{
    queue *myQueue = (queue*) malloc(sizeof(queue));
    int RUN = 1;
    int elem;
    int choice;
    initQueue(myQueue);
    while(RUN)
    {
        printf("=======================\n");
        printf("        Menu\n");
        printf("=======================\n\n");
        printf("1.Enter into the queue\n");
        printf("2.Remove from the queue\n");
        printf("3.Display the queue\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");

        scanf("%d%*c",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element you want to enter into the Queue : ");
                    scanf("%d%*c",&elem);
                    enQueue(myQueue,elem);
                    break;
                    
            case 2: elem = deQueue(myQueue);
                    printf("The element remove is :%d\n",elem);
                    break;
            
            case 3: printf("The Queue is: ");
                    displayQueue(myQueue);
                    printf("\n");
                    break;
            case 4: RUN = 0;
                    break;
            default: printf("Enter a valid input\n\n");
        }
    }

    /*
    insert(myQueue,32);
    insert(myQueue,21);
    displayQueue(myQueue);
    */
    delQueue(myQueue);
    printf("\nExiting.....\n");
    
}
