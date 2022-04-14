/* Java Program to read and write to a file 
 * by: Rohit Karunakaran
 */

import java.io.*;


public class ReadWriteToFile
{
    public static void main(String args[]) throws IOException, FileNotFoundException
    {

        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int i;
        String fileName = "file.txt";
        File originalFile = new File(fileName);

        if(!originalFile.exists()) originalFile.createNewFile();

        try
        {
            FileReader fileReader1 = new FileReader(fileName);
            File copy = new File("copy.txt");

            if(!copy.exists())
            {
                copy.createNewFile();    
            }
            
            try
            {
                FileWriter fileOutput = new FileWriter(copy);

                System.out.println("The String in the old file is : ");
                while ((i=fileReader1.read())!=-1)
                {
                    fileOutput.write((char)i);
                    System.out.print((char)i);
                }
                System.out.println(" ");
                fileOutput.flush();
                fileOutput.close();
            }
            catch (FileNotFoundException e)
            {
                System.out.println("The File is not writable or the file doesnt exist");
                e.printStackTrace();
            }
            finally
            {
                fileReader1.close();
            }

            FileReader fileReader2 = new FileReader(copy);

            System.out.println("\nThe contents of the new file is :");
            while((i=fileReader2.read())!=-1)System.out.print((char)i);
            System.out.print("\n");

        }
        catch (FileNotFoundException e)
        {
            System.out.println("File is not found or the file is not readable "+e);
        }
    }
}
