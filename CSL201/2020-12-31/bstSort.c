/**********************
 *  Sorting using binary search tree
 * Done By Rohit Karunakaran
 * ********************/


#include<stdio.h>
#include<stdlib.h>

typedef struct binary_search_tree_node{
    struct binary_search_tree_node* lc;
    struct binary_search_tree_node* rc;
    int value;
}node;

void insert_node(node** root,int value){
    int flag=1;
    node* ptr=*root;
    if(ptr!=NULL){
        while(ptr!=NULL&&flag){
            if(ptr->value<value){
                if(ptr->rc==NULL){
                    ptr->rc = (node*)malloc(sizeof(node));
                    ptr->rc->lc = ptr->rc->rc =NULL;
                    ptr->rc->value = value;
                    flag=0;
                }
                else{
                    ptr= ptr->rc;
                }
            }
            else{
                if(ptr->lc==NULL){
                    ptr->lc = (node*)malloc(sizeof(node));
                    ptr->lc->lc = ptr->lc->rc =NULL;
                    ptr->lc->value = value;
                    flag=0;
                }
                else{
                    ptr = ptr->lc;
                }
            }
        }
    }
    else{
    //Root is empty
        *root = (node*)malloc(sizeof(node));
        (*root) ->lc = (*root)->rc = NULL;
        (*root)->value = value;
    }
}

int index =0;

void bstSort(node* root,int arr[]){
    if(root!=NULL){
        bstSort(root->lc,arr);
        arr[index] = root->value; index++;
        bstSort(root->rc,arr);

    }
    else{
        return;
    }
    
}


int main(){
    node* root = NULL;
    int n;
    printf("Enter the number of elements to be sorted :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the array : ");

    for(int i=0;i<n;i++){
        int elem;
        scanf("%d",&elem);
        insert_node(&root,elem);
    }
    
    bstSort(root,arr);
    printf("The Sorted array of elemets are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
