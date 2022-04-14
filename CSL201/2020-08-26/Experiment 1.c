#include<stdio.h>

void main(){
    int comp=0,swaps=0,i,j;
    int arr[100];
    int n,temp;
    printf("Enter the number of elements in the arrat: ");
    scanf("%d",&n);
    printf("Enter the elements in the array : ");
    for(i=0;i<n;i++)
        scanf("%d%*c",arr+i);

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swaps++;
            }
            comp++;
        }
    }
    printf("Sorted Array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nNumber of comparisons = %d\n",comp);
    printf("Number of swaps= %d\n",swaps);

}
