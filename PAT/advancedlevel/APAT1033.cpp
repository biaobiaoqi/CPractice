/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1033
 用贪心算法，理清贪心算法的策略：
 1.从A加油站出发，在能行走的最大范围内，如果有比A站汽油更便宜的B站，则保证在A站点的【加油量刚好满足能到达B站点】；如果没有比A站汽油更便宜的站，则【加满车油】行走到范围内油价【最便宜的站上】。
 2.从A加油站出发，在能行走的最大范围内，如果没有其他站点，则A.dist + 一次最大的行走距离 为impossible情况下的最大站点。
 
 注意点：1.循环判定的结束条件不正确。这个需要特别注意验证设计的正确性。通过给stations数组增加了哨兵：stations[n]作为终点的站点表达，能够很容易的做结尾的判定。
 2.有个陷阱：如果没有距离为0的加油站，则无法行驶。
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 505
int n;
double cmax, d, davg;
struct station{
    double price;
    double dist;
} stations[MAX];

int compare(const void *a, const void *b)
{
    station *as = (station *)a;
    station *bs = (station *)b;
    return as->dist -bs->dist;
}

int main()
{
    scanf( "%lf%lf%lf%d", &cmax, &d, &davg, &n);
    for (int i = 0; i != n; ++ i)
        scanf( "%lf%lf", &stations[i].price, &stations[i].dist);
    stations[n].dist = d;
    qsort(stations, n, sizeof(station), compare);
    
    double gasLeft = 0;
    double sum = 0;
    bool possible = true ;
    int index = 0;
    
    if (stations[0].dist != 0) printf("The maximum travel distance = 0.00\n" );//This is easy to be ignored.
    else {
        while (true) {
            int nextDist = stations[index].dist + cmax * davg;
            if (nextDist < stations[index + 1].dist) { //impossible case: stations[n] has been assigned with the whole distance.
                possible = false;
                break;
            }else if (index == n  && nextDist >= d) {
                sum += (((d - stations[index].dist) * 1.0 / davg) - gasLeft) * stations[index].price;
                break;
            }
            
            int dest = index;
            for (int i = index + 1; i <= n && stations[i].dist <= nextDist; ++ i) { //loop in reachable distance.
                if (stations[i].price < stations[index].price) { //get the first station whose price is lower than current one(index).
                    dest = i;
                    break;
                }else if (dest == index || stations[i].price < stations[dest].price) //get the station whe lowest price which is higher than the current one (index)
                    dest = i;
            }
            
            if (stations[dest].price < stations[index].price) {
                //if leftGas is more than need, just minus the need amount.
                if ((stations[dest].dist - stations[index].dist) / davg >= gasLeft) {
                    sum += (((stations[dest].dist - stations[index].dist)/ davg) - gasLeft)* stations[index].price;
                    gasLeft = 0;
                }else {
                    gasLeft -= (stations[dest].dist - stations[index].dist) / davg;
                }
            }
            else {
                sum += (cmax - gasLeft) * stations[index].price;
                gasLeft = cmax - ((stations[dest].dist - stations[index].dist)  / davg);
            }
            index  = dest;
        }
        
        if (possible) printf("%.2lf" , sum);
        else printf("The maximum travel distance = %.2lf" , stations[index].dist + cmax*davg);
    }
}
