/*http://pat.zju.edu.cn/contests/pat-a-practise/1025
 简单模拟题，用qsort分段排序搞定。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct testee {
	char id[14];
	int location;
	int score;
	int localRank;
} t[30001];
int k[301];
int compare(const void *a, const void *b)
{
	testee *ta = (testee *)a;
	testee *tb = (testee *)b;
	if (tb->score == ta->score) return strcmp(ta->id, tb->id);
	else return tb->score - ta->score;
}

int main()
{
	int n;
	scanf("%d", &n);
	int index = 1;
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &k[i]);
		for ( int j = 0; j != k[i]; ++ j, ++ index){
			scanf("%s %d", t[index].id, &t[index].score);
			t[index].location = i;
		}

		int base = index - k[i];
		qsort(t + base, k[i], sizeof(testee), compare);
		for (int j = base; j != base + k[i]; ++ j) {
			if (j == base)
				t[j].localRank = 1;
			else if (t[j].score == t[j - 1].score)
				t[j].localRank = t[j - 1].localRank;
			else
				t[j].localRank = j - base + 1;
		}
	}

	printf("%d\n",index - 1);
	qsort(t + 1, index - 1, sizeof(testee), compare);
	int finalRank = 0;
	t[0].score = -1;
	for (int i = 1; i != index; ++ i) {
		if (t[i].score != t[i - 1].score)
			finalRank = i;
		printf("%s %d %d %d\n", t[i].id, finalRank, t[i].location, t[i].localRank);
	}
}
