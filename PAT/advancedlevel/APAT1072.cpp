#include <stdio.h>
#include <stdlib.h>
#define MAX 1015
#define INTMAX 2147483647
int edges[MAX][MAX], dist[MAX];
bool visited[MAX];
int n, m, k, d;

void dijkstra(int start) {
    for (int i = 0; i <= n + m; ++ i) {
        visited[i] = 0;
        dist[i] = INTMAX;
    }
    
    dist[start] = 0;
    while (true) {
        int cur_vertex = -1;
        int min = INTMAX;
        for (int i = 1; i <= n + m; ++ i) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                cur_vertex = i;
            }
        }
        if (cur_vertex == -1)
            break;
        visited[cur_vertex] = 1;
        
        for (int i = 1; i <= m + n; ++ i) {
            if (edges[cur_vertex][i] != 0 && i != cur_vertex) {
                if (dist[cur_vertex] + edges[cur_vertex][i] < dist[i]) {
                    dist[i] = dist[cur_vertex] + edges[cur_vertex][i];
                }
            }
        }
    }
}

int getInt(char *str) {
    if (str[0] == 'G') {
        return atoi(str + 1) + n;
    } else  {
        return atoi(str);
    }
}

int main(){
    scanf("%d%d%d%d", &n, &m, &k, &d);
    for (int i = 0; i != k; ++ i) {
        int v1, v2, distance;
        char str1[20], str2[20];
        scanf("%s%s%d", str1, str2, &distance);
        v1 = getInt(str1);
        v2 = getInt(str2);
        edges[v1][v2] = distance;
        edges[v2][v1] = distance;
    }
    
    int ret_sum = -1;
    int ret_min = -1;
    int gas_station = -1;
    for (int i = n + 1; i <= n + m; ++ i) {
        dijkstra(i);
        int min = INTMAX;
        int sum = 0;
        for (int j = 1; j <= n; ++ j) {
            sum += dist[j];
            if (dist[j] > d) {
                sum = 0;
                break;
            }
            if (dist[j] < min) {
                min = dist[j];
            }
        }
        
        if (sum != 0 && ((min > ret_min) || (min == ret_min && sum < ret_sum))) {
            ret_sum = sum;
            ret_min = min;
            gas_station = i - n;
        }
    }
    
    if (ret_sum != -1) {
        printf("G%d\n%.1lf %.1lf", gas_station, ret_min * 1.0, ret_sum * 1.0 / (n * 1.0));
    } else {
        printf("No Solution\n");
    }
    
    return 0;
}
