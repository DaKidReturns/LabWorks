/*******************************
 * Binary tree 
 * Done By: Rohit Karunakaran
 * *****************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree_node{
    struct binary_tree_node* lc;
    struct binary_tree_node* rc;
    int value;
}node;

/*
node* init_tree(){
    root_node = (node*) malloc(sizeof(node));
} 
*/

node* search_node(node* root, int value){
    node* ptr=NULL;
    if(root->value != value){
        if(root->lc==NULL && root->rc==NULL){
            return NULL;
        }
        else{
            if(root->lc!=NULL){
                ptr = search_node(root->lc, value);  
                if(ptr!=NULL){
                    return ptr;
                }
            }
            if(root->rc!=NULL){
                ptr = search_node(root->rc,value) ;  
                if(ptr !=NULL){
                    return ptr;
                }
            }
            return ptr;
        }
    }
    else{
        return root;
    }
}

node* search_parent(node* root, int value){
    node* ptr = NULL;
    if(root!=NULL){
        if(root->lc !=NULL && root->rc!=NULL){
            if(root->lc ->value == value||root->rc->value==value){
                return root;
            }else{
                ptr = search_parent(root->lc, value);
                if(ptr == NULL){
                    ptr = search_parent(root->rc, value);
                }
                return ptr;
            }
        }
        else if(root -> lc ==NULL && root ->rc ==NULL){
            return NULL;
        }
        else{
            if(root->lc == NULL){
                if(root->rc->value==value){
                    return root;
                }
                else{
                    ptr = search_parent(root->rc,value);
                    return ptr;
                }
            }
            else{
                if(root->lc->value==value){
                    return root;
                }
                else{
                    ptr = search_parent(root->lc,value);
                    return ptr;
                }
                
            }
        }
    }
    else{
        return NULL;
    }
}

void insert_node(node* root,int value){
    node* ptr = search_node(root,value);
    char c;
    if(ptr!=NULL){
        fflush(stdin);
        printf("Insert Node as Left child or as a right child: ");
        scanf("\n%c",&c);
        if(c == 'l'){
            if(ptr->lc == NULL){
                node* tmp = (node*)malloc(sizeof(node));
                printf("Enter the value to be inserted: ");
                scanf("%d",&(tmp->value));
                tmp->rc = NULL;
                tmp->lc = NULL;
                ptr->lc = tmp;
            }
            else{
                printf("Insertion at the left node of %d is not possible\n",ptr->value);
            }
        }
        
        else if(c =='r'){
            if(ptr->rc == NULL){
                node* tmp = (node*)malloc(sizeof(node));
                printf("Enter the value to be inserted: ");
                scanf("%d",&(tmp->value));
                tmp->rc = NULL;
                tmp->lc = NULL;
                ptr->rc = tmp;
            }
            else{
                printf("Insertion at the right node of %d is not possible\n",ptr->value);
            }
        }
        else{
            printf("Proper option was not chosen\n");
        }
    }
    else{
        printf("Value %d not found!!!!\nInsertion not possible\n",value);
    }
}

void inorder_traversal(node* root){
    if(root!=NULL){
        inorder_traversal(root->lc);
        printf("%d ",root->value);
        inorder_traversal(root->rc);

    }
    else{
        return;
    }
    
}

void postorder_traversal(node* root){
    if(root!=NULL){
        postorder_traversal(root->lc);
        postorder_traversal(root->rc);
        printf("%d ",root->value);
    }
    else{
        return;
    }
}

void preorder_traversal(node* root){
    if(root!=NULL){
        printf("%d ",root->value);
        preorder_traversal(root->lc);
        preorder_traversal(root->rc);
    }
    else{
        return;
    }
}

void delete_node(node** root, int value)
{
    node* parent = search_parent(*root, value);
    if(parent == NULL){
        if((*root)->value == value&&(*root)->rc==NULL&&(*root)->lc==NULL){
            free(*root);
            *root = NULL;

        }
        else if((*root)->value == value){
            printf("Deletion not possible\n");
        }
        else{
            printf("The value %d not found in the tree\n\n",value);
        }
    }
    else{
        if(parent->rc !=NULL&&parent->rc->value==value){
            if(parent->rc->rc==NULL && parent->rc->lc==NULL){
                free(parent->rc);  
                parent->rc =NULL;
            }
            else{
                printf("Deletion not possible\n");
            }
        }
        else{
            if(parent->lc->lc==NULL && parent->lc->rc==NULL){
                free(parent->lc);  
                parent->lc =NULL;
            }
            else{
                printf("Deletion not possible\n");
            }
        }
    }
}

int menu(node* root){
    printf("Binary Tree implementation\n");
    int RUN=1;
    int choice;
    int elem;
    while(RUN){
        printf("\nMenu\n");
        printf("1.Insert\n");
        printf("2.Inorder traversal\n");
        printf("3.Preorder traversal\n");
        printf("4.Postorder traversal\n");
        printf("5.Delete Node\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: if(root==NULL){
                        root = (node*)malloc(sizeof(node));
                        printf("Enter the value to be inserted: ");
                        scanf("%d",&elem);
                        root->value = elem;root->lc = NULL;root->rc = NULL;
                    }
                    else{
                        printf("Enter the value to be searched for : ");
                        scanf("%d",&elem);
                        insert_node(root,elem);
                    }
                    break;
            case 2: if(root!=NULL){
                        printf("\nInorder Traversal : ");
                        inorder_traversal(root);
                    }
                    else
                        printf("The tree is Empty!!!!\n");
                    break;
            case 3: if(root!=NULL){
                        printf("\nProerder Traversal : ");
                        preorder_traversal(root);
                    }
                    else
                        printf("The tree is Empty!!!!\n");
                    break;
            case 4: if(root!=NULL){
                        printf("\nPostorder Traversal : ");
                        postorder_traversal(root);
                    }
                    else
                        printf("The tree is Empty!!!!\n");
                    break;
            case 5: printf("Enter the value to be deleted: ");
                    scanf("%d",&elem);
                    delete_node(&root,elem);
                    break;
            case 6: RUN=0;
                    break;
        }
        
    }

    return RUN;
}

int main(){
    node* root = NULL;
    return menu(root);
}
