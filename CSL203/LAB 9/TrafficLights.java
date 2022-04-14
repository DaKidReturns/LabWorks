import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class TrafficLights{
    TrafficLights(){
        JFrame jfrm = new JFrame();
        jfrm.setLayout(new GridLayout(3,1));
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jfrm.setSize(200,500);
        JRadioButton signalButtons[] = new JRadioButton[3];
        ButtonGroup bg = new ButtonGroup();

        signalButtons[0]=new JRadioButton("Red");
        signalButtons[0].setBackground(Color.GRAY);;
        
        signalButtons[1]=new JRadioButton("Yellow");
        signalButtons[1].setBackground(Color.GRAY);;

        signalButtons[2]=new JRadioButton("Green");
        signalButtons[2].setBackground(Color.GRAY);;

        bg.add(signalButtons[0]);
        bg.add(signalButtons[1]);
        bg.add(signalButtons[2]);

        jfrm.add(signalButtons[0]);
        jfrm.add(signalButtons[1]);
        jfrm.add(signalButtons[2]);

        signalButtons[0].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                signalButtons[0].setBackground(Color.RED);
                signalButtons[1].setBackground(Color.GRAY);;
                signalButtons[2].setBackground(Color.GRAY);;
            }
        });

        signalButtons[1].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                signalButtons[0].setBackground(Color.GRAY);
                signalButtons[1].setBackground(Color.YELLOW);;
                signalButtons[2].setBackground(Color.GRAY);;
            }
        });

        signalButtons[2].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                signalButtons[0].setBackground(Color.GRAY);
                signalButtons[1].setBackground(Color.GRAY);;
                signalButtons[2].setBackground(Color.GREEN);;
            }
        });
        jfrm.setVisible(true);

    }
    public static void main(String[] args){
        new TrafficLights();
    }
    
}
