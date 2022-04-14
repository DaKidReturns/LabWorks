/*Implementation of linear Search*/

#include<stdio.h>

/*Linear search funtion:
 * Takes in an array A and a value query to search for in the array
 * Returns the position of the element or prints an error message if the element is not found
 */
int linearSearch(int* A,int n,int query){
    int KEY;
    int i;
    for(i=0;i<n;i++){
        if(A[i]==query){
            break;
        }
    }
    if(i==n){
        return -1;
    }
    else{
        return i; 
    }
}

void getValues(int* A, int n){
    for(int i = 0; i<n; i++){
        scanf("%d%*c",A+i); 
    }
}

void main(){
    int n;
    int arr[100];
    int elem;
    printf("Enter the size of the array: ");
    scanf("%d%*c",&n);
    printf("Enter the elements of the array: ");
    getValues(arr,n);
    printf("Enter the element to be searched: ");
    scanf("%d%*c",&elem);

    int KEY = linearSearch(arr,n,elem);
    if(KEY<0){
        printf("%d doesn't exist in the array\n",ele,); 
    }
    else{
        printf("First occurance of %d is in position %d and index %d\n",elem,KEY+1,KEY);
    }

}
