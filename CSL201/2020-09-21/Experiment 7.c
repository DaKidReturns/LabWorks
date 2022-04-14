#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

void printSparse(int **sp){
int i;
    printf("The sparse array is \n");
    for(i=0;i<=sp[0][2];i++){
        printf("[%d] %d  %d  %d \n",i,sp[i][0],sp[i][1],sp[i][2]);fflush(stdout); 
    }
}

int** readSparse(){
    int** sp = (int**) malloc(MAX_SIZE*sizeof(int*));
    int m,n;
    int i,j,k = 0;
    int A[10][10];

    for (i = 0;i<MAX_SIZE;i++)
        sp[i] = (int*)malloc(3*sizeof(int));

    //get the values for rows and columns in A 
    printf("Enter the number of rows and columns-> ");
    scanf("%d%*c%d%*c",&m,&n);
    
    //Receive values for the sparse matrix A
    printf("Enter the values of the sparse matrix A\n");
    for(i=0;i<m;i++){
        printf("Values for row %d -> ",i+1);
        for(j=0;j<n;j++){
            scanf("%d%*c",&A[i][j]);
            
            //find the triplet represent of the sparse matrix
            if(A[i][j]!=0){
                k++;      
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = A[i][j];
            }
            
        } 
    }

    sp[0][0] = m;
    sp[0][1] = n;
    sp[0][2] = k;
    return sp;
}

void transpose(int** sp1){
    int m = sp1[0][0];
    int n = sp1[0][1];
    int count = sp1[0][2];
    int **sp_t = (int**)malloc(MAX_SIZE*sizeof(int*));
    
    for(int i = 0;i<MAX_SIZE;i++){
       sp_t[i] = (int*) malloc(MAX_SIZE*sizeof(int));
    }
    
    if(count == 0){
        printf("The array is empty ");
        free(sp_t);
        return;
    }
    else{
        sp_t[0][0]=sp1[0][1];
        sp_t[0][1]=sp1[0][0];
        sp_t[0][2]=sp1[0][2];

        int i,j,k=1;

        for(i = 0;i<n;i++){
            for(j = 1;j<=count;j++){
                if(sp1[j][1]==i){
                    sp_t[k][0] = sp1[j][1];
                    sp_t[k][1] = sp1[j][0];
                    sp_t[k][2] = sp1[j][2];
                    k++;
                }
            }
        }
        printSparse(sp_t);
    }
}

int** add(int** A, int** B){
    int **c;
    int size = A[0][2]+B[0][2]+2;
    int i,j;
    int count = 0;
    
    if(A[0][0]==B[0][0]&&A[0][1]==B[0][1]){
        printf("Arrays can be added\n");fflush(stdout);

        c  = (int**) malloc(size*sizeof(int*));
        for(i=0;i<size;i++){
            c[i] = (int*) malloc(3*sizeof(int));
        }
        
        c[0][0] = A[0][0];c[0][1] = A[0][1];

        i=1;j=1; 
        while(i<=A[0][2]&&j<=B[0][2]){
            if(A[i][0]<B[j][0]){
                count++;
                c[count][0] = A[i][0];
                c[count][1] = A[i][1];
                c[count][2] = A[i][2];
                i++;
            }
            else if(A[i][0]>B[j][0]){
                count++;
                c[count][0] = B[j][0];
                c[count][1] = B[j][1];
                c[count][2] = B[j][2];
                j++;
            }
            else{
                if(A[i][1]<B[i][1]){
                    count++;
                    c[count][0] = A[i][0];
                    c[count][1] = A[i][1];
                    c[count][2] = A[i][2];
                    i++;
                }
                else if(A[i][1]>B[j][1]){
                    count++;
                    c[count][0] = B[j][0];
                    c[count][1] = B[j][1];
                    c[count][2] = B[j][2];
                    j++;
                }
                else{
                    count++;
                    c[count][0] = B[j][0];
                    c[count][1] = B[j][1];
                    c[count][2] = B[j][2]+A[i][2];
                    i++;j++;
                }
            }
        }

    while(i<=A[0][2]){
            count++;
            c[count][0] = A[i][0];
            c[count][1] = A[i][1];
            c[count][2] = A[i][2];
            i++;
        }

    while(j<=B[0][2]){
            count++;
            c[count][0] = B[j][0];
            c[count][1] = B[j][1];
            c[count][2] = B[j][2];
            j++;
        }
        c[0][2] = count;
        return c;
    }

    else{
        printf("Matrix cant be added");
        free(A);
        free(B);
        exit(0);
        return 0;
    }
    
    


}


void main(){
    int i,j,k=0;
    int A[10][10];
    int **sp1;
    int **sp2;
    int m,n;    //m is the number of rows and n is the number of columns
    
    int** sum;
    char c;
    //int RUN = 1;
    //while(RUN){
        sp1 = readSparse();
        sp2 = readSparse();
        //terminate the loop if n is entered
        printSparse(sp1);
        printSparse(sp2);

        //Print the transposes
        printf("\nTranspose of the first matrix is \n");
        transpose(sp1);
        printf("\nTranspose of the second matrix is \n");
        transpose(sp2);
        
        //Find the sum of the matrices
        sum = add(sp1,sp2);
        
        printf("Sum of both the matrices is \n");
        printSparse(sum);
     //   printf("Do You want to continue?????? (Y/N) -> ");
     //   fflush(stdin);
     //   c = getc(stdin);
     //   if(c == 'N'|| c=='n') RUN = 0;
    //}
        free(sp1);
        free(sp2);
        free(sum);
}
