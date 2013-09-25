package biaobiaoqi.algorithm.oj.pat.basiclevel;

import java.util.Scanner;

/**
 * 
 * 让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4



 * 1.素数算法：http://www.cnblogs.com/luluping/archive/2010/03/03/1677552.html
 * 2.<=的边界值
 * 
 * @author biaobiaoqi
 *
 */
public class BLPAT1007 {
	public static Integer[] primes = new Integer[100000];
	public static int index = 0;
	
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		
		int count = 0;
		
		primes[index++] = 2;
		for (int i = 3 ; i <= n ; i ++) {
			if (isPrime(i)) {
				//test
				System.out.print(i + " ");
				
				if (primes[index - 1] - primes[index - 2] == 2) {
					count ++;
				}
			}
		}
			
		System.out.println(count);
		
	}
	
	
	public static boolean isPrime(int n) {
		int j;
		boolean result;
		for (j = 0; j < index && primes[j] * primes[j] <= n ; j ++) {
			if (n%primes[j] == 0) {
				break;
			}
		}
		
		if (j >= index || primes[j] * primes[j] > n) {
			primes[index ++] = n;
			result = true;
		}else {
			result = false;
		}
		
		return result;

	}
}
