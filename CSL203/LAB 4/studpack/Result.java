/*  File name : Result.java
 *
 *  Done by : Rohit Karunakaran
 *  
 */

package studpack;

interface Sports
{
    int grade = 34; //This is public static final 
    
    void displayGrade();
}

public final class Result extends Student implements Sports
{
    private int total;

    public void displayGrade()
    {
        System.out.println("Grade = "+this.grade);
    }

    public Result(String name, int rollNo, int mark1, int mark2, int mark3)
    {
        super(name,rollNo,mark1,mark2,mark3);
        
        // total = marks + grade;
        this.total = this.mark1+this.mark2+this.mark3+this.grade;
    }

    public Result()
    {
        this("",0,0,0,0); //Constructor chaining
    }

    public void displayTotal()
    {
        System.out.println("\n======================================");
        System.out.println("Name of the student is "+this.name);
        System.out.println("Roll No: "+this.rollNo);
        System.out.println("Total = "+this.total);
        System.out.println("======================================\n");
    }

}
