/* Program2.java
 *
 *  Done By: Rohit Karunakaran
 *
 *  Abstract classes:
 *      Shape
 *  Classes: 
 *      Rectangle : extends Shape
 *      Triangle : extends Shape
 *      Hexagon : extends Shape
 * */


abstract class Shape
{   
    abstract void numberOfSides();
}

class Rectangle extends Shape
{
    void numberOfSides()
    {
        System.out.println("Number of sides in Rectangle= 4");
    }
}

class Triangle extends Shape
{
    void numberOfSides()
    {
        System.out.println("Number of sides in Triangle= 3");
    }
}

class Hexagon extends Shape
{
    void numberOfSides()
    {
        System.out.println("Number of sides in Hexagon = 6");
    }
}

public class Program2
{
    public static void main(String args[])
    {
        Rectangle r1 = new Rectangle();
        Triangle t1 = new Triangle();
        Hexagon h1 = new Hexagon();

        r1.numberOfSides();
        t1.numberOfSides();
        h1.numberOfSides();
    }
}
