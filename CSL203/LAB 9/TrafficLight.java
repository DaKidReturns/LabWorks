import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class Signal extends JComponent
{
    private boolean red;
    private boolean yellow;
    private boolean green;
        Signal() 
        {
            red = false;
            green =  false;
            yellow = false;
        }
        
        public void paint(Graphics g)
        {

            Graphics2D g2 = (Graphics2D)g;
            g2.setColor(Color.BLACK);
            g2.drawRect(10,10,200,620);
            g2.fillRect(10,10,200,620);

            if(red)
                g2.setColor(Color.RED);
            else
                g2.setColor(Color.GRAY);  //Red
            g2.drawOval(20,20,180,200);
            g2.fillOval(20,20,180,200);
            
            if(yellow)
                g2.setColor(Color.YELLOW);
            else
                g2.setColor(Color.GRAY);  //Yellow
            g2.drawOval(20,220,180,200);
            g2.fillOval(20,220,180,200);

            if(green)
                g2.setColor(Color.GREEN);
            else
                g2.setColor(Color.GRAY);   //Green
            g2.drawOval(20,420,180,200);
            g2.fillOval(20,420,180,200);
        }
        public void toggleRed()
        {
            red = true;
            yellow= false;
            green = false;
        }
        public void toggleGreen()
        {
            red = false;
            yellow= false;
            green = true;
        }
        public void toggleYellow()
        {
            red = false;
            yellow= true;
            green = false;
        }

}

public class TrafficLight
{
    //Bulb greenBulb;
    //Bulb yellowBulb;
    //Bulb redBulb;

    TrafficLight()
    {
        Signal s = new Signal();
        JFrame jfrm = new JFrame("Traffic Lights");
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        jfrm.setBounds(50,50,500,720);
        jfrm.setSize(500,720);
        
        JRadioButton redButton = new JRadioButton("Red");
        redButton.setBounds(240,240,120,30);
        redButton.addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent ae)
                    {
                        if(redButton.isSelected())
                        {
                            s.toggleRed();
                            s.repaint();
                        }
                    }
                }
                );
        jfrm.add(redButton);

        JRadioButton yellowButton = new JRadioButton("Yellow");
        yellowButton.setBounds(240,280,120,30);
        yellowButton.addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent ae)
                    {
                        if(yellowButton.isSelected())
                        {
                            s.toggleYellow();
                            s.repaint();
                        }
                    }
                }
                );
        jfrm.add(yellowButton);

        JRadioButton greenButton = new JRadioButton("Green");
        greenButton.setBounds(240,320,120,30);
        greenButton.addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent ae)
                    {
                        if(greenButton.isSelected())
                        {
                            s.toggleGreen();
                            s.repaint();
                        }
                    }
                }
                );
        jfrm.add(greenButton);
        s.setBounds(10,10,220,640);
        jfrm.add(s);

        ButtonGroup bg = new ButtonGroup();
        bg.add(greenButton);
        bg.add(redButton);
        bg.add(yellowButton);

        jfrm.setVisible(true);
        //jfrm.repaint();
    }
    public static void main(String args[])
    {
        new TrafficLight();
    }
}

