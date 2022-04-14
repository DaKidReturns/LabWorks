/*  Program to multoply two given matrices
 *
 *  Done by Rohit Karunakaran
 */

class Program3{
    public static void main(String[] args){
        int[][] C;
        int a_rows,a_columns,b_rows,b_columns,c_rows,c_columns;
        int i,j,k;

        a_rows=3;
        a_columns=2;
        int A[][] = {{1,2},{4,5},{9,16}};
        
        b_rows = 2; b_columns=4;
        int B[][] = {{3,4,5,6},{4,3,1,0}};

        if(a_columns==b_rows){
            c_rows = a_rows;
            c_columns = b_columns;
            C = new int[a_rows][b_columns];
            
            System.out.println("Array A is : ");
            for(i=0;i<a_rows;i++){
                for(j=0;j<a_columns;j++){
                    System.out.print(A[i][j]+" ");
                }
                System.out.println(" ");
            }

            System.out.println("Array B is : ");
            for(i=0;i<b_rows;i++){
                for(j=0;j<b_columns;j++){
                    System.out.print(B[i][j]+" ");
                }
                System.out.println(" ");
            }

            for(i=0;i<a_rows;i++){
                for(j=0;j<b_columns;j++){
                    C[i][j]=0;
                    for(k=0;k<a_columns;k++){
                        C[i][j]+=(A[i][k]*B[k][j]);
                    }
                }
            }

            System.out.println("Solution Matrix is : ");
            for(i=0;i<a_rows;i++){
                for(j=0;j<b_columns;j++){
                    System.out.print(C[i][j]+" ");
                }
                System.out.println(" ");
            }

        }

        else{
            System.out.println("Matrix cant be multiplied");
        }
    }
}
