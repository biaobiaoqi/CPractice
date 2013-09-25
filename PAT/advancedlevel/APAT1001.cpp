/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1001
 */

#include <stdio.h>

int main ()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int sum = a + b;
    if (sum < 0) {
        printf("-");
        sum = -sum;
    }else if (sum == 0) {
        printf("0");
    }
    
    char str[20];
    int count = 1, tmp;
    while (sum > 0) {
        tmp = sum %10;
        sum /= 10;
        str[count ++] = tmp + '0';
        if (sum != 0 && count % 4 == 0)
            str[count ++] = ',';
    }
    count --;
    
    for (int i = count; i >= 1; -- i)
        printf("%c", str[i]);
}