/*  Done By: Rohit Karunakaran
 *
 *  TODO:
 *  Employee:
 *      Attributes:
 *          Name -- String
 *          Age -- int
 *          PhoneNumber -- long
 *          Address -- String
 *          Salary -- float
 *      Methods:
 *          printSalary() -- prints the salary of the employee
 *  
 *  Officer - inherited from Employee:
 *      Attributes:
 *          specialization -- String
 *  
 *  Manager - inherited from Employee:
 *      Attributes:
 *          department -- String
 *
 *Task: assign name, age, phoneNo, addr and salary to an office and a manager 
 *      by making an object of both and print the same
 * */


class Employee {
    String name;
    int age;
    long phoneNo;
    String addr;
    float salary;

    void displayEmployee(){
        System.out.println("Name: "+this.name);
        System.out.println("Address: "+this.addr);
        System.out.println("Phone Number: "+this.phoneNo);
        System.out.println("Salary : "+this.salary);
    }

    void printSalary(){
        System.out.println("Salary of "+this.name+" is "+ this.salary);
    }

    Employee(String name, int age, long phoneNo, String addr,float salary){
        this.name = name;
        this.age = age;
        this.phoneNo = phoneNo;
        this.addr = addr;
        this.salary = salary;        
    }

    Employee(){
        this(" ",0,0l," ",0.0f);
    }

    public static void main(String [] args){
        Manager m1 = new Manager("Radhakrishnan",59,9823148320l,"123, Boulevard of Broken Dreams",4529.19f,"Research and Development");
        Officer o1 = new Officer("Anto Davis",48, 9847120926l,"Green House Villa, Pulmaidhanam", 3892.81f,"Corporate Security");
        m1.printSalary();
        o1.printSalary();

        m1.displayEmployee();
        o1.displayEmployee();
    }

}

class Officer extends Employee{
    String spec;
    
    void displayEmployee(){
        System.out.println("=========================================");
        super.displayEmployee();
        System.out.println("Specialization in "+ this.spec);
        System.out.println("=========================================");
        System.out.println("\n");
    }

    Officer(String name, int age, long phoneNo, String addr,float salary,String spec){
        super(name,age,phoneNo,addr,salary);
        this.spec = spec;
    }
    
    Officer(){
        this(" ",0,0l," ",0.0f," ");
    }
}

class Manager extends Employee{
    String dep;

    void displayEmployee(){
        System.out.println("=========================================");
        super.displayEmployee();
        System.out.println("Manager of "+ this.dep);
        System.out.println("=========================================");
        System.out.println("\n");
    }

    Manager(String name, int age, long phoneNo, String addr,float salary,String dep){
        super(name,age,phoneNo,addr,salary);
        this.dep= dep;
    }

    Manager(){
        this(" ",0,0l," ",0.0f," ");
    }

}
