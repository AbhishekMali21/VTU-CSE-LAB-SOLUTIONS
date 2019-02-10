import java.net.*;

public class UDPClient {
	public static void main(String[] args) throws Exception{
		DatagramSocket socket=new DatagramSocket(4000);
		byte data[]=new byte[1000];
		
		while(true) {
			DatagramPacket request=new DatagramPacket(data, data.length);
			socket.receive(request);
			String str=new String(request.getData());
			System.out.println(str);			
		}
	}
}