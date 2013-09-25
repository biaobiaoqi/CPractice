/*
http://pat.zju.edu.cn/contests/pat-a-practise/1040
 #####题意
 给定一个字符串，要求输出最长的连续对称子串的长度。比如给定字符串为`Is PAT&TAP symmetric?`，其中最长对称子串为`s PAT&TAP s`，所以输出结果11.
 
 #####分析
 
 这个题就是典型的Java实现timeout，而Cpp实现轻松过的类型。需要注意的一点是：有两种对称情况，一种形如`aba`，一种形如`abba`。

 
 */
#include <stdio.h>
char s[1001];
int main()
{
    gets(s); //读入一行
    int i = 0, offset = 0, max = 0;
    while (s[i] != 0 ) {
        while (s[i - offset] != 0 && s[i + offset] != 0 && s[i + offset] == s[i - offset])
            offset ++;
        
        if ((offset - 1)*2 + 1> max)
            max = (offset - 1)*2 + 1;
        
        offset = 0;
        ++ i;
    }
    i = 0;
    while (s[i] != 0) {
        while (s[i - offset] != 0 && s[i + offset + 1] != 0 && s[i - offset] == s[i + offset + 1])
            offset ++;
        
        if (offset*2 > max)
            max = offset*2;
        
        offset = 0;
        ++ i;
    }
    
    printf("%d\n", max);
    return 0;
}