/* Read interger as a stirng and print it's sum
 * File Name: StringTokenizerExample.java
 *
 * Done By: Rohit Karunakaran
 * */

import java.io.*;
import java.util.StringTokenizer;

public class StringTokenizerExample
{
    public static void main(String args[]) throws IOException
    {
        int sum = 0,a=0;
        //int n = 0;

        System.out.print("Enter an Integer Value : ");

        String s = new String(new BufferedReader(new InputStreamReader(System.in)).readLine()); //reads a line from the input
        System.out.print("\n");

        StringTokenizer st = new StringTokenizer(s,"0123456789",true); //if the boolean argument is true each of the delimeter is considered as tokens themselves

        System.out.print("The Number entered = ");
        while(st.hasMoreTokens())
        {
            try
            {
                a = Integer.parseInt(st.nextToken());
                //n = n*10+a;
                System.out.print(a);
            }
            catch(NumberFormatException e)
            {
                System.out.println("Expected an integer value");
                System.out.println("\nHere is the stack trace");

                e.printStackTrace();
            }
            /*finally
            {
                System.out.println("Program has excecuted");
            }*/

            sum+=a;
        }
        
        System.out.println("\nSum = "+sum);
       // System.out.println(n);
    }
}
