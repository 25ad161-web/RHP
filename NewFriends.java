import java.util.*;
public class new_frnds_atc {

    private static int find(int[] ldr,int node){
        if(ldr[node]!=node){
            ldr[node]=find(ldr,ldr[node]);
        }
        return ldr[node];
    }

    private static void join(int [] ldr, int rt,int  lt){
        ldr[find(ldr,rt)]=find(ldr,lt);

    }
    public static void main(String[] args) {
        Scanner sc= new Scanner (System.in);
        int N = sc.nextInt();
        int E= sc.nextInt();

        int [] ldr = new int[N+1];
        for (int node=0; node<=N;node++) ldr[node]=node;

        int [] edges = new int[E+1];
        for (int i=1;i<=E;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            edges[i]=a;
            join(ldr,a,b);
        }
        int [] gcnt= new int[N+1];
        int [] ecnt = new int[N+1];

        for(int node=1;node<=N;node++){
            gcnt[find(ldr,node)]++;
        }
       for(int c=1;c<=E;c++){
            ecnt[find(ldr,edges[c])]++;
        }
long ans=0;
        for(int node=1;node<=N;node++){
            long curr= ((long)gcnt[node]*(gcnt[node]-1)/2)-ecnt[node];
            ans+=curr;
        }

        System.out.println(ans);


        

        sc.close();
        
    }
}