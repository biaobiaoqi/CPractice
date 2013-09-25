/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1037
 简单模拟题。
*/
#include<stdio.h>
#include<algorithm>
using namespace::std;
#define MAX 100001
int c, p;
int coupons[MAX], prices[MAX];

int main()
{
	scanf("%d", &c);
	for (int i = 0; i != c; ++ i){
		scanf("%d", &coupons[i]);
	}
	sort(coupons, coupons + c);

	scanf("%d", &p);
	for (int i = 0; i != p; ++ i){
		scanf("%d", &prices[i]);
	}
	sort(prices, prices + p);
	long sum = 0;

	int posCI = c - 1, posPI = p - 1;
	while(posCI >= 0 && coupons[posCI] > 0 && prices[posPI] > 0){
		sum += coupons[posCI] * prices[posPI];
		-- posCI;
		-- posPI;
	}

	int negI = 0;
	while(negI < c && coupons[negI] < 0 && prices[negI] < 0){
		sum += prices[negI] * coupons[negI];
		++ negI;
	}

	printf("%ld\n", sum);
}
