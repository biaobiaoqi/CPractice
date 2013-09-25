/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1018
 思路：
	1.使用Dijkstra找到最短路径，其中注意记录每个节点在最短路径中的【所有】前驱节点；
	2.使用DFS的方法，得到所有的最短路径。
	3.计算每条最短路径的带出和带回的车辆数量。
 注意：
	1.DFS的方法归纳所有最短路径的方法很common sense，需要掌握。
	2.Dij的堆优化debug了很久。
	3.推理证明Dij算法过程中，记录每个节点的带入和带出车辆数量是无法成立的：记n点带入车数量为send[n]，带回车数量为back[n]，证明经过n点的最短路径中下一个节点n+1的send[n+1]和back[n+1]是无法通过send[n] back[n]计算出的，举出反例。
	因此，必须先得出最短路径，再整体计算。
*/
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define MAX 501
#define MAX_INT ((unsigned)(-1) >> 1)

long long adj[MAX][MAX];
int visit[MAX], dist[MAX];
vector<int> prevlist[MAX];
int c[MAX];
int cm, n, dest, m;
vector<vector<int>> result;

void dijkstra()
{
	for (int i = 1; i <= n; ++ i)
		dist[i] = MAX_INT;
	typedef pair<int,int>pii;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push(make_pair(0, 0));

	while(!q.empty()) {
		int node = q.top().second;
		int curDist = q.top().first;
		q.pop();

		if (visit[node])
			continue;
		visit[node] = 1;

		for (int i = 0; i <= n; ++ i)
			if (adj[node][i] && i != node && !visit[i])
				if (dist[node] + adj[node][i] == dist[i])
					prevlist[i].push_back(node);
				else if (dist[node] + adj[node][i] < dist[i]) {
					dist[i] = dist[node] + adj[node][i];
					prevlist[i].clear();
					prevlist[i].push_back(node);
					q.push(make_pair(dist[i], i));
				}
	}
}

void dfs(int d, vector<int> *path)
{
	path->push_back(d);
	if (d == 0)
		result.push_back(*path);
	else
		for (int i = 0; i != prevlist[d].size(); ++ i)
			dfs(prevlist[d][i], path);
	path->pop_back();
}

int main()
{
	scanf("%d%d%d%d", &cm, &n, &dest, &m);
	for (int i = 1; i <= n; ++ i) scanf("%d", &c[i]);
	for (int i =0; i != m; ++ i) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		adj[a][b] = adj[b][a] = c;
	}

	dijkstra();
	vector<int> path;
	dfs(dest, &path);

	int minSend = MAX_INT, minBack = MAX_INT, min = MAX_INT;
	for (int j = 0; j != result.size(); ++ j){
		int send = 0, back = 0;
		for (int i = result[j].size() - 2; i >= 0 ; -- i) {
			int tmp = cm/2 - c[result[j][i]];
			if (tmp < 0)
				back += -tmp;
			else if (tmp > back) {
				send += tmp - back;
				back = 0;
			}else
				back -= tmp;
		}

		if (minSend > send ||( minSend == send && minBack > back)){
			minBack = back;
			minSend = send;
			min = j;
		}
	}

	printf("%d 0", minSend);
	for (int i =  result[min].size() - 2; i >= 0; -- i)
		printf("->%d",result[min][i]);
	printf(" %d\n", minBack);

	return 0;
}
