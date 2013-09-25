package biaobiaoqi.algorithm.oj.pat.basiclevel;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


/**
 * 
 * 给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。

输出格式：每个测试用例的输出占一行，输出倒序后的句子。

输入样例：
Hello World Here I Come
输出样例：
Come I Here World Hello
 * 
 * 
 * 
 * 1.需要注意reader的用法。JAVA 的IO
 * 2.利用String的split方法，倒叙输出即可
 * @author biaobiaoqi
 *
 */
public class BLPAT1009 {
	public static void main(String args[]) throws IOException {
		BufferedReader bReader = new BufferedReader(new InputStreamReader(System.in));
		String string = bReader.readLine();
		String[] strings = string.split(" ");
		for (int i = strings.length - 1; i >= 0 ;  i --) {
			System.out.print(strings[i]);
			if (i != 0) {
				System.out.print(" ");
			}
		}
	}
}
