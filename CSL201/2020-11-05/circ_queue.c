#include<stdio.h>
#include<stdlib.h>

//Create a struct for our queue
typedef struct CQueue{
    int* Q;
    int front;
    int rear;
    int size;
} CQueue;


CQueue* initializeQueue(int size){
    //Create a pointer to stack 
    CQueue *a = (CQueue*) malloc (sizeof(CQueue));
    if(a == NULL){
        printf("An Overflow error has ocurred while creating the CircularQueue\n");
        exit(1);
    }

    //create the array that will contain our queue
    a->Q = (int*)malloc(size*sizeof(int));
    if(a->Q == NULL){
        printf("An Overflow error has ocurred while creating the Circular Queue array\n");
        exit(1);
    }

    a->front = -1;
    a->rear = -1;
    a->size = size;
    return a;
}

void deleteQueue(CQueue *a){
    free(a->Q);
    free(a);
}

void enQueue(CQueue *a,int item){
    if((a->rear+1)%(a->size) == a->front){
            printf("An Overflow Error has occured while reallocating the array\n");
            return;
    }
    else{
        if(a->front == -1){
            a->front = 0;
        }

        a->rear = (a->rear +1)%a->size;
        a->Q[a->rear] = item;
    }
}

int deQueue(CQueue *a){
   if(a->front == -1){
        printf("You have made a grave mistake, the CQueue was empty\n\n");
        //deleteQueue(a);
        //exit(1);
        return -1;

   } 
   else{
        int item = a->Q[a->front];
        if(a->front == a->rear){
            a->front = -1;
            a->rear = -1;
        }
        else{
            a->front = (a->front+1)%(a->size);
        }
        return item;
   }
}

void displayQueue(CQueue *a){
    if(a->front == -1){
        printf("Queue is empty\n");
        return;
    }
    else {
        if(a->front <= a->rear){
           for(int i=a->front;i<=a->rear;i++){
                printf("%d ",a->Q[i]);
           }
        }
        else{
            for(int i=a->front;i<a->size;i++){
                printf("%d ",a->Q[i]);
            }
            for(int i=0;i<=a->rear;i++){
                printf("%d ",a->Q[i]);
            }
        }
        printf("\n\nFront: %d Rear: %d\n",a->front,a->rear);
        printf("\n");
    }
}


int menu(CQueue *a){
        int RUN=1;
        int c;      //For the corresponding choice
        int item;   //To receive the item to push or pop from the array
        while (RUN){
            printf("\n");
            printf("-----------------------------------------------\n");
            printf("Circular Queue Implementation using structure\n");
            printf("-----------------------------------------------\n");
            printf("1.Insert\n");
            printf("2.Delete\n");
            printf("3.Print the queue\n");
            printf("4.Exit\n");
            printf("Enter the required choice --> ");
            scanf("%d%*c",&c);

            switch(c){
                case 1:printf("Enter the element to be inserted into the queue --> "); 
                       scanf("%d%*c",&item);
                       enQueue(a,item);
                       break;
                       
                case 2:item = deQueue(a); 
                       printf("Item removed is  is --> %d\n",item);
                       break;

                case 3:printf("The Circular Queue is --> ");
                       displayQueue(a);
                       break;

                case 4: RUN=0;
                        break;

                default:printf("Entered command is unknown");
            }

        }
        deleteQueue(a);

        printf("Finished excecuting the code ALL DONE\n");
        return RUN;
}

int main(){
    CQueue *a;
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    a = initializeQueue(n);
    return menu(a);
}
