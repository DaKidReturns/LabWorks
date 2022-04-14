/************************************************
 * Java Program to Demonstrate Thread Synchronization
 * Done By: Rohit Karunakaran
 * **********************************************/

public class Synch
{
    public static void main(String args[])
    {
        Test target = new Test();
        ThreadsInSync ob1 = new ThreadsInSync(target,"Hello");
        ThreadsInSync ob2 = new ThreadsInSync(target,"Synchronized");
        ThreadsInSync ob3 = new ThreadsInSync(target,"Thread");

        System.out.println("Without Sychronization");

        ob1.t.start();
        ob2.t.start();
        ob3.t.start();


        try{
            Thread.sleep(2900);
            System.out.println("With Sychronization");
        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupted");
        }

    }
}

class Test
{
    //synchronized void test(String msg)  <--- Either this or look at line 50
    void test(String msg)
    {
        System.out.print("["+msg);
        try{
            Thread.sleep(1000);

        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupted");
        }
        System.out.println("]");
    }
}

class ThreadsInSync implements Runnable
{
    String msg;
    Test target;
    Thread t;

    public ThreadsInSync(Test targ,String s)
    {
        target = targ;
        msg = s;
        t= new Thread(this);
    }

    public void run()
    {
        target.test(msg);
        try{
            Thread.sleep(2000);
        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupted");
        }
        
        synchronized(target){
            target.test(msg);
        }

    }
}

