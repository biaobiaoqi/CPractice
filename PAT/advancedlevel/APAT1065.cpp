#include <stdio.h>

int main() {
    long long a, b, c, tmp;
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++ i) {
        bool flag = false;
        scanf("%lld%lld%lld", &a, &b, &c);
        tmp = a + b;
        if (a < 0 && b < 0 && tmp >= 0 ) {
            flag = false;
        } else if (a > 0 && b > 0 && tmp <= 0) {
            flag = true;
        } else {
            flag = tmp > c;
        }
        
        printf("Case #%d: ", i);
        if (flag) printf("true\n");
        else printf("false\n");
    }
    return 0;
}
