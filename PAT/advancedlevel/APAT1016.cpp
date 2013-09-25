#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1016
 模拟题
 1.题意陷阱：用户可能会无匹配项。这种情况不输出任何值。
 2.过程中犯错：复杂逻辑实现出错；输出格式出错。
 3.技能：用qsort的定制函数进行层次排序。
 
 */
struct record{
    int month;
    char name[21];
    int day;
    int hour;
    int minute;
    char onOff;
    int total;
} records[1000];
int n;
int fee[24];

int compare(const void *a, const void *b) //qsort is customed to support complicated sort!
{
    record *rA = (record *)a;
    record *rB = (record *)b;
    
    int result = strcmp(rA->name, rB->name);
    if(result < 0) return -1;
    else if (result > 0)return 1;
    else return rA->total - rB->total;
}

double charge(record start, record end)
{
    int sday, shour, sminute, eday, ehour, eminute;
    sday = start.day;
    shour = start.hour;
    sminute = start.minute;
    eday = end.day;
    ehour = end.hour;
    eminute = end.minute;
    
    double cost = 0;
    long time = 0;
    
    while(sday < eday)//先让天相等
    {
        time += (60 - sminute);
        cost += (60 - sminute) * fee[shour];
        sminute = 0; shour ++;//分化成0，时加1
        time += 60 * (24 - shour);
        while(shour < 24)
        {
            cost += 60 * fee[shour];
            shour ++;
        }
        shour = 0; sday ++;//时化成0，天加1
    }//天此时相等，时分为00:00
    while(shour < ehour)//再让时相等
    {
        time += (60 - sminute);
        cost += (60 - sminute) * fee[shour];
        sminute = 0; shour ++;
    }
    time += (eminute - sminute);
    cost += fee[ehour] * (eminute - sminute);
    
    printf( "%02d:%02d:%02d %02d:%02d:%02d %ld $%.2f\n" , start.day, start.hour, start.minute, end.day, end.hour, end.minute, time, cost/100);
    
    return cost;
}

int main()
{
    for (int i = 0; i != 24; ++ i)
        scanf( "%d", &fee[i]);
    scanf( "%d", &n);
    for (int i = 0; i != n; i ++){
        record r;
		char tmp[21];
        scanf( "%s %d:%d:%d:%d %s", r.name, &r.month, &r.day, &r.hour, &r.minute, tmp); //Take care of the r.name, instead of &r.name
        r.total = r.day*24*60 + r.hour*60 + r.minute;
		r.onOff = tmp[1];
        records[i] = r;
    }
    
    qsort(records, n, sizeof(record), compare);
    
    double amount = 0;
    bool hasOutputName = false ;
    bool waitForOn = true ;
    record onRecord;
    int month;
    char currentName[21];
    
    for (int i = 0; i != n; ++ i) {
        record r = records[i];
        if (i == 0 || strcmp(currentName, r.name) != 0) {
            if (i != 0 && hasOutputName) { //注意后面这个条件。
                printf( "Total amount: $%.2f\n", amount/100);
            }
            
            strcpy(currentName, r.name);
            month = r.month;
            hasOutputName = false;
            waitForOn = true;
            amount = 0;
            onRecord = r;
        }
        
        if (waitForOn ) {
            if (r.onOff == 'n'){
                waitForOn = false;
                onRecord = r;
            }
        } else {
            if (r.onOff == 'f') {
                if (!hasOutputName){
                    hasOutputName = true;
                    printf( "%s %02d\n", currentName, month);
                }
                amount += charge(onRecord, r);
                waitForOn = true;
            } else {
                onRecord = r;
            }
        }
    }
    
    if (hasOutputName)
        printf("Total amount: $%.2f", amount/100);
    
    return 0;
}
