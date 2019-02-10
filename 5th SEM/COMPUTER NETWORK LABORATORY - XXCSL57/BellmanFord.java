import java.util.Scanner;

public class BellmanFord 
{
	int d[],noofvertices;
	public BellmanFord(int noofvertices) 
	{
		this.noofvertices = noofvertices;
		d = new int[noofvertices + 1];
	}
	
	public static void main(String[] args) 
	{
		int noofvertices,source;
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the number of vertices:");
		noofvertices = s.nextInt();
		
		int a[][] = new int[noofvertices + 1][noofvertices + 1];
		System.out.println("Enter the adjacency matrix:");
		for(int sn = 1; sn <= noofvertices; sn++) {
			for(int dn = 1; dn <= noofvertices; dn++) {
				a[sn][dn] = s.nextInt();
				if(sn == dn) {
					a[sn][dn] = 0;
					continue;
				}
				if(a[sn][dn] == 0)
					a[sn][dn] = 999;
			}
		}
		
		System.out.println("Enter src vertex:");		
		source = s.nextInt();
		BellmanFord b = new BellmanFord(noofvertices);
		b.bellmanFordeval(source,a);
	}
	
	private void bellmanFordeval(int source, int[][] a) 
	{
		for(int node = 1; node <= noofvertices; node++)
			d[node] = 999;
		d[source] = 0;
		
		for(int node = 1; node <= noofvertices-1; node++) 
			for(int sn=1; sn <= noofvertices; sn++)
				for(int dn = 1;dn <= noofvertices; dn++)
					if(a[sn][dn] != 999)
						if(d[dn] > d[sn]+a[sn][dn])
							d[dn] = d[sn]+a[sn][dn];
		
		for(int sn = 1; sn <= noofvertices; sn++)
			for(int dn = 1; dn <= noofvertices; dn++)
				if(d[dn] > d[sn]+a[sn][dn])
					System.out.println("-ve cycle");
		
		for(int vertex = 1; vertex <= noofvertices; vertex++)
			System.out.println( source+" to "+ vertex +" is "+ d[vertex] );
	}
}