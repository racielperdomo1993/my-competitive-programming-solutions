import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static BigInteger factorial(BigInteger n)
	{
		BigInteger cero = new BigInteger("2");
		BigInteger uno = new BigInteger("1");
		BigInteger aux= new BigInteger("-1");
		if(n.compareTo(cero) < 0)
		    return uno;
		else return n.multiply(factorial(n.add(aux)));
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger n;
		
		int t;
		t = sc.nextInt();
		while(t-->0)
		{
		    n = sc.nextBigInteger();
		    System.out.println(factorial(n));
		}
	}

}