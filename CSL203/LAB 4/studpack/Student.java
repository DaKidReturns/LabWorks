/*  File Name: Student.java
 *  
 *  Done by Rohit Karunakaran
 *
 * */
package studpack;

public class Student
{

    String name;
    int rollNo;
    int mark1,mark2,mark3;

    public Student(String name, int rollNo,int mark1,int mark2,int mark3)
    {
        this.name = name;
        this.rollNo = rollNo;
        this.mark1 = mark1;
        this.mark2 = mark2;
        this.mark3 = mark3;
    }    

    public Student()
    {
        this("",0,0,0,0);
    }

    public void displayTotal()
    {
        int total = mark1+mark2+mark3;
        System.out.println("Total marks earned by "+this.name+" is : "+total);
    }
}

