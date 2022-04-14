/*File Name: ThrowsExample.java
 *
 *Done By: Rohit Karunakaran
 */

import java.io.*;

public class ThrowsExample
{

    public static void main(String args[]) throws IOException, FileNotFoundException
    {
        File f = new File("File1.txt");
        FileReader f1 = new FileReader(f);
        System.out.println("The file is opened");
        f1.close();
        f.close();

    }
    
}
