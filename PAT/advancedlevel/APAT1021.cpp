#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

/**
 * Use union-find set to find components in the graph.
 * Choose one point, Using bfs to get one longest point, and from that point using bfs again to get all of the deepest roots.
 */
#define MAX 10005
int parent[MAX];
vector< int > adj[MAX];
int dist[MAX];
int n;

int find(int a)
{
	while(a != parent[a])
		a = parent[a];
	return a;
}

void merge(int a, int b)
{
	parent[a] = b;
}

int bfs(int start)
{
	for (int i = 1; i <= n; i++)
		dist[i] = -1;

	queue<int> q;
	q.push(start);
	dist[start] = 0;
	int maxDist = 0;

	while(q.size()){
		int current = q.front();
		for(int i = 0; i != adj[current].size(); i++){
			int tmp = adj[current][i];
			if (dist[tmp] < 0){
				q.push(tmp);
				dist[tmp] = dist[current] + 1;
				if (dist[tmp] > maxDist)
					maxDist = dist[tmp];
			}
		}
		q.pop();
	}
	return maxDist;
}

int main()
{
	scanf("%d",&n);
	int tmp = n + 1;
	while(tmp-- != 1)
		parent[tmp] = tmp;

	int a,b;
	for (int i = 1; i < n; ++i){
		scanf("%d%d",&a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		int ap = find(a);
		int bp = find(b);
		if (ap != bp)
			merge(ap, bp);
	}

	int count = 0;
	for (int i = 1; i <= n; ++ i)
		if (parent[i] == i)
			count ++;

	if (count > 1){
		printf("Error: %d components\n", count);
	}else {
		int max = bfs(1);
		int i;
		for (i = 1; i <= n; i++)
			if (dist[i] == max)
				break;
		max = bfs(i);
		dist[i] = max;
		for (i = 1; i <= n; ++i)
			if (dist[i] == max)
				printf("%d\n", i);

	}
	return 0;
}
