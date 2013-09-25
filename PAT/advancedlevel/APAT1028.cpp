#include<string.h>  
#include<iostream>  
#include<stdio.h>  
#include<stdlib.h>  
#include<algorithm> 

using namespace std;
/*
1.使用C++的sort方法，提供比较的模板即可。注意提供的compare方法与大小的对比。 
2.用Java实现读入数据就超时了。
3.自己实现的二分搜索超时了。sort方法的效率非常高。 
*/
#define MAX 100005
struct Node{
	char id[7];
	char name[9];
	int score;
};

Node a[MAX];

int cmp1(Node a, Node b){
	return strcmp(a.id, b.id) < 0;	
}

int cmp2(Node a, Node b) {
	int r = strcmp(a.name, b.name);
	if (r == 0) return cmp1(a, b);
	else return r < 0;
}

int cmp3 (Node a, Node b) {
	if (a.score == b.score) return cmp1(a, b);
	else return a.score < b.score ? 1 : 0;
}

int main()
{
	int n , c;
	scanf("%d%d", &n, &c);
	for (int i =0; i != n; ++i)
		scanf("%s%s%d", a[i].id, a[i].name, &a[i].score);

	switch (c) {
		case 1:
			sort(a, a+n, cmp1);		
			break;
		case 2:
			sort(a, a+n, cmp2);
			break;
		case 3:
			sort(a, a+n, cmp3);
			break;	
		default:
			break;
	}

	for (int i =0; i != n; ++i) printf("%s %s %d\n", a[i].id, a[i].name, a[i].score);
 
} 
