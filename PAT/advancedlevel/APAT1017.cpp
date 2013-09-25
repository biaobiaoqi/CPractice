/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1017
 出错：1.建模的逻辑上有了漏洞；2.注意17：00以前开始接收的都能处理完；3.注意while的控制条件。
 
 */
#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

#define MAX      10001
#define START    8*60*60
#define END      17*60*60

struct person {
    int arrive, start, process;
} persons[MAX];

int compare(const void * a, const void * b) {
    person *aa = (person *) a;
    person *bb = (person *) b;
    return aa->arrive - bb->arrive;
}

bool operator<(person a, person b) //用于优先队列中的比较：某人结束处理的时间离当前时刻比较近，则往前排。
{
    return  a.start + a.process  > b.start + b.process;
}

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    int hour, minute, second;
    for (int i = 1; i <= n; ++i ) {
        scanf("%d:%d:%d %d", &hour, &minute, &second, &persons[i].process);
        persons[i].arrive = hour*60*60 + minute*60 + second;
        persons[i].process *= 60;
    }
    
    qsort(persons + 1, n, sizeof(person), compare);
    
    priority_queue<person> windows;
    int totalTime= 0;
    int count = 0;
    int index = 1;
    int timer = START;
    
    while (index <= n) {
        bool breakFlag = false;
        while (windows.size() < m){ //将黄线外等待的人放到窗口内来处理
            if (persons[index].arrive > END){
                breakFlag = true;
                break;
            }

            if (persons[index].arrive > timer) //如果当前时刻，下一个人还没有到，那么他的开始时间设置为到达的时刻
                persons[index].start = persons[index].arrive;
            else
                persons[index].start = timer;
            
            windows.push(persons[index]);
            
            totalTime += persons[index].start - persons[index].arrive;
            ++ count;
            ++ index;
        }

		if (breakFlag)//由于只需要计算等待时间，所以得到所有人的开始时间后，即可跳出循环，结束战斗
            break;
        
        person popPerson = windows.top();
        windows.pop();
        timer = popPerson.process + popPerson.start;
    }
    
    printf("%.1f\n", totalTime/(count*60.0));
    
    return 0;
}
