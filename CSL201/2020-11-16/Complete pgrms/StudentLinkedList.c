/********************************
 * Linked List Implementation
 * Done By: Rohit Karunakaran
 * ******************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Linked_List_Node
{
    struct Linked_List_Node *link;
    int rollNo;
    double mark;
    char name[40]; 

}Student;

void initList(Student* Header)
{
    //Header = (Student*) malloc (sizeof(Student));
    Header->link = NULL;
}

void clearList(Student **List)
{
    Student* ptr = *List;
    Student *eat = ptr;
    ptr = ptr->link;
    if(ptr!=NULL)
    {
        free(eat);
        ptr = ptr->link;
    }
}

void getStudentData(Student* node)
{
    printf("\nEnter the name of the student: ");
    scanf("%[^\n]%*c",node->name);
    printf("Enter the roll no: ");
    scanf("%d",&node->rollNo);
    printf("Enter the marks: ");
    scanf("%lf",&node->mark);
    printf("\n");
}

//Searching Algorithm
Student* searchFor(Student* Header, int rollNo)
{
    Student* ptr = Header;
    if(Header->link == NULL){
        printf("The List is Empty\n");
        return NULL;
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->rollNo == rollNo)
            {
                return ptr;
            }
            ptr = ptr->link;
        }
        return NULL;
    }
}

//Sorting algorithm
void sortStudentList(Student** Header)
{
    if((*Header)->link==NULL)
    {
        printf("The List is empty]\n");
    }
    else
    {
        Student *temp =(Student*) malloc(sizeof(Student));
        Student *ptr=NULL;
        temp->link=(*Header)->link;
        (*Header)->link = NULL;

        while(temp->link!=NULL)
        {
            ptr = temp->link;
            temp->link = ptr->link;
            if((*Header)->link ==NULL)
            {
                (*Header)->link = ptr;
                ptr->link = NULL;
            }
            else
            {
                Student *ptr2=(*Header)->link;
                Student *ptr1 =(*Header);
                while(ptr2!=NULL && ptr2->rollNo<=ptr->rollNo) 
                {
                    ptr2=ptr2->link;
                    ptr1=ptr1->link;
                }
                ptr1->link=ptr;
                ptr->link = ptr2;

            }
            
        }
        
    }
}

void dispStudent(Student* ptr)
{
    printf("\nName: %s",ptr->name);
    printf("\nRoll No: %d",ptr->rollNo);
    printf("\nMarks: %lf",ptr->mark);
}

//Insertion Algorithms
void insertStart(Student *Header)
{
    Student *new_node = (Student*) malloc(sizeof(Student));

    if(new_node!=NULL)
    {
        getStudentData(new_node);
        new_node->link = NULL;
        Student* ptr = Header->link;
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

void insertAt(Student *Header,int rollNo) //Insert at a specified position from the header node
{
    Student *new_node = (Student*) malloc(sizeof(Student));

    if(new_node!=NULL)
    {
        Student* ptr = searchFor(Header,rollNo);
        if(ptr!=NULL)
        {
            new_node->link = ptr->link;    
            getStudentData(new_node);
            ptr->link =new_node;
        }
        else
        {
            printf("Given roll No is not found......\n");
            //exit(1);
        }
    }
    else
    {
        printf("Insertion Not Possible\n");
        exit(1);
    }
}

void insertEnd(Student *Header)
{
    Student *new_node = (Student*) malloc(sizeof(Student));

    if(new_node!=NULL)
    {
        getStudentData(new_node);
        new_node->link = NULL;
        Student* ptr=Header;

        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new_node;
    }

    else
    {
        printf("Insertion not possible\n");
    }

    return;
}

//Deletion Algorithms
void deletionBegin(Student *Header)
{
    if(Header->link == NULL)
    {
        printf("Deletion not possible. The list is empty\n");
    }
    else
    {
        Student* ptr = Header->link;
        Header->link = ptr->link;
        dispStudent(ptr);
        free(ptr);
    }
}

void deletionAt(Student* Header, int rollNo)
{
    if(Header->link == NULL)
    {
        printf("Deletion not possible. The list is empty\n");
    }
    else
    {
        Student* ptr = Header;
        while(ptr->link!=NULL)
        {
            if(ptr->link->rollNo==rollNo)
                break;
            ptr=ptr->link; 
        }
        if(ptr->link!=NULL)
        {
            Student* red = ptr->link;
            ptr->link = ptr->link->link;
            printf("The Student to be deleted is :\n");
            dispStudent(red);
            free(red);
        }
        else
        {
            printf("The Given RollNo is not found \n");
        }
    }
}

void deletionEnd(Student* Header)
{
    if(Header->link == NULL)
    {
        printf("Deletion not possible. The list is empty");
    }
    else
    {
        Student* ptr=Header->link;
        Student* ptr1=Header;
        while(ptr->link!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->link;
        }
        printf("The Node deleted is : \n");
        dispStudent(ptr);
        ptr1->link = NULL;
        free(ptr);
    }
}

void displayList(Student* Header)
{
    Student* ptr = Header->link;
    if(ptr!=NULL)
    {
        printf("The List is : ");
        while(ptr!=NULL)
        {
            dispStudent(ptr);
            ptr=ptr->link;
        }
        printf("\n");
    }
    else
    {
        printf("The Linked list is empty\n");
    }
}

int menu(Student* Header)
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
        printf("8.Search for a Student by Roll No\n");
        printf("9.Sort By Roll No\n");
        printf("10.Exit\n");
        printf("Enter Choice: ");
        int choice;
        int pos;
        scanf("%d%*c",&choice);
        
        switch(choice)
        {
            case 1: 
                    insertStart(Header);
                    printf("\n");
                    break;

            case 2: 
                    insertEnd(Header);
                    printf("\n");
                    break;

            case 3: printf("Enter the roll no after which the new Student is to be inserted : ");
                    scanf("%d%*c",&pos);
                    insertAt(Header,pos);
                    printf("\n");
                    break;

            case 4: deletionBegin(Header);
                    break;

            case 5: deletionEnd(Header);
                    break;


            case 6: printf("Enter the roll no of the student to be deleted : ");
                    scanf("%d%*c",&pos);
                    deletionAt(Header,pos);
                    printf("\n");
                    break;

            case 7: displayList(Header);
                    break;

            case 8: printf("Enter the roll Number to be searched for : ");
                    scanf("%d%*c",&pos);
                    Student* res = searchFor(Header,pos);
                    if(res == NULL)
                    { 
                        printf("The given roll number is invalid !!!\n");
                    }
                    else
                    {
                        dispStudent(res);
                    }
                    break;

            case 9: sortStudentList(&Header);
                    break;
            case 10: RUN=0;
                    break;
            default: printf("Enter a valid choice\n");
                    printf("\n");
                     break;

        }

    }
    printf("Exiting........\n");
    clearList(&Header);
    return RUN;
}


int main()
{
    Student *Header = (Student*)malloc(sizeof(Student));
    initList(Header);
    return menu(Header);

}
