/**********************
 * Binary Search Tree 
 * Done By Rohit Karunakaran
 * ********************/


#include<stdio.h>
#include<stdlib.h>

typedef struct binary_search_tree_node{
    struct binary_search_tree_node* lc;
    struct binary_search_tree_node* rc;
    int value;
}node;

node* search_node(node* root, int value){
    if(root!=NULL){
        if(root->value!=value){
            if(root->value>value){
                return search_node(root->lc,value);
            }
            else{
                return search_node(root->rc,value);
            }
        }
        else{
            return root;
        }
    }
    else{
        return NULL;
    }
}


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

void delete_node(node** root, int value,node* par){
    node* ptr = *root;
    node* parent =par;
    int flag = 1;
    if(ptr!=NULL){
        while(ptr!=NULL&&flag){
            if(ptr->value<value){
                parent = ptr;
                ptr = ptr->rc;
            }
            else if(ptr->value>value){
                parent = ptr;
                ptr = ptr->lc;
            }
            else{
                flag = 0;
            }
        }
        if(flag == 1){
            printf("Item not found\n");
            return;
        }
        if(ptr ->lc ==NULL && ptr->rc==NULL){
            if(parent!=NULL){
                if(parent -> rc ==ptr){
                    parent ->rc =NULL;
                }
                else {
                    parent ->lc =NULL;
                }
            }
            else{
                *root = NULL;
            }
            free(ptr);

        }
        else if(ptr->lc!=NULL && ptr->rc!=NULL){
            node* ptr1=ptr->rc;
            while(ptr1->lc!=NULL) ptr1=ptr1->lc; //Find the successor node
            int item = ptr1->value;
            delete_node(&ptr1,item,ptr);
            ptr->value = item;
        }
        else{
            if(parent!=NULL){
                if(parent ->rc ==ptr){
                   if(ptr->rc!=NULL){
                        parent ->rc = ptr->rc;
                   } 
                   else{
                        parent->rc = ptr->lc;
                   }
                }
                else{
                   if(ptr->rc!=NULL){
                        parent ->lc = ptr->rc;
                   } 
                   else{
                        parent->lc = ptr->lc;
                   }
                
                }
            }
            else{
                //If the parent is null then the node is root and has one child
                if(ptr->rc!=NULL){
                    *root = ptr->rc;
                }
                else{
                    *root = ptr->lc;
                }
            }
            free(ptr);
        }
    }
    else{
        printf("There is no item in the binary tree\n");
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

void leaf_nodes(node* root,int* count){
    if(root!=NULL){
        leaf_nodes(root->lc,count);
        if(root->lc==NULL&&root->rc==NULL)(*count)++;
        leaf_nodes(root->rc,count);

    }
    else{
        return;
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
        printf("6.Number of leaf nodes\n");
        printf("7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be inserted : ");
                    scanf("%d",&elem);
                    insert_node(&root,elem);
                    break;
            case 2: if(root!=NULL){
                        printf("Inorder Traversal: ");
                        inorder_traversal(root);
                    }
                    else
                        printf("The tree is Empty!!!!\n");
                    break;
            case 3: if(root!=NULL){
                        printf("Preorder Traversal: ");
                        preorder_traversal(root);
                    }
                    else
                        printf("The tree is Empty!!!!\n");
                    break;
            case 4: if(root!=NULL){
                        printf("Postorder Traversal: ");
                        postorder_traversal(root);
                    }
                    else
                        printf("The tree is Empty!!!!\n");
                    break;
            case 5: printf("Enter the value to be deleted: ");
                    scanf("%d",&elem);
                    delete_node(&root,elem,NULL);
                    break;
            case 6: if(root!=NULL){
                        elem = 0;
                        leaf_nodes(root,&elem);
                        printf("Number of leafnodes = %d\n",elem);
                    }
                    else{
                        printf("The tree is empty there is no leaf nodes\n");
                    }
                    break;
            case 7: RUN=0;
                    break;
            default:printf("Wrong value entered try again\n\n");
                    break;
        }
        
    }

    return RUN;
}

int main(){
    node* root = NULL;
    return menu(root);
}
