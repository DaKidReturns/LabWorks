/* File name: TryFinallyExample.java
 *  
 *  Done By: Rohit Karunakaran
 * */

public class TryFinallyExample
{
    public static void main(String args[]){
        int a =3;
        int len = args.length;
        try{
            int b = a/len;
        }

        finally{
            System.out.println("In the finally Statement");
            System.out.println("Have a nice Day");
            System.out.println("---------------------------------------\n");
        }
    }
}
