/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1029
 简单题，归并排序思想。
 注意变量类型，long的输入输出为%ld
*/
/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1029
 归并排序思想
*/
#include<stdio.h>
#define MAX 1000001
long a[MAX], b[MAX];

int main()
{
	int n, k;
	scanf("%d", &n);
	for (int i = 0; i != n; ++ i)
		scanf("%ld", &a[i]);
	scanf("%d", &k);
	for (int i = 0; i != k; ++ i)
		scanf("%ld", &b[i]);

	int m = (n + k + 1)/2;

	int i = 0, j = 0, index = 0;
	long result;
	while (i != n && j != k && index != m) {
		if (a[i] <= b[j]) {
			result = a[i];
			++ i, ++ index;
		}else {
			result = b[j];
			++ j, ++ index;
		}
	}

	while (i != n && index != m) {
		result = a[i];
		++ i; ++ index;
	}

	while (j != k && index != m) {
		result = b[j];
		++ j, ++ index;
	}

	printf("%ld\n", result);

	return 0;
}
