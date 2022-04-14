/* File Name: NoSufficientArgument.java
 *
 * Done By: Rohit Karunakaran
 */

public class NoSufficientArgumentForAdding
{
    public static void main(String[] args) //throw Excenption
    {
        try
        {
            if(args.length<2){
                throw new ArrayIndexOutOfBoundsException("Less than 2 command line arguments found");
            }
            else{
            int a = Integer.parseInt(args[0]);
            int b = Integer.parseInt(args[1]);
            int c = a+b;

            System.out.println("No Exception has occurred. The sum = "+c);
            }
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println(e);
        }
        catch(NumberFormatException e)
        {
            System.out.println("Pass an Integer as a command line argument");
            System.out.println(e);
        }
    }
}
