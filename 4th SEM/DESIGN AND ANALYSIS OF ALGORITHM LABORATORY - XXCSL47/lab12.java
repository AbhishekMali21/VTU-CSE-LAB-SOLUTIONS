import java.util.Scanner;
public class lab12
{
    static int x[] = new int[10];
    public static void main(String[] args) 
    {
     Scanner sc = new Scanner(System.in);
     int i,j,x1, x2, edges, n;
     int g[][] = new int[10][10];     
     System.out.print("Enter No. of Vertices: ");
     n = sc.nextInt();     
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=n;j++)
         {
             g[i][j] = 0;
             x[i]=0;
         }
     }
     
     System.out.print("Enter No. of Edges: ");
     edges = sc.nextInt();     
     for(i=1;i<=edges;i++)
     {
         System.out.println("Enter the Edge"+i+": ");
         x1 = sc.nextInt();
         x2 = sc.nextInt();         
         g[x1][x2] = 1;
         g[x2][x1] = 1;
     }     
     x[1] = 1;
     System.out.println("\nHamiltonian Cycle");
     hcycle(g,n,2);
    }
    
    public static void nextvalue(int g[][],int n,int k)
    {
        int j;
        while(true)
        {
            x[k] = (x[k] + 1) % (n+1);
            if(x[k] == 0)
                return;
            if(g[x[k-1]][x[k]] == 1)
            {
                for(j=1;j<=k-1;j++)
                {
                    if(x[j] == x[k] )
                        break;
                }
                if(j ==  k)
                {
                    if((k<n) || ((k==n) && (g[x[n]][x[1]] == 1)))
                        return;
                }
            }
        }
    }

    public static void hcycle(int g[][],int n, int k)
    {
        int i;
        while(true)
        {
            nextvalue(g,n,k);
            if(x[k]== 0)
                return;                   
            if(k==n)
            {
                for(i=1;i<=n;i++)
                    System.out.print(x[i]+"-->");
                System.out.println(x[1]+"\n");
            }
            else
                hcycle(g,n,k+1);
        }
    }
}