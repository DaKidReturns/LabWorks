/* File name: NestedTryExample.java
 *
 * Done By: Rohit Karunakaran
 */

public class NestedTryExample
{
    public static void main(String args[]){
        //3 levels of nesting
        int a[] = {1,2,5,32,12};
        System.out.println("\nExample With Nested Try Statements");
        try
        {
            System.out.println("Inside the Outer Most Try Block");
            System.out.println("=================================\n");
            int b = a[3];
            try
            {
                System.out.println("Inside the Inner Try Block");
                System.out.println("=================================\n");
                int c = 2*a[1]+a[0]-a[2];
                try
                {
                    System.out.println("Inside the Innermost Try Block");
                    System.out.println("=================================\n");
                    int e = b/c;
                }

                catch(ArithmeticException e)
                {
                    System.out.println("An Exception has occured in the innerMost try Block");
                    System.out.println("An Arithmetic expression error occured : "+e);
                }
                
                finally
                {
                    System.out.println("In the final block of the Innermost try expression");
                    System.out.println("=================================\n");
                }
                //System.out.println("After the innermost try bolck Statement");
            }

            finally
            {
                System.out.println("In the final block of the Inner try expression");
                System.out.println("=================================\n");
            }

            int d = a[41]; //Array out of bounds exception 

            System.out.println("I assure you that as long as the size of a is less than 42,");
            System.out.println("This statement will not be excecuted");
            //TRY 1 END    


        }
        
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Exception :"+e+" \nhas Occured in the outermost try block");
        }

        finally
        {
            System.out.println("The Final Block of the Outermost try is complete");
            //System.out.println("=================================\n");
            System.out.println("---------------------------------------\n");
        }
        

    }
}
