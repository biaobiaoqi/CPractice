#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>

/*http://pat.zju.edu.cn/contests/pat-a-practise/1039
 这个题是个倒排索引的实现。不过在时间上卡的比较严。
 
 使用最简单的思路：map<string, vector<int> students倒排索引，在没有输出排序的课程列表时最后一个case已经超时；优化：将学生姓名的hash为int，减免了string的匹配过程，还是超时（map本身用红黑树实现，效率并不是特别高，还需要对每组数据进行排序），只能改变使用map的方式。
 
 最终AC的解法是：
 
 * 构建一个从学生编号字符串到int值的hash函数，在读入学生编号后，hash到int值做处理。
 * 不适用map结构，根据学生姓名的限制，设定一个`vector<int> st[26*26*26*10]`的数据结构，读入时直接倒排索引插入。

 */
using namespace::std;
vector<int> st[26*26*26*10];

int n,k;

int getHash(char name[]) {//这个hash方法很关键，用其他的hash方式出现了timeout
    return (name[0]-'A')*26*26*10+(name[1]-'A')*26*10+(name[2]-'A')*10+(name[3]-'0');
}

int main()
{
    scanf("%d%d", &n, &k);
    int course, num, hash;
    char name[5];
    
    for (int i = 1; i <= k; ++ i) {
        scanf("%d%d", &course, &num);
        for (int j = 1; j <= num; ++ j) {
            scanf("%s", name);
            hash = getHash(name);
            st[hash].push_back(course);
        }
    }
    
    for (int i = 1; i <= n; ++ i) {
        scanf("%s", name);
        hash = getHash(name);
        sort(st[hash].begin(), st[hash].end());
        printf("%s %ld", name, st[hash].size());
        for (int j = 0; j != st[hash].size(); ++ j)
            printf(" %d", st[hash][j]);
        printf("\n");
    }
}