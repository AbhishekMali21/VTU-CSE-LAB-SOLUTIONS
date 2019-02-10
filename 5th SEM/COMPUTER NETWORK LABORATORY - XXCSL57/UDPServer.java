import java.net.*;
import java.util.Scanner;

public class UDPServer {
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		DatagramSocket socket=new DatagramSocket();
		String msg=in.nextLine();
		
		byte code[]=msg.getBytes();
		InetAddress iAddress=InetAddress.getByName("127.0.0.1");
		DatagramPacket request=new DatagramPacket(code,code.length,iAddress,4000);
		socket.send(request);
		}
}