/**
  BankAccount.java
  
  Created By: Rohit Karunakaran

 **/

class BankAccount{
    String name;
    long accNumber;
    String accType;
    float balance;

    public void withdraw(float amount){
        //You cannot withdraw negative values
        if(amount>=0){

            if(balance-amount > 0){
                balance-=amount;
                System.out.println("Sucessfully withdrawn "+ amount+" from the account");
            }
            else{
                System.out.println("Error! Insufficient balance in Account");
            }
            System.out.println("Remaining balance in Account = " + balance+"\n");
        }

        else{
            System.out.println("Please enter a valid amount\n");
        }
    }

    public void deposit(float amount){
        //You can't deposit negative values
        if(amount>0){
            balance+=amount;
            System.out.println("Successfully deposited "+amount+" to the account");
            System.out.println("Remaining balance is "+ balance+"\n");
        } 
        else{
            System.out.println("Error!!!! Enter a valid value\n");
        }
    }
    
    public void display(){
        System.out.println("\n==================================================");
        System.out.println("Account Number: " + accNumber);
        System.out.println("Name of the Account Holder: "+ name);
        System.out.println("Account Type: "+ accType);
        System.out.println("Balance: "+ balance);
        System.out.println("==================================================\n");
    }
    //Default constructor 
    BankAccount(){
        name = " ";
        accNumber = 0l;
        accType = " ";
        balance = 0.0f;
    } 

    //Paramaterised constructor
    BankAccount(String n,float b, long a, String t){
        name = n;
        balance = b;
        accType = t;
        accNumber = a;
    }

    public static void main(String[] args){
        long a;
        String name;
        String type;
        float cash; 
        
        BankAccount benk = new BankAccount(); 
        BankAccount benk1 = new BankAccount("Babu",8034.123f,1029343458l,"Savings");
        
        benk.display();
        benk1.display();
        
        a = 11066049032l;
        name = "Dhamodharan";
        cash = 2340.0f;
        type = "Checkings";

        benk.name = name;
        benk.accNumber=a;
        benk.balance=cash;
        benk.accType=type;
        
        benk.withdraw(9000.0f);
        benk1.withdraw(800f);
        benk.deposit(-2000f);

        benk.display();
        benk1.display();
    }   
}
