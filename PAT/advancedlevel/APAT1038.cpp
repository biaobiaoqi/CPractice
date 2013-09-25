/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1038
 容易简单的以为使用字典序排列拼接，实际上有一个特殊的拼接情况需要考虑。
 
 比如数据`32 321 3214`，这是按字典序排列的，但实际上这并不是最小的拼接方式，最小的拼接方式是：`321 3214 32`。
 
 比较这个实例，不难找到最小拼接的排序规律：
 
 * 1.两个字符串做比较时，如果其中一个字符串(a)是另一个字符串(ab)的前缀串，则需要将较长字符串(ab)除去前缀串的部分(b)与较短字符串(a)继续递归比较。比如，321和32，需要拿1和32做比较。又比如323和32比较，第一次拿3和32比较，第二次拿3和2按字典序比较。
 * 2.其他情况按字典序比较。
 
 另外需要注意的一个坑是：如果没有数据，则输出0。

 */

#include<stdio.h>
#include<stdlib.h>
#define MAX 10001
#define LEN 9
char m[MAX][LEN];
int n;
int compare(const void *aa, const void *bb)
{
    char * a = (char *)aa;
    char * b = (char *)bb;
    int ret = 0;
    
    while( !(ret = *a - *b) && *b && *a)
        ++a, ++b;
    
    if (*a && !*b)
        return compare(a, bb);
    if (*b && !*a)
        return compare(aa, b);
    else
        return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i != n; ++ i)
        scanf("%s", m[i]);
    
    qsort(m, n, sizeof(char)*9, compare);
    
    bool flag = true;
    for (int i = 0; i != n; ++ i){
        for (int j = 0; m[i][j] != 0; ++ j) {
            if (m[i][j] == '0' && flag)
                continue;
            else {
                flag = false;
                printf("%c", m[i][j]);
            }
        }
    }
    
    if (flag)
        printf("0\n");
    
    return 0;
}