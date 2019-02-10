import java.util.Scanner;
public class lab3a 
{
		lab3a()
		{
			int a,b;
			float c;
			Scanner sc=new Scanner(System.in);
			try
			{
				System.out.println("Enter the value of a");
				a=sc.nextInt();
				System.out.println("Enter the value of b");
				b=sc.nextInt();
				sc.close();
				if(b==0)
					throw new ArithmeticException(" Divide by Zero Error");
				c=(float)a/b;
				System.out.println("value of a is: "+a);
				System.out.println("value of b is: "+b);
				System.out.println("a/b is: "+c);
			}
			catch(ArithmeticException e)
			{
				System.out.println("ERROR..!!");
				e.printStackTrace();
			}
		}
		public static void main(String srgs[])
		{
			new lab3a();
		}
}