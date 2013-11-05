#include <stdio.h>
#include <stdlib.h>
typedef  struct {
    int tons;
    double price;
    double unit_price;
} moon_cake;
moon_cake cakes[10001];

int compare(const void *a, const void *b) {
    moon_cake *aa = (moon_cake *)a;
    moon_cake *bb = (moon_cake *)b;
    if (bb->unit_price > aa->unit_price)
        return 1;
    else
        return -1;

}

int main(){
    int n, amount;
    scanf("%d %d", &n, &amount);
    for (int i = 0; i != n; ++ i)
        scanf("%d", &cakes[i].tons);
    for (int i = 0; i != n; ++ i) {
        scanf("%lf", &cakes[i].price);
        cakes[i].unit_price = cakes[i].price / cakes[i].tons;
    }
    
    qsort(cakes, n, sizeof(moon_cake), compare);
    //24, 20.83 22.2222
    
    double ret = 0;
    for (int i = 0; i != n && amount > 0 ; ++ i) {
        if (cakes[i].tons < amount) {
            ret += cakes[i].price;
            amount -= cakes[i].tons;
        } else {
            ret += cakes[i].price * amount / cakes[i].tons;
            amount = 0;
        }
    }
    
    printf("%.2lf", ret);
    
    return 0;
}
