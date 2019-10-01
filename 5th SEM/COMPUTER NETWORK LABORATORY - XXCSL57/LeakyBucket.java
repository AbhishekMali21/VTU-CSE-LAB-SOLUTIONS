import java.util.Scanner;
public class LeakyBucket
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
int incoming, outgoing, buck_size, n, time = 1, store = 0;
System.out.println("Enter bucket size, outgoing rate and Number of Packets:");
buck_size = sc.nextInt();
outgoing = sc.nextInt();
n = sc.nextInt();
while (n != 0)
{
System.out.println("Enter the incoming packet size at Time:"+ (time++) );
incoming=sc.nextInt();
System.out.println("Incoming packet size is " + incoming);
if(incoming <= (buck_size - store))
{
store += incoming;
System.out.println("Bucket buffer size is " + store + " out of " + buck_size);
}
else
{
int pktdrop = incoming - (buck_size - store);
System.out.println("Dropped " + pktdrop + " no of packets");
System.out.println("Bucket buffer size is 10 out of "+buck_size);
store = buck_size;
}
store = store - outgoing;
System.out.println("After outgoing: "+ store +" packets left out of " + buck_size + " in buffer\n");
n--;
}
sc.close();
}
}
