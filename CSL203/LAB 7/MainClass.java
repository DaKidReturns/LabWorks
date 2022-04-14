/*Doubly Linked List implementation in Java
 * Done By: Rohit Karunakaran
 * */
import java.io.*;

/*Node class for the nodes of the linked list*/
class Node
{
    private int data;
    private Node prev;
    private Node next;

    //Constructors
    public Node(int x,Node next,Node prev)
    {
        data = x;
        this.prev =prev;
        this.next = next;
    }
    public Node(int x){ this(x,null,null); }
    public Node() { this(0); }

    
    //Gettes and Setters
    public Node getNextNode() { return this.next; }
    public Node getPrevNode() { return this.prev; }
    public int getData() { return this.data; }

    public void setNextNode(Node n) { this.next=n; }
    public void setPrevNode(Node n) { this.prev=n; }
    public void setNextNode() { this.next=null; }
    public void setPrevNode() { this.prev=null; }
}


/*  Doubly linked list class that contains the relevent functions for
 *  implementation*/

class DoublyLinkedList
{
    private Node header; //The header node
    public int length; //To keep a track of the length of the doubly linked list

    public DoublyLinkedList()
    {
        header = new Node();
        length=0;
    }

    public DoublyLinkedList(int nums[]) //Creates a doubly linked list when an array of numbers is passed
    {
        this();
        for(int x:nums)
        {
            this.add(x);
        }

    }

    public void add(int x) //add a node to the end of the doubly linked list
    {
        Node ptr=header;
        while(ptr.getNextNode()!=null)
            ptr=ptr.getNextNode();
        Node n = new Node(x);
        n.setPrevNode(ptr);
        n.setNextNode(ptr.getNextNode());
        ptr.setNextNode(n);
        length++;
    }

    public void remove(int x) //remove the node containing the given value if it exists
    {
        Node ptr=header.getNextNode();
        if(ptr==null)
        {
            System.out.println("The List is empty");
            return;
        }
        while(ptr!=null)
        {
            if(ptr.getData() == x)
                break;
            ptr=ptr.getNextNode();
        }
        if(ptr!=null)
        {
            //delete node
            if(ptr.getNextNode()!=null)
                ptr.getNextNode().setPrevNode(ptr.getPrevNode());
            ptr.getPrevNode().setNextNode(ptr.getNextNode());
            ptr.setNextNode(null);
            ptr.setPrevNode(null);
            length--;
        }
        else
        {
            System.out.println("No Such element found");
        }

    }


    public void displayList()
    {
        Node ptr=header.getNextNode();
        while(ptr!=null)
        {
            System.out.println(ptr.getData());
            ptr=ptr.getNextNode();
        }
    }
}

public class MainClass
{
    public static void main(String args[]) throws IOException
    {
        DoublyLinkedList dll = new DoublyLinkedList();
        int elem=0;
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        boolean Run = true;

        while(Run)
        {
            System.out.println("\n-------------Menu------------");
            System.out.println("1.Add an element");
            System.out.println("2.Remove an element");
            System.out.println("3.Display the List");
            System.out.println("4.Exit");
            System.out.print("\nEnter your choice:  ");
            try
            {
                int c = Integer.parseInt(r.readLine());
                switch(c)
                {
                    case 1: //add an element
                            System.out.print("Enter the elemet to be added: ");
                            elem = Integer.parseInt(r.readLine());
                            dll.add(elem);
                            break;
                    case 2: //remove an element
                            System.out.print("Enter the elemet to be deleted: ");
                            elem = Integer.parseInt(r.readLine());
                            dll.remove(elem);
                            break;
                    case 3: //display the list
                            System.out.println("\nThe List is :");
                            dll.displayList();
                            break;
                    case 4:Run = false;
                           break;
                    default: System.out.println("Please Enter a valid input ");
                             break;
                }
            }
            catch (NumberFormatException e)
            {
                System.out.println("Please Enter a integer value ");
                e.printStackTrace();
            }
        }
    }
}
