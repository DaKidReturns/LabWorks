/*************************************
 * Hashing with linear probing as the
 * collision resolution method
 *
 * Done By: Rohit Karunakaran
 ************************************/


#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void insert(int ***hash_table, int e,int i){
    if(i<=SIZE){
        int pos = (e%SIZE+i)%SIZE;
        int **ht = *hash_table;

        if(ht[pos]==NULL){
            int* node = (int*) malloc(sizeof(int));
            *node = e;
            ht[pos] = node;
        }
        else{
            insert(hash_table,e,i+1);
        }
    }
    else{
        printf("INSERTION NOT POSSIBLE!!!!!!\nThe Hash Table is full\n");
        return;
    }

}

void show_the_hash_table(int **ht){
    int i;
    for(i=0;i<SIZE;i++){
        int *ptr = ht[i];
        if(ptr!=NULL){
            printf("(%d) - %d\n",i,*ptr);
        }
    }
}

int main(){
    int **hash_table=(int**)calloc(sizeof(int*),SIZE);
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
                insert(&hash_table, elem,0);
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

    for(int i = 0; i<SIZE;i++){
        free(*(hash_table+i));
    }
    free(hash_table);
    
    return 0;
}

