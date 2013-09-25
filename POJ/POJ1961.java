package biaobiaoqi.algorithm.oj.poj;

import java.util.Scanner;

public class POJ1961 {
	public static int[] next = new int[1000002];
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int index = 0;
		int count ;
		String str ;
		while (cin.hasNext()) {
			index ++;
			count = cin.nextInt();
			str = cin.next();
			
			next(str);
			System.out.println("Test case #" + index);			
			for (int i = 2; i <= count; i ++) {
				
				
				if (i%(i - next[i - 1]) == 0 && next[i - 1] != 0)
					System.out.println(i + " " + i/(i - next[i - 1]));
			}
			System.out.println();
		}
	}
	
	public static void next(String str) {
		next[0] = 0;
		for (int i = 1, j = 0; i != str.length(); i++) {
			while (str.charAt(i) != str.charAt(j) && j > 0)
				j = next[j - 1];

			if (str.charAt(i) == str.charAt(j))
				j++;

			next[i] = j;
		}
	}
}
