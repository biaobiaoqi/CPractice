package biaobiaoqi.algorithm.oj.hdoj;

import java.util.Scanner;

public class HDOJ1867 {
	public static int[] next = new int[100005];

	public static void main(String[] atgs) {
		Scanner cin = new Scanner(System.in);
		String str1 = null;
		String str2 = null;
		while (cin.hasNext()) {
			str1 = cin.next();
			str2 = cin.next();

			int x = maxCommanLength(str1, str2);
			int y = maxCommanLength(str2, str1);

			if (x > y)
				printString(str1, str2, x);
			else if (x < y)
				printString(str2, str1, y);
			else if (str1.compareTo(str2) <= 0)
				printString(str1, str2, x);
			else
				printString(str2, str1, x);
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

	public static int maxCommanLength(String str1, String str2) {
		next(str2);

		int i, j;
		for (i = 0, j = 0; i != str1.length() && j != str2.length(); i++) {
			while (str1.charAt(i) != str2.charAt(j) && j > 0)
				j = next[j - 1];

			if (str1.charAt(i) == str2.charAt(j))
				j++;

		}

		if (i == str1.length())
			return j;

		return 0;
	}

	public static void printString(String str1, String str2, int maxCommanLength) {
		System.out.print(str1);
		for (int i = maxCommanLength; i != str2.length(); i++)
			System.out.print(str2.charAt(i));
		System.out.println();
	}
}