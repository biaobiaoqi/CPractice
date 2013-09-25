/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1045
 简单DP，最长递增子序列（LIS）.
*/

#include<stdio.h>
int n ,m, l;
int order[201];
int stripe[10001];
int length[10001];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int tmp;
		scanf("%d", &tmp);
		order[tmp] = i;
	}

	scanf("%d", &l);
	int index = 0;
	while(l --){
		int tmp;
		scanf("%d", &tmp);
		if (order[tmp] != 0 && tmp <= n)
			stripe[index++] = tmp;
	}

	int max = 0;
	if (index != 0){
		for (int i = 0; i != index; ++ i) {
			length[i] = 1; //Take care.
			for (int j = 0; j != i; ++ j)
				if (order[stripe[j]] <= order[stripe[i]] && length[j] + 1 > length[i])
					length[i] = length[j] + 1;

		}
		max = length[0];
		for (int i = 0; i!= index; ++ i)
			if (max < length[i]) max = length[i];
	}

	printf("%d\n",max);
}
