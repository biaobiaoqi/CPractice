#include<stdio.h>
#include<map>
#include<stdlib.h>
#include<string>

/*
 *WA�˺ܶ��Ρ�
 *��һ���ӣ�ͬ�ȷ��������Ρ�����1,2,2,4
 * */

using namespace std;

#define MAX 2001
typedef int (*pFunc)(const void *, const void *);
int m,n;

struct student {
	char id[8];
	int c, m, e, a;
} st[MAX];

struct finalRank {
	int rank;
	char item;
};

map<string,  finalRank> result;

int compareC(const void *a, const void *b)
{
	return ((student *)b)->c  - ((student *)a)->c;
}

int compareM(const void *a, const void *b)
{
	return ((student *)b)->m - ((student *)a)->m;
}

int compareE(const void *a, const void *b)
{
	return ((student *)b)->e - ((student *)a)->e;
}

int compareA(const void *a, const void *b)
{
	return ((student *)b)->a - ((student *)a)->a;
}

void rankProcess(pFunc pf, char item)
{
	int currentRank = 1;
	int delta = 0;
	for (int i = 0; i != n; ++i ){
		if (i != 0 && pf(&st[i - 1], &st[i]) != 0 ){
			currentRank += delta;
			delta = 1;
		}else
			delta ++;

		if (result[st[i].id].rank > currentRank){
			result[st[i].id].item = item;
			result[st[i].id].rank = currentRank;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i != n; ++i){
		scanf("%s%d%d%d", &st[i].id, &st[i].c, &st[i].m, &st[i].e);
		st[i].a = st[i].c + st[i].m + st[i].e;
		finalRank fr = {n + 2, 0};
		result[st[i].id] = fr;
	}

	qsort(st, n, sizeof(student), compareA);
	rankProcess(compareA, 'A');

	qsort(st, n, sizeof(student), compareC);
	rankProcess(compareC, 'C');

	qsort(st, n, sizeof(student), compareM);
	rankProcess(compareM, 'M');


	qsort(st, n, sizeof(student), compareE);
	rankProcess(compareE, 'E');

	char name[7];
	for (int i = 0; i != m; ++i ){
		scanf("%s", name );
		if (result.find(name) == result.end())
			printf("N/A\n");
		else
			printf("%d %c\n", result[name].rank, result[name].item);
	}

	return 0;
}
