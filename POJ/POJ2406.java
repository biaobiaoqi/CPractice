package biaobiaoqi.algorithm.oj.poj;

import java.util.Scanner;

public class POJ2406 {
	public static int[] next = new int[1000005];
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		String str = cin.next();
		
		while (!str.equals(".")) {
			kmpNext(str);
			int ans = str.length() - next[str.length() - 1];
			if (str.length() % ans == 0) 
				System.out.println(str.length() / ans);
			else 
				System.out.println(1);
			
			str = cin.next();
		}
	}

	public static void kmpNext(String str) {
		next[0] = 0;
		for (int i = 1, j = 0; i != str.length(); i ++) {
			while (j > 0 && str.charAt(i) != str.charAt(j)) 
				j = next[j - 1];
			if (str.charAt(i) == str.charAt(j))
				j ++;
			next[i] = j;
		}
	}
}
