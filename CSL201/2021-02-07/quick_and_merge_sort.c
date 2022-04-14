#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_SIZE 100

typedef struct student_structure{
    char name[101];
    float height;
    float weight;
}student;

enum prop{NAME,HEIGHT,WEIGHT};
char prop_name[][10]={"Name","Height","Weight"};

/********************************
 * Quick Sort 
 * *****************************/
int partition(student *list, int first, int pivot, enum prop a){
    int i,j;

    i = first;
    j = first-1;
    while(i<pivot){
        int flag = 0;

        switch(a){
            case NAME: 
                if(strcmp(list[i].name,list[pivot].name)<=0) flag = 1;
                break;
            case HEIGHT:
                if(list[i].height<=list[pivot].height) flag = 1;
                break;
            case WEIGHT:
                if(list[i].weight<=list[pivot].weight) flag = 1;
                break;
        }
        if(flag){
            j++;
            student temp = list[i];
            list[i] = list[j]; 
            list[j] = temp;
        }
        i++;
    }
    j++;
    if(pivot != j){
        student temp = list[pivot];
        list[pivot] = list[j]; 
        list[j] = temp;
    }
    return j;
}

void quick_sort(student *list,int first,int last,enum prop a){
    if(first<last){
        int q = partition(list, first,last,a);
        quick_sort(list, first, q-1,a);
        quick_sort(list,q+1,last,a);
    }
}

/********************************
 * Merge Sort 
 * ******************************/
void merge(student *list,int first,int mid,int last,enum prop a){
    int n = last-first+1;
    student *temp =(student*)malloc(n*sizeof(student)) ;

    int i,j,flag,k=0;
    for(i=first,j=mid+1;i<=mid&&j<=last;)
    {
        flag = 0;
        switch(a){
            case NAME:
                if(strcmp(list[i].name,list[j].name)<=0){
                    flag = 1;
                }
                break;
            case HEIGHT:
                if(list[i].height<=list[j].height){
                    flag =1;
                }
                break;
            case WEIGHT:
                if(list[i].weight<=list[j].weight){
                    flag =1;
                }
                break;
        }
        if(flag){ //if the flag is true then add i, else add j;
            strcpy(temp[k].name,list[i].name);
            temp[k].height= list[i].height;
            temp[k].weight = list[i].weight;
            i++;
        }
        else{
            strcpy(temp[k].name,list[j].name);
            temp[k].height= list[j].height;
            temp[k].weight = list[j].weight;
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k] = list[i];
        i++;k++;
    }
    while(j<=last){
        temp[k] = list[i];
        j++;k++;
    }
    k=0;
    for(i = first;i<=last;i++){
        strcpy(list[i].name,temp[k].name);
        list[i].height= temp[k].height;
        list[i].weight = temp[k].weight;
        k++;
    }
}

void merge_sort(student *list, int first, int last, enum prop a)
{
    if(first<last){
        int mid = (first+last)/2;
        merge_sort(list,first,mid,a);
        merge_sort(list,mid+1,last,a);
        merge(list,first,mid,last,a);
    }
}

void list_copy (student* l1, student* l2,int n){
    for(int i=0;i<n;i++){
        strcpy(l1[i].name,l2[i].name);
        l1[i].height = l2[i].height;
        l1[i].weight = l2[i].weight;
    }
}

int main(){

    student *student_list = (student*) malloc(MAX_SIZE*sizeof(student));
    student *temp_list = (student*) malloc(MAX_SIZE*sizeof(student));
//    FILE *file = fopen("./output.txt","w");

    char first_name[50];
    char last_name[50];
    int n = 0;
    int i;
    enum prop a = HEIGHT;

    clock_t t;
    double time_taken;

    if(freopen("./student_data.txt","r",stdin)){
        FILE *quickSortOp = fopen("./quicksortop.txt","w");
        FILE *mergeSortOp = fopen("./mergesortop.txt","w");
        while(scanf("%s %s %f %f\n", first_name,last_name,&(student_list[n].height),
                    &(student_list[n].weight))==4) {
            //conactinate the first and the last names
            strcat(student_list[n].name, first_name);
            strcat(student_list[n].name, " ");
            strcat(student_list[n].name, last_name);
            n++;
        }
        fprintf(quickSortOp,"QUICK SORT\n");
        fprintf(quickSortOp,"============\n");

//        for(int a=NAME;a<=WEIGHT;a++ ){ //For iterating through all the 
            list_copy(temp_list,student_list,n);
            
            t = clock();
            quick_sort(temp_list,0,n-1,a);
            t = clock()-t;

            i=0;
            fprintf(quickSortOp,"Sorted according to order of the %s\n\n",prop_name[a]);
            while(i<n){
                fprintf(quickSortOp,"%s %.2f %.2f\n",temp_list[i].name,temp_list[i].height,temp_list[i].weight);
                i++;
            }
            
            time_taken = ((double)t)/(CLOCKS_PER_SEC);
            fprintf(quickSortOp,"Time taken = %lf seconds",time_taken);
            fprintf(quickSortOp,"\n\n");
 //       }

        fprintf(mergeSortOp,"MERGE SORT\n");
        fprintf(mergeSortOp,"============\n");

 //       for(int a = NAME; a<=WEIGHT;a++){
            list_copy(temp_list,student_list,n);

            t = clock();
            merge_sort(temp_list,0,n-1,a);
            t = clock()-t;

            i=0;
            fprintf(mergeSortOp,"Sorted according to order of the %s\n\n",prop_name[a]);
            while(i<n){
                fprintf(mergeSortOp,"%s %.2f %.2f\n",temp_list[i].name,temp_list[i].height,temp_list[i].weight);
                i++;
            }

            time_taken = ((double)t)/(CLOCKS_PER_SEC);
            fprintf(mergeSortOp,"Time taken = %lf seconds",time_taken);
            fprintf(mergeSortOp,"\n\n");
//        }
    }

    return 0;
}
