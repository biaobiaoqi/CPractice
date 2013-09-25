/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1047
 1.用priority_queue<student> courses[2501];，case4超时。换做vector试试.
 2.vector涉险350ms过关。【priority_queue的优势在于动态的增减时的一致性保持。但均摊的效率并不一定很高!】
 */
#include<stdio.h>
#include<vector>
#include <string.h>
#include<algorithm>
using namespace::std;

struct student{
    int hash;
};
char names[40001][5];

bool comp(student a, student b) {
    return strcmp(names[a.hash], names[b.hash]) < 0;
}

vector<student> courses[2501];

int main()
{
    int n, k, tmp, m;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i) {
        scanf("%s%d", names[i], &tmp);
        while (tmp -- ){
            scanf("%d", &m);
            courses[m].push_back({i});
        }
    }
    
    for (int i = 1; i <= k; i ++) {
        printf("%d %ld\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), comp);
        long size = courses[i].size();
        for (long j = 0; j != size; ++ j)
            printf("%s\n", names[courses[i][j].hash]);
    }
}