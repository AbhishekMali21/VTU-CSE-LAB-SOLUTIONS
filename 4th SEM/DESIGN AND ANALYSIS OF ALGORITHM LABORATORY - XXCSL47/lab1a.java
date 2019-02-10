class student 
{
	String USN,NAME,BRANCH,PH;
	student(String U,String N,String b,String p)
	{ 
		this.USN=U;
		this.NAME=N;
		this.BRANCH=b;
		this.PH=p;
	}
	
	void display()
	{
		System.out.println("\nEnter the students detail");
		System.out.println("USN="+this.USN);
		System.out.println("Name="+this.NAME);
		System.out.println("Branch="+this.BRANCH);
		System.out.println("Phone No="+this.PH);
	}
}
public class lab1a 
{
     public static void main(String[]args)
     {
    	 student ob1=new student("CS112","xxx","CSE","119");
    	 student ob2=new student("CS132","yyy","CSE","118");
    	 student ob3=new student("CS098","zzz","CSE","117");
    	 ob1.display();
    	 ob2.display();
    	 ob3.display();
     }
}
