/*  File Name : Hybrid.java
 *
 *  Done By: Rohit Karunakaran
 *  
 *  The package studpack contains the classes Result and Students and a Sports interface
 *  
 *  The Result class implements Sports and inherits Student.  
 * */
import studpack.Result;
import studpack.Student;

public class Hybrid
{
    public static void main(String args[])
    {   
        String name[] = {"Bhaskaran Pilla","Chandra Mohan","Sivadasan","Mani Vessel","Narayani"};
        int rollNo[] = {4,11,56,34,41};
        int marks[] = {45,69,23};
        
        //Create an arry of 5 students
        Student A[]=new Result[5];  //Dynamic Method Dispatch

        //Set the values for the Students
        for(int i = 0;i<5;i++){
            A[i] = new Result(name[i],rollNo[i],marks[i%3]+2*i,marks[i%3]+3*i,marks[i%3]+4*i);
        }

        //Print out the values for the students
        for(int i = 0;i<5;i++){
            A[i].displayTotal();
        }

    }
}
