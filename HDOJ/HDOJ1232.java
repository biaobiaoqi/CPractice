package biaobiaoqi.algorithm.oj.hdoj;

import java.util.Scanner;
//http://acm.hdu.edu.cn/showproblem.php?pid=1232
//union-find set ²¢²é¼¯
//406ms
//find optimization 406ms
//rank optimization 390ms

public class HDOJ1232 {
	public static int max = 1005;
	public static int[] root = new int[max];
	public static int[] rank = new int[max];
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int n,m;
		
		while((n = cin.nextInt()) != 0){
			//init
			for (int i = 1; i <= n; i++)
				root[i] = i;
			
			m = cin.nextInt();
			int s,e;
			while(m-- != 0){
				s = cin.nextInt();
				e = cin.nextInt();
				union(s, e);
			}
			
			int count = 0;
			for (int i = 1; i <= n; i ++)
				if (root[i] == i)
					count ++;
			
			System.out.println(count-1);
		}
	}
	
	public static void union(int a, int b){
		int ap = findP(a);
		int bp = findP(b);
		
		if (ap != bp){
			if (rank[a] == rank[b]){
				root[ap] = bp;
				rank[bp] ++;
			}
			else if (rank[a] < rank[b])
				root[ap] = bp;
			else
				root[bp] = ap;	
		}
	}
	
	public static int findP(int a){
		if (root[a] != a)
			root[a] = findP(root[a]);

		return root[a];
	}
}