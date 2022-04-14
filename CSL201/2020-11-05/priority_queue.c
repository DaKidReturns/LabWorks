/* Priority Queue implemetation using dynamic array
 *  Done By : Rohit Karuankaran
 * */


#include <stdlib.h>
#include <stdio.h>
#define SIZE 32


typedef struct priority_queue
{
    int **Q;
    int size;
    int front;
    int rear;
}pqueue;

void initQueue(pqueue *q)
{
    q->size = SIZE;
    q->Q = (int**) malloc(q->size*sizeof(int*));

    for (int i = 0;i<q->size;i++)
        q->Q[i] = (int*)malloc(2*sizeof(int));

    q->front = -1;
    q->rear = -1;
}

void delQueue(pqueue *q)
{
    for(int i =0;i<q->size;i++)
        free(q->Q[i]);
    free(q->Q);
}

void enQueue(pqueue *q,int elem,int p)
{
    if(q->rear>=q->size)
    {
        printf("The Queue is full Inseriton not possible\n");
        delQueue(q);
        exit(1);

    }
    else
    {
        if(q->front==-1)
        {
            q->front=q->front+1;
        }
        q->rear = q->rear+1;
        q->Q[q->rear][0] = elem;
        q->Q[q->rear][1] = p;
        return;
    }
}

int deQueue(pqueue *q)
{
    if(q->front == -1)
    {
        printf("QUEUE IS EMPTY THERE IS NO ELEMENT TO DELETE\n");
        return -1;
    }
    
    else
    {
        int ptr = q->front;
        int pos =ptr;
        int priority = q->Q[q->front][1];
        while(ptr<=q->rear)
        {
            if(q->Q[ptr][1]<priority)
            {
                priority = q->Q[ptr][1];
                pos = ptr;
            }
            ptr++;
        }

        int elem = q->Q[pos][0];

        if(pos !=q->front)
        {
            while(pos>q->front)
            {
                pos--;
                q->Q[pos+1][0] =q->Q[pos][0]; 
                q->Q[pos+1][1] =q->Q[pos][1]; 
            }
        }

        if(q->front==q->rear)
        {
            q->rear =-1;
            q->front =-1;
        }
        else{
            q->front +=1;
        }
        return elem;
    }
}

void displayQueue(pqueue *q)
{
    int i = q->front;
    if(q->front==-1)
    {
        printf("EMPTY");
        return;
    }
    while(i>=0&&i<=q->rear)
    {
        printf("%d ",q->Q[i][0]);
        i++;
    }

}

int main()
{
    pqueue *myQueue = (pqueue*) malloc(sizeof(pqueue));

    int RUN = 1;
    int elem;
    int priority;
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
                    printf("Enter the priority of the element : ");
                    scanf("%d%*c",&priority);
                    enQueue(myQueue,elem,priority);
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
