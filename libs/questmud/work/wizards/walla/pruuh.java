import javax.swing.*;

public class pruuh
{

    public static void main(String[] args)
    {
        String chooseHeight=JOptionPane.showInputDialog(null, "How high should the pattern be?","Pattern height",JOptionPane.QUESTION_MESSAGE);
        String chooseWidth=JOptionPane.showInputDialog(null, "How wide should the pattern be?","Pattern width",JOptionPane.QUESTION_MESSAGE);
        
        //converting string to int
        
        int height = Integer.decode(chooseHeight);
        int width = Integer.decode(chooseWidth);
        int halfWidth = width / 2;
        int halfHeight = height / 2;
        int centerLine1 = 0;
        int centerLine2 = 0;
        int centerColumn1 = 0;
        int centerColumn2 = 0;
        
        //Sanity check for parameters
        if(width < 1 || height < 1)
        {
            JOptionPane.showMessageDialog(null, "Width and height not compatible","ERROR",
            JOptionPane.ERROR_MESSAGE);
        }
        

        for ( int x = 0; x < width; x++) {
          
          for (int y = 0; y < height; y++) {
              
              if ((((x == 0) || (x == (width-1))) || (x == (halfWidth-1))) || (x == halfWidth)) {
              
                  System.out.print("*");
                } // close if
                
                else {
                    System.out.print(" ");
                }//close else
                
                /*
                 
                if ((((y == 0) || (y == (height-1))) || (y == (halfHeight-1))) || (y == halfHeight)) {
                    System.out.print("*");
                } //close if
                
                else {
                    System.out.print(" ");
                } //close else
                
                */ 
               
            } //close 2nd for
             System.out.println("");
        } // close 1st for
        
       
        
        } // close method
    } // close class




