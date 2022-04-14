/***********************************
 * Implementiong of Hashing with 
 * chaining 
 * Done By: Rohit Karunakaran
 * ********************************/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct hash_node{
    int data;
    struct hash_node *next;
} node;

void insert(node **hash_table, int e){
    int pos = e%SIZE;
    //node **hash_table = *ht;

    node *new_node = (node*)malloc(sizeof(node));
    if(new_node !=NULL){
        new_node->data = e;
        new_node->next=NULL;
        if(hash_table[pos]==NULL){
            hash_table[pos] = new_node;
        }
        else{
            node *ptr = hash_table[pos];
            while(ptr->next!=NULL)ptr = ptr->next;
            ptr->next=new_node;
        }
    }
}

void show_the_hash_table(node **ht){
    int i;
    for(i=0;i<SIZE;i++){
        node *ptr = ht[i];
        if(ptr!=NULL){
            while(ptr->next!=NULL){
                printf("%d -> ",ptr->data);
                ptr = ptr->next;
            }
            printf("%d\n",ptr->data);
        }
    }
}

int main(){
    node **hash_table=(node**)calloc(sizeof(node),SIZE);
    int RUN=1;
    int elem;
    int c;

    while(RUN){
        printf("\nMENU\n");
        printf("1.Insert to hash table\n");
        printf("2.Display the hash table\n");
        printf("3.Exit\n");
        printf("Enter yout choice: ");

        scanf("%d",&c);

        switch(c){

            case 1: 
                printf("Enter the element you want to enter : "); 
                scanf("%d",&elem);
                insert(hash_table, elem);
                break;
            case 2:
                printf("The hash table is : \n");
                show_the_hash_table(hash_table);
                break;
            case 3: 
                RUN=0;
                break;
        }
        
    }
    return 0;
}

