/*
 *Program to check whether a given number is 
 *prime or not
 */

class Program2{
    public static void main(String[] args){
        int n,i;
        boolean flag=true;
        
        n=31; //The number to be checked

        for(i=2;i<n/2;i++){
            
            if(n%i==0){
                flag=false;
            }
        
        }
        
        if(flag)
            System.out.println("The number "+n+" Is prime");
        else
            System.out.println("The number "+n+" is not prime");
    }
}
