/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1053
 dfs，剪枝，vector的qsort排序
 */
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace::std;
struct node{
    int weight;
    vector<node *> children;
} nodes[MAX];

bool compare(node *a, node *b)
{
    return a->weight > b->weight;
}

vector<int> results[MAX];
int n, m, s;

int dfs(node *node, long weight, int r) { //r stands for result index one can use.
    results[r].push_back(node->weight);
    
    if (node->children.size() == 0) { // leaf
        if (weight + node->weight == s)
            return r + 1;
        else {
            results[r].pop_back();
            return r;
        }
    }else {
        if (weight + node->weight > s) {
            results[r].pop_back();
            return r;
        }else {
            int oriR = r;
            vector<int> tmpResult = results[r];
            for (int i = 0; i != node->children.size(); ++ i) {
                results[r] = tmpResult;
                r = dfs(node->children[i], weight + node->weight, r);
            }
            if (oriR == r)
                results[r].pop_back();
            return r;
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i != n; ++ i)
        scanf("%d", &nodes[i].weight);
    
    for (int i = 0; i != m; ++ i) {
        int node, tmp, child;
        scanf("%d%d", &node, &tmp);
        while (tmp --) {
            scanf("%d", &child);
            nodes[node].children.push_back(&nodes[child]);
        }
        sort(nodes[node].children.begin(), nodes[node].children.end(), compare);
    }
    
    int result = dfs(&nodes[0], 0, 0);
    for (int i = 0; i != result; ++ i)
        for (int j = 0; j != results[i].size(); ++ j) {
            printf("%d", results[i][j]);
            if (j != results[i].size() - 1)
                printf(" ");
            else
                printf("\n");
        }
}