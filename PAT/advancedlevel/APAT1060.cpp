/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1060
 简单题。
 注意：
 1.由于数字位数特别大，不能使用double等数据类型处理，而应该直接使用字符串。
 2.对于输入数据 3 0 0，输出应该为 YES 0.000*10^0
 
  用Xcode编译，Sample全过，但pat只过了一个case。原来字符串数组末尾没有赋值0，但Xcode给做了优化，于是在本地是能通过的。汗=。=
 */
#include<stdio.h>
#include<string.h>
#define MAX 110
struct result{
    char r[MAX];
    int k;
};

result getResult(char a[MAX], int n) {
    result r;
    
    int index = 0 ;
    int firstPos = -1; //the position of first valueable number in a.
    int pointPos = -1; //the position of point.
    int i;
    for (i = 0; a[i] != 0; ++ i) {
        if (a[i] == '.') { //get position of point
            pointPos = i;
            continue;
        }
        
        if (a[i] == '0' && firstPos == -1) //ignore header 0s.
            continue;
        else {
            if (firstPos == -1 )
                firstPos = i;
            if (index < n)
                r.r[index ++] = a[i];
        }
    }
    r.r[index] = 0;
    
    if (pointPos == -1)
        pointPos = i;
    if (pointPos - firstPos < 0)
        r.k  = pointPos - firstPos + 1;
    else
        r.k = pointPos - firstPos;
    
    if (index == 0) { //zero case.
        int i;
        for (i = 0; i != n; ++ i)
            r.r[i] = '0';
        r.r[i] = 0;
        r.k = 0;
    }
    
    return r;
}

int main()
{
    int n;
    char a[MAX], b[MAX];
    scanf("%d%s%s", &n, a, b);
    result r1 = getResult(a, n);
    result r2 = getResult(b, n);
    
    if (strcmp(r1.r, r2.r) == 0 && r1.k == r2.k)
        printf("YES 0.%s*10^%d\n", r1.r, r1.k);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", r1.r, r1.k, r2.r, r2.k);
    
}