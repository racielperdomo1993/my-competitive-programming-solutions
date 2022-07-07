import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	
	public static void main (String args[]) throws IOException
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		BigInteger a;
		String num;
		BigInteger negat = new BigInteger("-1");
		BigInteger tres = new BigInteger("3");
		BigInteger dos = new BigInteger("2");
		while((num=in.readLine())!=null)
		{
			a = new BigInteger(num);
			if(a.compareTo(tres) < 0)
			{
				System.out.println(a);
			}else{
				System.out.println(a.add(negat).multiply(dos));
			}
		}
	}
}

