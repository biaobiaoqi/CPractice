package biaobiaoqi.algorithm.oj.hdoj;

import java.util.Scanner;

public class HDOJ2203 {
	public static int[] next = new int[100005];

	public static void main(String[] atgs) {
		Scanner cin = new Scanner(System.in);
		String str = null;
		String dest = null;
		while (cin.hasNext()) {
			str = cin.next();
			dest = cin.next();
			if (dest.length() > str.length()) {
				System.out.println("no");
				continue;
			}
			str = str + str;
			kmpNext(dest);
			if (kmp(str, dest))
				System.out.println("yes");
			else
				System.out.println("no");
		}
	}

	public static void kmpNext(String str) {
		next[0] = 0;
		// i stands for index of string, j is temporary for particail match
		// values computing, at the beginning of each loop process, j is the
		// particial match value of former character .
		for (int i = 1, j = 0; i < str.length(); ++i) {
			while (j > 0 && str.charAt(i) != str.charAt(j))
				// This loop is to get a matching character recursively. Another
				// stop condition is when particial match value meets end.
				j = next[j - 1];// j will be recomputed in the recursion. Take
								// care that next[j-1] is the particial match
								// value of the first j characters substirng.

			if (str.charAt(i) == str.charAt(j)) // If not in this case, j must
												// meets end, equals to zero.
				++j;

			next[i] = j;
		}
	}

	public static boolean kmp(String str, String dest) {
		// i stands for index of str string, j stands for index in dest string.
		// At the beginning of each loop process, j is the new position of dest
		// taht should be compared.
		for (int i = 0, j = 0; i < str.length(); i++) {
			while (j > 0 && str.charAt(i) != dest.charAt(j))
				// This loop is to get a matching character recursively. Another
				// stop condition is when particial match value meets end.
				j = next[j - 1];// As i in str and j in dest is comparing,
								// recomputing of j should be in the former
								// character substring, which is next[j-1]

			if (str.charAt(i) == dest.charAt(j))
				j++;

			if (j == dest.length())
				return true;
		}
		return false;
	}
}