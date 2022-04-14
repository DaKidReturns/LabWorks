/********************************
 * Linked List Implementation
 * Done By: Rohit Karunakaran
 * ******************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Linked_List_Node
{
    struct Linked_List_Node *link;
    int data;
}Node;

void initList(Node* Header)
{
    //Header = (Node*) malloc (sizeof(Node));
    Header->link = NULL;
    Header->data = 0;
}


//Insertion Algorithms
void insertStart(Node *Header,int val)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node!=NULL)
    {
        new_node->data = val; 
        new_node->link = NULL;
        Node* ptr = Header->link;
        Header->link = new_node;
        new_node->link=ptr;
    }
    else
    {
        printf("Insertion Not Possible\n");
        exit(1);
    }
    return ;
}

void insertAt(Node *Header,int val,int pos) //Insert at a specified position from the header node
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node!=NULL)
    {
        Node* ptr = Header;
        int index = -1;
        while(index<pos-1 && ptr!=NULL)
        {
            ptr=ptr->link;
            index ++;
        }
        if(ptr !=NULL)
        {
            new_node->link = ptr->link;    
            new_node->data = val;
            ptr->link =new_node;
        }
        else
        {
            printf("Given position is not found \nExiting......\n");
            exit(1);
        }
    }
    else
    {
        printf("Insertion Not Possible");
        exit(1);
    }
    return ;
    
}

void insertEnd(Node *Header,int val)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node!=NULL)
    {
        new_node->data = val;
        new_node->link = NULL;
        Node* ptr=Header;

        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }

        ptr->link = new_node;
    }

    else
    {
        printf("Insertion not possible");
        exit(1);
    }

    return;
}

//Deletion Algorithms
int deletionBegin(Node *Header)
{
    if(Header->link == NULL)
    {
        printf("Deletion not possible. The list is empty");
        exit(0);
        return 0;
    }
    else
    {
        Node* ptr = Header->link;
        Header->link = ptr->link;
        int elem = ptr->data;
        free(ptr);
        return elem;
    }
}

int deletionAt(Node* Header, int pos)
{
    if(Header->link == NULL)
    {
        printf("Deletion not possible. The list is empty");
        exit(0);
        return 0;
    }
    else
    {
        int index = -1;
        Node* ptr = Header;
        while(index<pos-1&&ptr!=NULL)
        {
            ptr=ptr->link; 
            index++;
        }
        if(ptr->link!=NULL)
        {
            int elem = ptr->link->data;
            Node* red = ptr->link;
            ptr->link = ptr->link->link;
            free(red);
            return elem;
        }
        else
        {
            printf("Index Is out of Bounds \n");
            exit(1);
            return 0;
        }
    }
}

int deletionEnd(Node* Header)
{
    if(Header->link == NULL)
    {
        printf("Deletion not possible. The list is empty");
        exit(0);
        return 0;
    }
    else
    {
        Node* ptr=Header->link;
        Node* ptr1=Header;
        while(ptr->link!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->link;
        }
        int elem = ptr->data;
        ptr1->link = NULL;
        free(ptr);
        return elem;
    }
}

void displayList(Node* Header)
{
    Node* ptr = Header->link;
    if(ptr!=NULL)
    {
        printf("The List is : ");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
    else
    {
        printf("The Linked list is empty\n");
    }
}

int menu(Node* Header)
{
    int RUN = 1;
    while(RUN)
    {
        printf("\n");
        printf("=============================\n");
        printf("            MENU             \n");
        printf("=============================\n");
        printf("1.Insert At Begining\n");
        printf("2.Insert At End\n");
        printf("3.Insert At Position\n");

        printf("4.Delete From Begining\n");
        printf("5.Delete From End\n");
        printf("6.Delete From Position\n");
        printf("7.Display the linked List\n");
        printf("8.Exit\n");
        printf("Enter Choice: ");
        int choice;
        int elem;
        int pos;
        scanf("%d%*c",&choice);
        
        switch(choice)
        {
            case 1: printf("Enter the element to be inserted: ");
                    scanf("%d%*c",&elem);
                    insertStart(Header,elem);
                    printf("\n");
                    break;

            case 2: printf("Enter the element to be inserted: ");
                    scanf("%d%*c",&elem);
                    insertEnd(Header,elem);
                    printf("\n");
                    break;

            case 3: printf("Enter the element to be inserted: ");
                    scanf("%d%*c",&elem);
                    printf("Enter the postion to insert %d : ",elem);
                    scanf("%d%*c",&pos);
                    insertAt(Header,elem,pos);
                    printf("\n");
                    break;

            case 4: elem = deletionBegin(Header);
                    printf("The Element removed is %d",elem);
                    printf("\n");
                    break;

            case 5: elem = deletionEnd(Header);
                    printf("The Element removed is %d",elem);
                    printf("\n");
                    break;


            case 6: printf("Enter the postion of the element to be deleted : ");
                    scanf("%d%*c",&pos);
                    elem = deletionAt(Header,pos);
                    printf("The Element removed is %d",elem);
                    printf("\n");
                    break;

            case 7: displayList(Header);
                    break;

            case 8: RUN=0;
                    break;
            default: printf("Enter a valid choice\n");
                    printf("\n");
                     break;

        }

    }
    printf("Exiting........\n");
    return RUN;
}


int main()
{
    Node *Header = (Node*)malloc(sizeof(Node));
    //Node *next = (Node*)malloc(sizeof(Node));

    //Header->link=NULL;
    //insertStart(Header,23);
    //displayList(Header);
    //next->next = NULL;
    //Node *Header;
    initList(Header);
    return menu(Header);

}
