
#include<stdio.h>
#include<stdlib.h>


void printarr(int *a, int n){
    for(int i = 0;i<n;i++){
        printf("%d ",*(a+i));
    }
}

void enterValues(int *a, int n){
    printf("Enter the elements of the array: ");
    for(int i =0; i<n;i++){
        scanf("%d%*c",a+i); 
    }
}

void main(){
    int i,j;
    int n,comp=0,swaps=0;
    int arr[100];
    int temp; 
    char c;

    printf("Enter the number of elements in the array: ");
    scanf("%d%*c",&n);
/**/    printf("%d\n",n);
    enterValues(arr,n);
/**/    printarr(arr,n);
    printf("\n\n");
    
    for(i=1;i<n;i++){
        temp=arr[i];
        for(j=i-1;j>=0;j--){     
            comp++;       
            if(arr[j]<temp)break;
            arr[j+1]=arr[j];
            swaps++;
        }
        if(j!=i-1){
            swaps++;
            arr[j+1]=temp;
        }
        printf("The array after %d step is : ",i);
        printarr(arr,n);printf("\n");
        
    }
    
    printf("\n\nThe sorted array is -> ");
    printarr(arr,n);printf("\n\n"); 
    printf("The total number of comparisons = %d\nThe total number of swaps = %d\n",comp,swaps);  
}
