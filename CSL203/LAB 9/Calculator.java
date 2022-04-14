/****************************************
 * Calculator implementing the funtions +,-,*,/
 * Done By: Rohit Karunakaran
 * *************************************/
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class Calculator
{
    JFrame jfrm;
    JLabel disp;
    GridBagConstraints c ;
    ActionListener numberButtonPressed;
    ActionListener mathButtonPressed;
    boolean add;
    boolean sub;
    boolean mul;
    boolean div;
    boolean done;

    double calc;

    public Calculator()
    {
        jfrm = new JFrame("Calculator");
        jfrm.setLayout(new GridBagLayout());
        c = new GridBagConstraints();
        calc = 0;
        add=false;
        sub=false;
        div=false;
        mul=false;
        done = true;
        
        jfrm.setSize(270,330);
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        disp = new JLabel(String.valueOf(calc));

        numberButtonPressed = new ActionListener()
        {
            public void actionPerformed(ActionEvent ae)
            {
                JButton callerButton = (JButton)ae.getSource();
                String val = callerButton.getText();
                String displayText = disp.getText();

                if(displayText.equals("ERROR"))
                {
                    disp.setText(val);
                }
                else
                {
                    if(done ==true){
                            disp.setText(String.valueOf(Double.parseDouble(val)));
                    }
                    else{
                            double newVal = Double.parseDouble(displayText)*10+Double.parseDouble(val);
                            disp.setText(String.valueOf(newVal));
                        }
                }
                done = false;
            }
        };

        mathButtonPressed = new ActionListener()
        {
            public void actionPerformed(ActionEvent ae)
            {
                //done = true;
                JButton b = (JButton) ae.getSource();
                double result = 0.0;
                String val = disp.getText();
                if(!done)
                {
                    if(val.equals("ERROR"))
                    {
                        disp.setText("0.0");
                        calc = 0.0;
                    }
                    else
                    {
                        if(add||sub||div||mul)
                        {
                            double operand= Double.parseDouble(val);
                            if(add)
                            {
                                result = calc+operand;
                                add = false;
                            }
                            else if(sub)
                            {
                                result = calc-operand;
                                sub = false;
                            }
                            else if(mul)
                            {
                                result = calc*operand;
                                mul = false;
                            }
                            else if(div)
                            {
                                if(operand!=0.0)
                                    result = calc/operand;
                                else{
                                    disp.setText("ERROR");
                                    done = true;
                                    return;
                                }
                                div = false;
                            }
                            calc = result;
                            disp.setText(String.valueOf(calc));

                        }
                        else
                        {
                            calc = Double.parseDouble(val);
                            char op = b.getText().charAt(0);
                            switch(op)
                            {
                                case '+':add=true;break;
                                case '*':mul=true;break;
                                case '/':div=true;break;
                                case '-':sub=true;break;
                            }
                        }

                    }
                    done = true;
                }
            }
        };

        c.anchor = GridBagConstraints.FIRST_LINE_START;
        c.fill= GridBagConstraints.VERTICAL;
        c.weightx=0.5;
        c.gridx=0; c.gridy=0;
        c.gridwidth = 3;
        c.ipady = 20;

        jfrm.add(disp,c);
        addButtons();
        jfrm.setVisible(true);
    }

    private void addButtons()
    {
       c.ipady = 10;
       c.gridwidth = 1;
       c.fill= GridBagConstraints.HORIZONTAL;
       c.anchor = GridBagConstraints.LINE_START;
       JButton numbers[] = new JButton[10];
       for(int i = 0;i<10;i++)
       {
            numbers[i] = new JButton(String.valueOf(i));
            numbers[i].addActionListener(numberButtonPressed);
            if(i!=0)
                c.gridx = (i+2)%3;
            else 
                c.gridx = 1;
            c.gridy = i%3==0?4-(i/3-1):4-(i/3);
            jfrm.add(numbers[i],c);
       }
       JButton addButton= new JButton("+");
       addButton.addActionListener(mathButtonPressed);

       JButton subButton= new JButton("-");
       subButton.addActionListener(mathButtonPressed);

       JButton mulButton= new JButton("x");
       mulButton.addActionListener(mathButtonPressed);

       JButton divButton= new JButton("/");
       divButton.addActionListener(mathButtonPressed);

       c.gridx = 3;
       c.gridy = 2;
       jfrm.add(addButton,c);
       c.gridy = 3;
       jfrm.add(subButton,c);
       c.gridy =4;
       jfrm.add(mulButton,c);
       c.gridy = 5;
       jfrm.add(divButton,c);

       JButton equalButton = new JButton("=");
       equalButton.addActionListener(new ActionListener()
               {
                    public void actionPerformed(ActionEvent ae)
                    {
                        double result = 0.0;
                        String val = disp.getText();
                        if(!done)
                        {
                            if(val.equals("ERROR"))
                            {
                                disp.setText("0.0");
                                calc = 0.0;
                            }
                            else
                            {
                                if(add||sub||div||mul)
                                {
                                    double operand= Double.parseDouble(val);
                                    if(add)
                                    {
                                        result = calc+operand;
                                        add = false;
                                    }
                                    else if(sub)
                                    {
                                        result = calc-operand;
                                        sub = false;
                                    }
                                    else if(mul)
                                    {
                                        result = calc*operand;
                                        mul = false;
                                    }
                                    else if(div)
                                    {
                                        if(operand!=0.0)
                                            result = calc/operand;
                                        else{
                                            disp.setText("ERROR");
                                            done = true;
                                            return;
                                            }
                                        div = false;
                                    }
                                    calc = result;
                                    disp.setText(String.valueOf(calc));
                                }
                                else
                                {
                                    calc = Double.parseDouble(val);
                                }

                            }
                            done = true;
                        }
                    }
               });

        c.gridy=5;
        c.gridx =2;
        jfrm.add(equalButton,c);

        c.gridx = 0;
        JButton clearAll = new JButton("AC");
        clearAll.addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent ae)
                    {
                        add = mul = div = sub = false;
                        done = true;
                        disp.setText("0.0");
                    }
                }
                );
        jfrm.add(clearAll,c);

    }


    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable()
                {
                    public void run()
                    {
                        new Calculator();
                    }
                });
    }
}
