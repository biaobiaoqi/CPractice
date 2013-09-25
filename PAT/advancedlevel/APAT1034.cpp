/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1034
 用并查集并没有用dfs简洁。
*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace::std;

map<string, int> weights;
map<string, vector<string>> adj;
map<string, bool> visit;
map<string, int> results;
int n, threshold;
string head;
int curSize, curWeight;
void dfs(string str)
{
	visit[str] = true;
	++ curSize;
	curWeight += weights[str];
	if (weights[str] > weights[head])
		head = str;

	for (vector<string>::iterator it = adj[str].begin(); it != adj[str].end(); ++ it) {
		if (!visit[(*it)])
			dfs((*it));
	}
}

int main()
{
	cin >> n >> threshold;
	string str1, str2;
	int w;
	while(n -- ) {
		cin >> str1 >> str2 >> w;
		weights[str1] += w;
		weights[str2] += w;
		adj[str1].push_back(str2);
		adj[str2].push_back(str1);
		visit[str1] = false;
		visit[str2] = false;
	}
	for (map<string, bool>::iterator it = visit.begin(); it != visit.end(); ++ it) {
		if (!(*it).second) {
			curSize = 0;
			curWeight = 0;
			head = (*it).first;
			dfs((*it).first);

			if (curSize > 2 && curWeight > threshold*2)
				results[head] = curSize;
		}
	}

	cout << results.size() << endl;
	for (map<string, int>::iterator it = results.begin(); it != results.end(); ++ it)
		cout << (*it).first << " " << (*it).second << endl;

	return 0;
}
