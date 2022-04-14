/* File Name : MultipleCatchExample.java
 *
 * Done By: Rohit Karunakaran
 *
 * */

public class MultipleCatchExample{

    public static void main(String args[]){
        //3 catches for a single try
        System.out.println("Example for multiple Catch Statements");
        try
        {
            int len = args.length;

            int i = Integer.parseInt(args[0]);
            int b = Integer.parseInt(args[1]);
            int c = i/b;
        }

        catch(NumberFormatException e)
        {
            System.out.println("In the First Catch");
            System.out.println("An Exception has occurred while parsing the command line input :"+e);
            System.out.println("Expected an integer");
        }
        
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("In the Second Catch");
            System.out.println("Expected more than 1 command line argument");
            System.out.println("Exception occured is : "+e);
        }
        
        catch(ArithmeticException e)
        {
            System.out.println("In the Third Catch");
            System.out.println("An Exception has occured : "+e);
        }
        finally
        {
            //System.out.println("");
            System.out.println("---------------------------------------");
        }
    }

}
