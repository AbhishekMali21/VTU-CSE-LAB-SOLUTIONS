import java.util.Scanner;
public class lab1b 
{
	final int max=5;
	int s[]=new int[max];
	int top=-1;
	void push(int ele)
	{
		if(top>=max-1)
			System.out.println("stack overflow");
		else
			s[++top]=ele;
	}
	int pop()
	{
		int z=0;
		if(top==-1)
			System.out.println("stack underflow");
		else
			z=s[top--];
		return z;
	}
	void display()
	{
		if(top==-1)
			System.out.println("stack empty");
		else
		{
			for(int i=top;i>-1;i--)
			System.out.println(s[i]+" ");
		}
	}
	
public static void main(String args[])
{
	int q=1;
	lab1b m = new lab1b();
	System.out.println("program to perform stack operations");
	Scanner sc=new Scanner(System.in);
	while(q!=0)
	{
		System.out.println("1. push 2.pop 3. display 4.Exit");
		System.out.println("Enter your choice");
		int ch=sc.nextInt();
		switch(ch)
		{
			case 1:
				System.out.println("enter the element to be pushed");
				int ele=sc.nextInt();
				m.push(ele);
				break;
			case 2:
				int popele;
				popele=m.pop();
				System.out.println("the poped element is");
				System.out.println(popele+" ");
				break;
			case 3:
				System.out.println("elements in the stack are");
				m.display();
				break;
			case 4:
				q=0;
		}
	}
}
}