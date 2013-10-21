#include <stdio.h>
#define MAX 100005
int a[MAX];
int visit[MAX];

//实际上是dfs的思想，但是直接套用dfs的递归方式，性能上并不见得好。（当然PATOJ上测试发现两者都能AC-,-）
int getLink(int x) {
    int count = 0;
    while (!visit[x]) {
        visit[x] = 1;
        ++ count;
        x = a[x];
    }
    return count;
}

int main() {
    int n, res = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; ++ i) {
        int count = getLink(i);
        //如果count == 1，则这个数不需要移动，不用加到res上；
        //如果count == 0，表明这个位置的数已经被访问过，同样不用记入。
        if (count != 1 && count != 0) {
            //这里假定0并不在这个link中，于是，首先得将0swap到这个link中，
            //再进行swap操作，故需要+1. 作为举例，考虑数组{0, 2, 1}，
            //getLink(1)返回2，而swap过程首先需要将0和1（或者2）交换，
            //得到{2, 0, 1}，然后0和2交换得到{2, 1, 0}，再将0和2交换得到结果。
            res += count + 1;
        }
    }
    
    //之前的运算中，对每个link的计算，都假设0不在link中。如果0本身不处于0的位置，
    //那么至少有一次link的计算是包含有0的。而0在link中和不在link中，swap数目相差2.
    //于是给这种情况-2.
    if (a[0] != 0) {
        res -= 2;
    }
    
    printf("%d\n", res);
    
    return 0;
}
