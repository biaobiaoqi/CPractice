/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1011
 很水的题目。比较大小，输出结果即可。
*/
#include<stdio.h>

int main()
{
	double ret = 0.65, tmp;
	char hash[3] = {'W', 'T', 'L'};
	for (int i = 0; i != 3; ++i){
		double tmp, max = 0;
		int pos = -1;
		for (int j = 0; j != 3; ++j) {
			scanf("%lf", &tmp);
			if ((tmp - max) > 1e-6) {
				max = tmp;
				pos = j;
			}
		}
		ret *= max;
		printf("%c ", hash[pos]);
	}

	printf("%.2lf\n", 2*(ret - 1));

}
