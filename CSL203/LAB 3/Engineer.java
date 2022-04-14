
/* Engineer.java
 *
 * Done By: Rohit Karunakaran
 * 
 * */

class Employee
{
    void display()
    {
        System.out.println("Name of the class is Employee");
    }

    void calcSalary()
    {
        System.out.println("Salary of employee is 10000");
    }
}

public class Engineer extends Employee
{
    void calcSalary()
    {
        System.out.println("Salary of employee is 20000");
    }

    public static void main(String[] args)
    {
        Engineer e1 = new Engineer();

        e1.display();
        e1.calcSalary();
    }
}
