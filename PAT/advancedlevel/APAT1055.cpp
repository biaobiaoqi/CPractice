/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1055
 这道题时间限制比较严格。有两种思路：
 
 第一种思路：
 
 * 1.所有年龄做qsort()排序；
 * 2.分离到不同年轻的人的数组中，此时每个年龄中，都是排序好的。
 * 3.对于每个查询，从2中所得数组里进行归并排序，归并的每次比较过程，使用最大堆实现。
 
 第二种思路
 
 * 1.所有年龄做排序
 * 2.对排序好的年龄，每个年龄计数减掉100名之后的人。
 * 3.然后对待查询轮训过滤即可。
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace ::std;
#define MAX 100005
struct person{
    char name[10];
    int age;
    int value;
    
} p[MAX];

bool operator < (person const &a, person const &b )
{
    if (a.value == b.value) {
        if (a.age == b.age)
            return strcmp(a.name, b.name) < 0;
        else
            return a.age > b.age;
    } else
        return a.value < b.value;
}

bool compare( const person &a, const person &b)
{
    if (a.value == b.value) {
        if (a.age == b.age)
            return strcmp(a.name, b.name) < 0;
        else
            return a.age < b.age;
    } else
        return a.value > b.value;
}

vector<person> m[201];
int n, k;

int main()
{
    scanf( "%d %d", &n, &k);
    for (int i = 0; i != n; ++ i)
        scanf( "%s %d %d", p[i].name, &p[i].age, &p[i].value);
    sort(p, p + n, compare);
    for (int i = 0; i != n; ++ i)
        m[p[i].age].push_back(p[i]);
    
    int limit, start, end;
    int curs[201], cur;
    person result[101];
    for (int i = 1; i <= k; ++ i) {
        scanf( "%d %d %d", &limit, &start, &end);
        printf( "Case #%d:\n", i);
        priority_queue<person> q;
        memset(curs, 0, 201* sizeof(int ));
        cur = 0;
        
        for (int j = start; j <= end; ++ j)
            if (curs[j] < m[j].size())
                q.push(m[j][curs[j] ++]);
        while(!q.empty() && cur < limit) {
            person tmp = q.top();
            q.pop();
            result[cur ++] = tmp;
            
            if (curs[tmp.age] < m[tmp.age].size())
                q.push(m[tmp.age][curs[tmp.age] ++]);
            
        }
        if (cur == 0)
            printf( "None\n");
        else
            for (int i = 0; i != cur; ++ i)
                printf( "%s %d %d\n", result[i].name, result[i].age, result[i].value);
    }
    return 0;
}


/*
 12 4
 Zoe_Bill 35 2333
 Bob_Volk 24 5888
 Anny_Cin 95 999999
 Williams 30 -22
 Cindy 76 76000
 Alice 18 88888
 Joe_Mike 32 3222
 Michael 5 300000
 Rosemary 40 5888
 Dobby 24 5888
 Billy 24 5888
 Nobody 5 0
 4 15 45
 4 30 35
 4 5 95
 1 45 50
 
 
 Case #1:
 Alice 18 88888
 Billy 24 5888
 Bob_Volk 24 5888
 Dobby 24 5888
 Case #2:
 Joe_Mike 32 3222
 Zoe_Bill 35 2333
 Williams 30 -22
 Case #3:
 Anny_Cin 95 999999
 Michael 5 300000
 Alice 18 88888
 Cindy 76 76000
 Case #4:
 None
 
 */