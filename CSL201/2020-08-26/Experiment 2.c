#include<stdio.h>

void main(){
    int comp=0,swaps=0,i,j;
    int arr[100];
    int n,temp,smallest,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements in the array: ");
    for(i=0;i<n;i++)
        scanf("%d%*c",arr+i);

    for(i=0;i<n;i++){
        smallest =arr[i];
        pos =i;
        for(j=i;j<n;j++){
            if(arr[j]<smallest){
                smallest= arr[j];
                pos =j;
            }
            comp++;
        }
        if(pos!=i){
            temp = arr[pos];
            arr[pos] = arr[i];
            arr[i]=temp;
            swaps++;
        }

    }

    printf("Sorted Array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nNumber of comparisons = %d\n",comp);
    printf("Number of swaps= %d\n",swaps);

}
