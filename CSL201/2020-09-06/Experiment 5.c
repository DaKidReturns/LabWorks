/* Implementation of binary search
 */
#include<stdio.h>

int binarySearch(int *A,int n, int elem){
    int beg = 0;
    int last = n-1;
    int mid;
    while(beg<=last){
        mid = (last+beg)/2;
        if(A[mid]>elem){
            last=mid-1; 
        }
        else if(A[mid]<elem){
            beg = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

void inputArray(int *A, int n){
    for(int i = 0;i<n;i++){
        scanf("%d%*c",A+i);
    }
}

void main(){
    int n,elem;
    int arr[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d%*c",&n);
    printf("Enter the elements of the array: ");
    inputArray(arr,n);
    
    printf("Enter the element to search for: ");
    scanf("%d%*c",&elem);

    int KEY = binarySearch(arr,n,elem);
    if(KEY<0){
        printf("%d is not in the array\n",elem);
    }
    else{
        printf("%d is found at postion %d and at index %d in the array\n",elem,KEY+1,KEY);
    }
}
