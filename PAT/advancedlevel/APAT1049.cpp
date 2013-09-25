/*http://pat.zju.edu.cn/contests/pat-a-practise/1049
《编程之美》有讲解。一道侧重分析的题目。
最初分析的时候，往字节码的方向想开去了，走进了死胡同。
1.思路：结题思路充分展现了对数据内在关联的敏感，在推演的过程中发现特征：每个位置独立计算出现次数。可以细细品味。
2.技巧：这种很common sense的按位处理方式需要掌握。按照r*=10迭代。
3.注意：推算出的公式、规律，需要在边界值、不同情况下进行验证。
*/
#include<stdio.h>

int main()
{
	int n;
	long long sum = 0;
	scanf("%d", &n);

	int left, current, right;
	int r = 1;
	while (n/r) {
		//printf("test:%d sum:%ld\n",tmp, sum);
		left = n/(r*10);
		current = (n/r)%10;
		right  = n - (n/r)*r;

		//printf("left:%d current:%d right:%d\n", left, current, right);
		if (current == 1) {
			sum += right + 1 + left * r;
		}else if (current > 1 ) {
			sum += (left + 1)*r;
		}else {
			sum += left * r;
		}

		r *= 10;
	}

	printf("%ld\n", sum);
	//getchar();
}
