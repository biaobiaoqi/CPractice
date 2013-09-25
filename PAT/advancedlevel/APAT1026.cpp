/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1026
 队列模拟题，单线程，循环里逐个处理人的逻辑。相比循环处理时间窗口的要简单。
 
 截止2013-7，PAT对1026的测试数据都有问题，即使如下case没通过，也能AC：
 
 2
 10:00:00 30 1
 12:00:00 30 1
 5 1
 3
 
 0 0 2 0 0
 */

#include<stdio.h>
#include<algorithm>
#include<deque>
#include<math.h>
using namespace std;
#define END 13*60*60
struct player{
    int arrive, process, vip;
} players[10005];
struct table{
    int servedCount, vip, available, id;
}tables[101];
int n, k, m;

bool operator <(const player &a, const player &b)
{
    return a.arrive < b.arrive;
}

bool operator <(const table &a, const table &b)
{
    if (a.available == b.available)
        return a.id < b.id;
    else
        return a.available < b.available;
}

bool sortt(const table &a, const table &b)
{
    return a.id < b.id;
}
int main()
{
    scanf( "%d", &n);
    for (int i = 1; i <= n; ++ i){
        int h, m, s, p, v;
        scanf( "%d:%d:%d %d %d", &h, &m, &s, &p, &v);
        players[i].arrive = (h - 8)*3600 + m*60 + s;
        players[i].process = p > 120 ? 120 : p;
        players[i].vip = v;
    }
    sort(players + 1, players + n + 1);
    
    scanf( "%d %d", &k, &m);
    for (int i = 1; i <= k; ++ i)
        tables[i].id = i;
    while(m --) {
        int tmp;
        scanf( "%d", &tmp);
        tables[tmp].vip = 1;
    }
    
    deque<int> waiting;
    int cur = 1;//players的处理游标，标记第一个未被处理的player。
    int timer = 0;
    while(timer < END) {
        while (cur <= n && players[cur].arrive <= timer)
            waiting.push_back(cur ++);
        
        if (waiting.size() == 0) {
            if (cur <= n && players[cur].arrive < END) {
                timer = players[cur].arrive;
                waiting.push_back(cur ++);
                for (int i = 1; i <= k; ++ i) {  //
                    if (tables[i].available < timer) {
                        tables[i].available = timer;
                    }
                }
                
                sort(tables + 1, tables + k);
            }else { //结束
                break;
            }
        }
        
        int vip = 0;
        for (int i = 0; i != waiting.size(); ++ i)
            if (players[waiting[i]].vip){
                vip = waiting[i];
                break;
            }
        
        int viptable = 0;
        if (vip)
            for (int i = 1; i <= k && tables[i].available == timer; ++ i)
                if (tables[i].vip) {
                    viptable = i;
                    break;
                }
        
        //确定当前循环所要处理的桌子和人员。
        int curp, curt;
        if (viptable) {
            curt = viptable;
            curp = vip;
            for (deque<int>::iterator it = waiting.begin(); it != waiting.end(); ++ it)
                if ((*it) == vip) {
                    waiting.erase(it);
                    break; //take care of this.
                }
        }else {
            curp = waiting.front();
            waiting.pop_front();
            curt = 1;
        }
        
        int art = players[curp].arrive;
        int stt = timer;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", art/3600 + 8, art/60%60, art%60, stt/3600 + 8, stt/60%60, stt%60, (int)floor((stt - art)/60.0 + 0.5)); //注意cell方法的使用
        
        tables[curt].servedCount ++;
        tables[curt].available = timer + players[curp].process * 60;
        
        //更改过处理后的table后，重新排序，准备下一轮的处理
        sort(tables + 1, tables + k + 1);
        timer = tables[1].available;
    }
    
    sort(tables + 1, tables + k + 1, sortt);
    for (int i = 1; i <= k; ++ i) {
        printf( "%d",tables[i].servedCount);
        if (i != k)
            printf( " ");
    }
    return 0;
}