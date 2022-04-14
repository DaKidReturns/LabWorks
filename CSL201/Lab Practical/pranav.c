#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
struct node
{
	int data[20];
    int size;
	struct node *link;
};

struct node *header=NULL;

void insert(struct node *header,int m)
{
	bool flag ;
	flag = 'T';
	char ch;
	int i,element;
	struct node *ptr=header->link;
	if(ptr==NULL)
	{
		ptr=(struct node *)malloc(sizeof(struct node));	
		for(i=0;i<m;i++)
		{
			scanf("%d",&ptr->data[i]);
		}
		ptr->link=NULL;
	}
	else
	{
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		if(ptr->data[m-1]!=NULL)
		{
			i=0;
			ptr->link = (struct node *)malloc(sizeof(struct node));
			while(flag == 'T')
			{
				
				
				printf("DO YOU WANT TO ENTER A DATA ? Y/N");
				scanf("%c",&ch);
				if(ch=='y' || ch=='Y')
				{
					if(i<m)
					{
				
						printf("\n ENTER THE DATA TO BE STORED : \n");
						scanf("%d",&element);
						ptr->link->data[i]=element;
						i++;		
						
					}
					else
					{
						printf("\n node is full!!!");
						break;
					}
				}
				else
				{
					flag= 'F';
				}
			}
		}
		else
		{
			printf("INSERTION NOT POSSIBLE");
			exit(0);
		}
	}
}

void sort_node(struct node *header,int m)
{
	int min;
	int temp;
	struct node *ptr=header->link;
	while(ptr!=NULL)
	{
		for(int i=0;i<m-1;i++)
     		{
      			min=i;
      			for(int j=i+1;j<m;j++)
      			{
         			
         			if(ptr->data[j]<ptr->data[min])
           				min=j;
      			}
     
     			if(min!=i)
     			{
      				temp=ptr->data[min];
      				ptr->data[min]=ptr->data[i];
      				ptr->data[i]=temp;
     			}
    		}
		ptr=ptr->link;
	}
}

void sort_list(struct node *header)
{
	int min;
	struct node *ptr=header->link;
	struct node *temp;




        while (ptr->link != NULL) 
        { 
            if (ptr->data[0] > ptr->link->data[0]) 
            { 
		struct node* ptr1=ptr->link; 
 		temp=ptr1;
		ptr1=ptr;
		ptr=temp;
		ptr1->link=ptr;
            } 
            ptr = ptr->link; 
        } 
}

void display(struct node *header,int m)
{
	int i;
	struct node *ptr=header->link;
	while(ptr!=NULL)
	{
		for(i=0;i<m-1;i++)
		{
			printf("\n %d -->",ptr->data[i]);
			
		}
		printf("\n %d ",ptr->data[i]);
		ptr=ptr->link;
		printf("\n\n");
	}
}
		


void main()
{
	struct node *header=NULL;
	int i,n,m;
	printf("ENTER THE NUMBER OF NODES : ");
	scanf("%d",&n);
	printf("ENTER THE NUMBER OF ELEMENTS IN EACH NODE : ");
	scanf("%d",&m);
	for(i=0;i<n;i++)
		insert(header,m);
	sort_node(header,m);
	sort_list(header);
	display(header,m);

}
