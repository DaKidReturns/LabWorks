#include<stdio.h>
#include<stdlib.h>

void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void create_heap(int *arr,  int n){
   int i = 0; 
   int k,j;
   while(i<n){
        j = i;
        while(j>0){
            k = j%2==0?j/2-1:j/2;
            if(arr[j]>arr[k]){
                swap(arr,j,k); 
                j = k;
            }
            else{
                j=0;
            }
        }
    i++;
   }
   //printf("Entered heap sort");
}


void heapify(int *arr, int i){
//i is the upper bound 
    if(i == 0){
        return; //the array is sorted
    }
    else{
        int j=0;
        int flag = 1;
        while(flag){
            int largest = j;//initially assume the parent is the largerst which in the first loop is'nt
            int lc = 2*j+1;
            int rc = 2*(j+1);

            if(lc<=i && arr[lc]>arr[largest])largest = lc;
            if(rc<=i && arr[rc]>arr[largest])largest = rc;

            if(j!=largest){
                swap(arr,j,largest);
            }
            else{
               // printf("swapped\n");
                flag =0; //if there is no change in the largest element then the array is heapified
            }
        }

    }
}

void heap_sort(int *arr, int n){
    create_heap(arr,n);
    for(int i = n-1;i>=0;i--){
        swap(arr,i,0);
        heapify(arr,i-1);
    }
}

int binary_search(int *arr, int first, int last, int elem){
    if(first<=last){
        int mid = (first+last)/2;
       if(arr[mid]== elem){
            return mid;
       } 
       else if(arr[mid]>elem){
            return binary_search(arr,first,mid-1,elem);
       }
       else{
            return binary_search(arr,mid+1,last,elem);
       }
    }
    else{
        return -1;
    }
}


int main(){
    int n;
    int elem;
    int* arr = (int*)malloc(20*sizeof(int));

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements : ");
    for(int i = 0; i<n;i++){
        scanf("%d",arr+i);
    }

    heap_sort(arr,n);
    printf("The sorted array is : ");

    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Enter the element to be searched: ");
    scanf("%d", &elem);
    int index = binary_search(arr,0,n-1,elem);
    if(index!=-1){
        printf("The element is found at index %d\n",index);
    }
    else{
        printf("The element doesnt exist\n");
    }

    free(arr);

    return 0;
}
