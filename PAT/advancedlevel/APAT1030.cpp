#include<stdio.h>
#include<stack>
/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1030
 Dijkstra的变形题。
 */
using namespace::std;
#define MAX     501
#define MAXDIS 260000
int n, m, s, d;
int e[MAX][MAX];
int c[MAX][MAX];
bool known[MAX];
int dist[MAX];
int cost[MAX];
int pre[MAX];
void initArray(int a[], int limit)
{
    while (limit > 0)
        a[-- limit] = MAXDIS;
}

void dijkstra(int s, int d)
{
    initArray(dist, n);
    initArray(cost, n);
    dist[s] = 0;
    cost[s] = 0;
    
    while(true) {
        int min = MAXDIS;
        int index = -1;
        for (int i = 0; i != n; ++ i)
            if ( !known[i] && min > dist[i] ) {
                index = i;
                min = dist[i];
            }
        
        if (index == -1 || index == d) break;
        else known[index] = known;
        
        for (int i = 0; i != n; ++ i) {
            if (!known[i] && e[index][i] && i != index) {
                if ((dist[i] > dist[index] + e[index][i])
                    || (dist[i] == dist[index] + e[index][i] && cost[i] > cost[index] + c[index][i])) {
                    dist[i] = dist[index] + e[index][i];
                    cost[i] = cost[index] + c[index][i];
                    pre[i] = index;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d",&n, &m, &s, &d);
    int v1, v2, dis, cos;
    for (int i = 0; i != m; ++ i) {
        scanf("%d%d%d%d", &v1, &v2, &dis, &cos);
        e[v1][v2] = dis;
        e[v2][v1] = dis;
        c[v1][v2] = cos;
        c[v2][v1] = cos;
    }
    
    dijkstra(s, d);
    stack<int> st;
    int tmp = d;
    st.push(tmp);
    while(tmp != s) {
        st.push(pre[tmp]);
        tmp = pre[tmp];
    }
    
    bool flag = true;
    
    while(!st.empty()) {
        if (flag) flag = false;
        else printf(" ");
        
        printf("%d", st.top());
        st.pop();
    }
    printf(" %d %d", dist[d], cost[d]);
}