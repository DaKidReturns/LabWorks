#include<stdlib.h>
#include<stdio.h>


struct node
{
    int * a;
    struct node * next;
};


void selection_sort(int * a,int n)
{
    int i,j,temp,index;

	for(i=0;i<n-1;i++)
	{   index=i;

	    for(j=i+1;j<n;j++)
	    {

	        if (a[j]<a[index])
	            {
	                index=j;

	            }
	    }

	    temp=a[i];
	    a[i]=a[index];
	    a[index]=temp;
	}

}



void sort(struct node * head)
{
    struct node * p1=head;
    struct node * p2;
    struct node * p3;
    struct node * p4;
    struct node * p5;
    int small;
    while(p1->next!=NULL)
    {
        small=10000;
        p2=p1->next;
        p4=p1;
        while(p2!=NULL)
        {

            if(p2->a[0]<small)
            {
                p5=p4;
                p3=p2;
                small=p2->a[0];
            }
            p4=p2;
            p2=p2->next;

        }

        p5->next=p3->next;
        p3->next=p1->next;
        p1->next=p3;

        p1=p1->next;

    }

}


void main()
{
    int n,m;
    printf("Enter the value of n");
    scanf("%d",&n);
    printf("Enter the value of m");
    scanf("%d",&m);

    struct node * head=(struct node * )malloc(sizeof(struct node));

    struct node * ptr1=head;


    int i=0;
    while(i<n)
    {

         if(i%m==0)
         {
             struct node * ptr=(struct node * )malloc(sizeof(struct node));
             ptr->next=NULL;
             ptr->a=(int *)malloc(m*sizeof(int));
             int j=0;
             while(j<m && i<n)
             {
                 scanf("%d",&(ptr->a[j]));
                 i++;
                 j++;
             }
             while(j<m)
             {
                 ptr->a[j]=-1271523;
                 j++;
             }

              ptr1->next=ptr;
              ptr1=ptr;
         }

    }


    struct node * ptr2=head->next;

    int g=0;
    int j=0;
     while(ptr2!=NULL)
     {
          j=0;
          while(g<n && j<m)
          {
              printf("%d ",ptr2->a[j]);
              g++;
              j++;
          }

         ptr2=ptr2->next;
     }


    g=0;
    ptr2=head->next;

    while(ptr2!=NULL)
     {
          j=0;
          while(g<n && j<m)
          {

              g++;
              j++;
          }

          selection_sort(ptr2->a,j);
         ptr2=ptr2->next;
     }

     struct node * p2=head;
        sort(p2);
    printf("\n");

    struct node *ptr3=head->next;
     g=0;
     printf("The Sorted is : ");
    while(ptr3!=NULL)
     {
          j=0;
          while(j<m)
          {
              if(ptr3->a[j]!=-1271523)
                printf("%d ",ptr3->a[j]);
              g++;
              j++;
          }
          printf("->");

         ptr3=ptr3->next;
     }


}
