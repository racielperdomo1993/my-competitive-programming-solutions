import java.util.Scanner;
 
public class Main
{
   public static void main(String args[]) 
   {
      Scanner br = new Scanner(System.in);
 
      int numCasos = br.nextInt();
      int num, diagonalAnt, resto;
   
      for( int i = 0; i < numCasos; i++)
      {
         num = br.nextInt();
    
         diagonalAnt = (int)( Math.sqrt( num << 1 ) - 0.5 );
         resto = num - diagonalAnt * ( diagonalAnt + 1 )/2;
   
         if( ( diagonalAnt & 1 ) == 0 )
            System.out.println( "TERM " + num + " IS " + (diagonalAnt+2-resto) + "/" + resto );
 
         else
            System.out.println( "TERM " + num + " IS " + resto + "/" + (diagonalAnt+2-resto) );
      }
    
   }
}