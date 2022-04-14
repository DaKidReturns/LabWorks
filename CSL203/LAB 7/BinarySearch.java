/* Binary search algorithm implementation in java
 * Done By: Rohit Karunakaran
 *
 **/

import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.*;


class BinarySearch
{

    //Recursive binary search funtion
    
    static int binarySearch(ArrayList<Integer> a,int elem,int beg,int last)
    {
        int mid = (beg+last)/2;
        if(beg<=last)
        {
            if(a.get(mid)==elem)
                return mid;
            else if(a.get(mid)>elem)
                return binarySearch(a,elem,beg,mid);
            else
                return binarySearch(a,elem,mid+1,last);
        }
        else
        {
            return -1; //If the element is not found it will return -1
        }
    }

    public static void main(String args[]) throws IOException
    {
        
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int elem=0;
        try
        {
            System.out.print("Enter the elements in the array in ascending order in th form  \"1 2 32 65 75 \" \nwith out the quotes: ");
            BufferedReader br= new BufferedReader(new InputStreamReader(System.in));

            String nums = br.readLine();

            StringTokenizer st = new StringTokenizer(nums," ");

            while(st.hasMoreTokens())
            {
                arr.add(Integer.parseInt(st.nextToken()));
            }

            System.out.print("Enter the element to be searched ");
            elem = Integer.parseInt(br.readLine());
            //arr.sort();
            int index = binarySearch(arr,elem,0,arr.size()-1);

            if(index==-1)
            {
                System.out.println("The element is not found\n");
            }
            else
            {
                System.out.println("The element is found at index "+index);
            }
        }
        catch(NumberFormatException e)
        {
            System.out.println("A Number expected ");
            e.printStackTrace();
        }

    }
}
