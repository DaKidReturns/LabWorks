/* Deque implemetation using dynamic array
 *  Done By : Rohit Karuankaran
 * */

#include <stdlib.h>
#include <stdio.h>
#define SIZE 50

typedef struct deque_structure_datatype
{
    int *Q;
    int size;
    int front;
    int rear;
}deque;

void initQueue(deque *dq)
{
    dq->size = SIZE;
    dq->Q = (int*) malloc(dq->size*sizeof(int));
    dq->front = -1;
    dq->rear = -1;
}

void delQueue(deque *dq)
{
    free(dq->Q);
}

void insertRear(deque *dq,int elem)
{
    if(dq->rear>=dq->size)
    {
        printf("The Queue is full Inseriton not possible\n");
        //incrSize(dq);
    }
    else
    {
        if(dq->front==-1)
        {
            dq->front=dq->front+1;
        }
        dq->rear = dq->rear+1;
        dq->Q[dq->rear] = elem;
        return;
    }
}

void insertFront(deque *dq,int elem)
{
    if(dq->front==0)
    {
        //This is the condition  if there is somthin inserted
        printf("Insertion at front not possible\n");
    }
    else
    {
        if(dq->rear == -1)
        {
            dq->rear= dq->rear+1;
        }
        if(dq->front == -1)
        {
            dq->front=dq->front+1;
        }
        else
        {
            dq->front = dq->front-1;
        }
        dq->Q[dq->front] =  elem;
        return;
    }
}

int deleteFront(deque *dq)
{
    if(dq->front == -1)
    {
        printf("QUEUE IS EMPTY THERE IS NO ELEMENT TO DELETE\n");
        return -1;
    }
    
    else
    {
        int elem = dq->Q[dq->front];

        if(dq->front==dq->rear)
        {
            dq->front = -1;
            dq->rear = -1;
        }

        else
            dq->front=dq->front+1;
        return elem;
    }
}

int deleteRear(deque *dq)
{
    if(dq->rear ==-1)
    {
        printf("QUEUE IS EMPTY THERE IS NO ELEMENT TO DELETE\n");
        return -1;
    }
    else
    {
        int elem = dq->Q[dq->rear];

        if(dq->front==dq->rear)
        {
            dq->front = -1;
            dq->rear = -1;
        }
        else
        {
            dq->rear = dq->rear-1;
        }
        return elem;
    }
}

void displayQueue(deque *dq)
{
    int i = dq->front;
    if(dq->front==-1)
    {
        printf("EMPTY");
        return;
    }
    while(i>=0&&i<=dq->rear)
    {
        printf("%d ",dq->Q[i]);
        i++;
    }
}

int main()
{
    deque *myDeque = (deque*) malloc(sizeof(deque));
    int RUN = 1;
    int elem;
    int choice;
    initQueue(myDeque);
    while(RUN)
    {
        printf("\n=======================\n");
        printf("        Menu\n");
        printf("=======================\n");
        printf("1.Enter into the front\n");
        printf("2.Enter into the rear\n");
        printf("3.Remove from the front\n");
        printf("4.Remove from the rear\n");
        printf("5.Display the deque\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");

        scanf("%d%*c",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element you want to enter into the front : ");
                    scanf("%d%*c",&elem);
                    insertFront(myDeque,elem);
                    break;

            case 2: printf("Enter the element you want to enter into the rear: ");
                    scanf("%d%*c",&elem);
                    insertRear(myDeque,elem);
                    break;
                    
            case 3: elem = deleteFront(myDeque);
                    printf("The element remove is :%d\n",elem);
                    break;

            case 4: elem = deleteRear(myDeque);
                    printf("The element remove is :%d\n",elem);
                    break;
            
            case 5: printf("The Queue is: ");
                    displayQueue(myDeque);
                    printf("\n");
                    break;

            case 6: RUN = 0;
                    break;
            default: printf("Enter a valid input\n\n");
        }
    }
    /*
    insert(myDeque,32);
    insert(myDeque,21);
    displayQueue(myDeque);
    */
    delQueue(myDeque);
    printf("\nExiting.....\n");
}
