import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client 
{
	public static void main(String[] args) throws Exception 
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter file name:");
		String fname=s.next();
		Socket socket=new Socket("127.0.0.1",4000);
	
		OutputStream osStream=socket.getOutputStream();
		PrintWriter pwWriter=new PrintWriter(osStream,true);
		pwWriter.println(fname);
		
		InputStream inStream=socket.getInputStream();
		Scanner sin=new Scanner(inStream);
		while(sin.hasNext())
			System.out.println(sin.next());
	}
}