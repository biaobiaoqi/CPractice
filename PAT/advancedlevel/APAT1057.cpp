/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1057
 思路：stack的操作容易实现，关键问题在于返回中位数。
 由于数据量在100000以内，可以采用桶排序的方式，结合树状数组，用二分定位到中位数。
*/
#include<stdio.h>
#define MAX 100005
#define LOWBIT(x) (x & -x)
int n, top, stack[MAX], tr[MAX];//stack数组用来模拟栈操作，tr树状数组用来对桶排序的数组做记录，方便查找中位数。

int sum(int x)
{
	int sum = 0;
	while(x){
		sum += tr[x];
		x -= LOWBIT(x);
	}
	return sum;
}

void update(int x, int delta)
{
	while(x < 100001) {
		tr[x] += delta;
		x += LOWBIT(x);
	}
}

int median()
{
	int high = 100000, low = 0, median;
	int target = (!(top%2)) ? top/2: (top + 1)/2;
	while(low <= high) {
		median = (high + low)/2;
		int leftSum = sum(median - 1);
		int medianSum = sum(median);
		if (leftSum < target && medianSum >=  target) //由于树状数组tr[x]记录的是x之前的所有值之和，即小于x的值的个数，做二分时的条件判断跟传统有些不同。
			break;
		else if (leftSum >= target)
			high = median;
		else
			low = median;
	}
	return median;
}

int main()
{
	scanf("%d", &n);
	char cmd[15];
	int value;
	while(n --) {
		scanf("%s", cmd);
		if (cmd[1] == 'o') { //pop
			if (top == 0)
				printf("Invalid\n");
			else {
				int value = stack[-- top];
				printf("%d\n", value);
				update(value, -1);
			}
		}else if (cmd[1] == 'u') { //push
			scanf("%d", &value);
			stack[top ++] = value;
			update(value, 1);
		}else { //peekmedian
			if (top == 0)
				printf("Invalid\n");
			else
				printf("%d\n", median());
		}
	}
	return 0;
}
