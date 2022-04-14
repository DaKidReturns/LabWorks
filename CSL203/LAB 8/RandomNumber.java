/*********************************************************
 * A Multi-threaded Program which has 3 threads,
 * Thread 1: prints a random number every 1 Second;
 * Thread 2: If the number is even then print it's square
 * Thread 3: If the number is odd then print the cube
 * *******************************************************/
/*********************************************************
 * Done By: Rohit Karunakaran
 ********************************************************/


class SquareThread implements Runnable
{
    int i;
    public Thread t;
    public SquareThread(int a)
    {
        t = new Thread(this,"Square Thread");
        i = a;
    }
    public void run()
    {
        int sq = i*i;
        System.out.println("The square of the number "+i+" is "+sq);
    }
}

class CubeThread implements Runnable
{
    public Thread t;
    int i;
    public CubeThread(int a)
    {
        t = new Thread(this,"Cube Thread");
        i = a;
    }
    public void run()
    {
        int qube = i*i*i;
        System.out.println("The Cube of the number "+i+" is "+qube);
    }
}


class RandomThread implements Runnable
{
    int i;
    //Random rn;
    public Thread t;

    public RandomThread()
    {
        //rn = new Random();
        i = (int)Math.random()*100;
        t = new Thread(this,"Random Number");
    }

    public void run()
    {
        for(int j=0;j<10;j++)
        {
           // i = rn.nextInt();  //Generates a random number from 0-99
            i = (int)(Math.random()*100);
            System.out.println("Random Number : "+i);
            if(i%2==0)
            {
                //Square thread
                new SquareThread(i).t.start();
                //s.t.start();
            }
            else
            {
                //cubeThread
                new CubeThread(i).t.start();
                //c.t.start();
            }
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException e)
            {
                System.out.println("Interrupted");
            }
        }
    }      
}

public class  RandomNumber
{
    public static void main(String args[])
    {
        RandomThread r =new RandomThread();
        r.t.start();
        
    }
}
