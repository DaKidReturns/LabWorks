#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void printarr(int *a, int n){
    for(int i = 0;i<n;i++){
        printf("%d ",*(a+i));
    }
}

void enterManual(int *a, int n){
    for(int i =0; i<n;i++){
        scanf("%d%*c",a+i); 
    }
}

void enterRandom(int *a, int n){
    srand(time(0));
    int MAX=100;
    int MIN=0;
    for(int i =0 ; i<n; i++){
        a[i]= (rand()%(MAX-MIN+1))+MIN;
    }
}

void main(){
    int i,j;
    int n;
    int arr[100];
    int temp; 
    int comp=0,swaps=0;
    char c;

    int RUN=1;
    printf("Enter the number of elements in the array: ");
    scanf("%d%*c",&n);

    while(RUN){
        printf("Press 1 for random values and 0 to enter values maunally: ");
        scanf("%c%*c",&c);

        if(c=='1'||c=='0')RUN=0;
        else{
            printf("ERROR!!!!! Please Co-operate and enter either 1 or 0\n");
        }
    }

    if(c=='0') enterManual(arr,n);
    if(c=='1') {
        enterRandom(arr,n);
        printf("The Random Array is : ");
        printarr(arr,n);
        printf("\n");
    }
    
    for(i=1;i<n;i++){
        temp=arr[i];
        for(j=i-1;j>=0;j--){            
            if(arr[j]<temp)break;
            comp++;
            arr[j+1]=arr[j];
            swaps++;
        }
        if(j!=i-1){
            arr[j+1]=temp;
            swaps++;
        }
        printf("The array after %d step is : ",i);
        printarr(arr,n);
        printf("\n");
        
    }
    
    printf("The sorted array is ");
    printarr(arr,n); 
    printf("\n");  
    printf("The number of comparisons = %d \nThe number of swaps = %d\n",comp,swaps);
}
