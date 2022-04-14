#include<stdlib.h>
#include<stdio.h>

typedef struct singlylinkedlist{
    int data;
    struct singlylinkedlist *link;
}sll;

void insert(sll** Header, int e){
    sll* node = (sll*)malloc(sizeof(sll));
    node->data = e;

    sll* ptr = (*Header);
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link = node;
    node->link = NULL;
}

void sortList(sll** Header)
{
    if((*Header)->link==NULL)
    {
        printf("The List is empty]\n");
    }
    else
    {
        sll *temp = (sll*) malloc(sizeof(sll));
        sll *ptr = NULL;

        temp -> link = (*Header)->link;
        (*Header)->link = NULL;

        while(temp->link!=NULL){
            ptr = temp->link;
            temp->link=ptr->link;//increment the temp

            if((*Header)->link==NULL){
                (*Header)->link = ptr;
                ptr->link=NULL;
            }
            else{
                sll* ptr1 = (*Header)->link;
                sll* ptr2 = (*Header);

                while(ptr1!=NULL && ptr1->data<=ptr->data){
                    ptr1=ptr1->link;
                    ptr2 = ptr2->link;
                }

                ptr2->link=ptr;
                ptr->link = ptr1;
            }
        }
        free(temp);
    }
}

void displayList(sll* Header){
    sll* ptr = Header->link;
    while(ptr!=NULL){
        if(ptr->link==NULL)
            printf("%d ",ptr->data);
        else
            printf("%d -> ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}


int main(){
    sll* Header = (sll*)malloc(sizeof(sll));
    int n,elem;

    
    printf("Enter the number of elements in the linked list: ");
    scanf("%d",&n);

    int i=0;
    while(i<n){
        printf("Enter the %d element: ",i+1);
        scanf("%d",&elem);
        insert(&Header,elem);
        i++;
    }

    printf("The list is: ");
    displayList(Header);

    sortList(&Header);

    printf("The sorted list is: ");
    displayList(Header);

    return 0;



}
