/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1058
 简单模拟题
 坑：题目交代最高位的区间为[0, 100000000]，但是没说如果两数相加超过这个值怎么办。需要将最高位的结果区间设定为20000000以上AC。
 */
#include<stdio.h>

int scale[4] = {0, 20000010, 17, 29};
int a[4];
int b[4];
int r[4];
int main()
{
    scanf("%d.%d.%d", &a[1], &a[2], &a[3]);
    scanf("%d.%d.%d", &b[1], &b[2], &b[3]);
    
    int carry = 0, tmp;
    
    for (int i = 3; i != 0; -- i) {
        tmp = a[i] + b[i] + carry;
        r[i] = tmp % scale[i];
        carry = tmp / scale[i];
    }
    
    printf("%d.%d.%d", r[1], r[2], r[3]);
}
