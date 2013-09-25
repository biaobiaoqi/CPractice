package biaobiaoqi.algorithm.oj.pat.basiclevel;

import java.util.Scanner;

/**
 * 读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。

输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112
 * 
 * 这个题目毫无技术含量。
 * @author biaobiaoqi
 *
 */
public class BLPAT1004 {
	
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		String highestName = null, highestNo = null;
		String lowestName = null, lowestNo = null;
		int highestScore = 0, lowestScore = 100, score;
		String name, no;
		for (int i = 0 ; i < n ; i ++) {
			name = cin.next();
			no = cin.next();
			score = cin.nextInt();
			if (score < lowestScore) {
				lowestScore = score;
				lowestName = name;
				lowestNo = no;
			}
			
			if (score > highestScore) {
				highestName = name;
				highestNo = no;
				highestScore = score;
			}
		}	

		System.out.println(highestName + " " + highestNo);
		System.out.println(lowestName + " " + lowestNo);
	}
}
