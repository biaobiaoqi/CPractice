#include <stdio.h>
#include <stdlib.h>
#define max 1005

//http://pat.zju.edu.cn/contests/pat-a-practise/1013

typedef struct node{
	int vertex;
	struct node* next;
} Node;

int n, m, k;
Node nodes[max];
bool visited[max];

void dfs(int index) {
	visited[index] = true;
	Node node = nodes[index];
	while(node.next){
		node = *node.next;
		if (!visited[node.vertex])
			dfs(node.vertex);
	}
}

int main() {
	scanf("%d%d%d",	&n, &m, &k);
	for (int i = 0; i != m; i ++){
		int a, b;
		scanf("%d%d", &a, &b);
		Node *p = (Node *)malloc(sizeof(Node));
		p->vertex = b;
		p->next = nodes[a].next;
		nodes[a].next = p;
		p = (Node *)malloc(sizeof(Node));
		p->vertex = a;
		p->next = nodes[b].next;
		nodes[b].next = p;
	}
	for (int i = 0; i != k; i++){
		int c;
		scanf("%d",&c);
		for (int j = 1; j <= n; j ++)
			visited[j] = false;
		visited[c] = true;
		int count = -1;
		for (int j = 1; j <= n; j ++)
			if (!visited[j]){
				dfs(j);
				count ++;
			}
		printf("%d\n", count);
	}

	getchar();
	return 0;
}


