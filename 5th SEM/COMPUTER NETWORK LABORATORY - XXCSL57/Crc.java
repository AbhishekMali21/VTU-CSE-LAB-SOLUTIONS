import java.util.Scanner;
public class Crc {

	static int n,m,msb,i,j,k,g[],d[],z[],r[];
	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);
		
		System.out.println("Enter no. of databits:");
		n=s.nextInt();
		
		System.out.println("Enter no. of generator bits:");
		m=s.nextInt();
		
		d=new int[m+n];
		g=new int[n];
		
		System.out.println("Enter databits:");
		for(i=0;i<n;i++)
			d[i]=s.nextInt();
		
		System.out.println("Enter generator bits:");
		for(i=0;i<m;i++)
			g[i]=s.nextInt();
		crcEval();
		
		System.out.println("\nThe code data is:");
		for(i=0;i<n+m-1;i++)
			System.out.println(d[i]);
		crcEval();
		boolean t=true;
		for(i=n;i<n+m-1;i++) {
			if(r[i]==1)
				t=false;
		}
		if(t)
			System.out.println("\nNo error");
		else
			System.out.println("Error");
	}
	
	private static void crcEval() 
	{
		r=new int[m+n];
		for(i=0;i<m;i++)
			r[i]=d[i];
		z=new int[m];
		for(i=0;i<n;i++) {
			k=0;
			msb=r[i];
			for(j=i;j<m+i;j++) {
				if(msb==0)
					r[j]=r[j]^z[k];
				else
					r[j]=r[j]^g[k];
				k++;
			}
			r[m+i]=d[m+i];		
		}
		//System.out.println("The code bits added are:");
		for(i=n;i<n+m-1;i++) {
			d[i]=r[i];
			//System.out.print(d[i]+" ");
		}
	}
}