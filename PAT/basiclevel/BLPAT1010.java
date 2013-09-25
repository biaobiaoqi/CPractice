package biaobiaoqi.algorithm.oj.pat.basiclevel;

import java.util.Scanner;

/**
 * 设计函数求一元多项式的导数。

输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。

输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0


 * 题目略不严谨。当输入数据为空时，输出0 0
 * @author biaobiaoqi
 *
 */
public class BLPAT1010 {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		int aPre = 0, bPre = 0;
		boolean start = true;
		
		
		while (cin.hasNextInt())
        {	
			aPre = cin.nextInt();
			bPre = cin.nextInt();
			
			aPre *= bPre;
			bPre --;
			
			if (aPre == 0) {
				continue;
			}else {
				if (start) {
					start = false;
				}else {
					System.out.print(" ");
				}
				System.out.print(aPre + " " + bPre);
			}
        }
		
		if (start) {
			System.out.print("0 0");
		}


	}
}
