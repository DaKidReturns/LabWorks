#include<stdio.h>
#include<stdlib.h>

#define SIZE 50


int A[SIZE];
int top = -1;

int  isEmpty(){
    if(top<0){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top<SIZE)
        return 0;
    else
        return 1;
}

int peek(int index){
    int i = top-index +1;
    if(i<0){
        printf("Underflow there is no element in the array \n");
        return 0;
    }
    else{
        return A[i];
    }
}

int stackTop(){
    if(isEmpty()){
        printf("The Stack is empty no element in stack\n");
        return 0;
    }
    else{
        return A[top];
    }
}

void push(int a){
    if(isFull()){
        printf("Stack is Full: Overflow");
    }
    else{
        top = top+1;
        A[top] = a;
    }
}

int pop(){
    int a;
    if(isEmpty()){
        printf("Underflow Stack is empty no element to pop");
    }
    else{
        a =  A[top];
        top--;
    }
    return a; //garbage or error is returned if underflow occurs
}

void display()
{
    if(isEmpty())
    {
        printf("The stack is empty");
    }
    else
    {
        int i = top;
        printf("The stack is : ");
        while(i>=0)
        {
            if(i==top)
                printf("%d <- Top\n",A[i]);
            else
                printf("               %d\n",A[i]);
            i--;
        }
    }
}

void main(){
    int c;
    int i;
    int e;
    int RUN = 1;
    while(RUN){
        printf("\n");
        printf("=========================\n");
        printf("Menu\n");
        printf("1.Push\n2.Pop\n3.Check if empty\n4.Check if full\n5.Element at top\n6.Peek\n7.Display\n8.Exit\n");
        printf("=========================\n");
        printf("\nEnter Choice ---> ");
        scanf("%d%*c",&c);
        switch(c){
            case 1: printf("\nEnter an element to push into the array --> ");
                    scanf("%d%*c",&e);
                    push(e);
                    break;
            case 2: e =pop() ;
                    printf("\nElement poped is %d\n",e);
                    break;
            case 3: if(isEmpty()){
                        printf("Stack is empty\n");
                    }
                    else{
                        printf("Stack is not empty\n");
                    }
                    break;
            case 4: if(isFull()){
                        printf("Stack is full\n");
                    }
                    else{
                        printf("Stack is not full\n");
                    }
                    break;
            case 5: e = stackTop();
                    printf("The Element at top is %d\n", e);
                    break;
            case 6: printf("Enter the value of the index--> ");
                    scanf("%d%*c",&i);
                    e = peek(i);
                    printf("\nThe %dth element in the stack is %d\n",i,e);
                    break;
            case 7: display();
                    break;
            case 8: RUN = 0;
                    printf("\nExiting!!!!!!!!!!\n");
                    break;
            default: printf("Enter a proper value!!!!!!!!!!!!!!! \n");
        }
    }
}
