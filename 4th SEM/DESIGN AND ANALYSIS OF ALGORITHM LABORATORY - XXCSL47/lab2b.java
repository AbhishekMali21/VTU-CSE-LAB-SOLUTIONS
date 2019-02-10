import java.util.Scanner;
import java.util.StringTokenizer;
class Customer
{
	private String name;
	private String date_of_birth;
	public Customer(String name, String date_of_birth)
	{
		super();
		this.name = name;
		this.date_of_birth = date_of_birth;
	}
	public Customer ()
	{
	}
	
	public void readData(String name, String date_of_birth)
	{
		this.name = name;
		this.date_of_birth = date_of_birth;
	}
	public void displayData()
	{
		StringTokenizer st=new StringTokenizer(this.date_of_birth,"/");
		System.out.print(this.name+",");
		while(st.hasMoreTokens())
		{
			System.out.print(st.nextToken()+",");
		}
	}
}

public class lab2b
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		System.out.println("Enter Name :-");
		String name=in.nextLine();
		System.out.println("Enter Date of birth:-");
		String date=in.next();
		Customer customer=new Customer();
		customer.readData(name, date);
		customer.displayData();
	}
}