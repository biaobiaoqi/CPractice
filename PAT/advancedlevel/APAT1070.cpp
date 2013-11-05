#include <stdio.h>
#include <algorithm>
using namespace std;
typedef  struct {
    double tons;
    double price;
    double unit_price;
} moon_cake;
moon_cake cakes[1001];

bool compare(moon_cake a,moon_cake b) {
    return  a.unit_price > b.unit_price;
}

int main(){
    int n, amount;
    scanf("%d %d", &n, &amount);
    for (int i = 0; i != n; ++ i)
        scanf("%lf", &cakes[i].tons);
    for (int i = 0; i != n; ++ i) {
        scanf("%lf", &cakes[i].price);
        cakes[i].unit_price = cakes[i].price / cakes[i].tons;
    }
    
    sort(cakes, cakes + n, compare);
    
    double ret = 0;
    for (int i = 0; i != n && amount > 0 ; ++ i) {
        if (cakes[i].tons < amount) {
            ret += cakes[i].price;
            amount -= cakes[i].tons;
        } else {
            ret += (amount * 1.0/ cakes[i].tons) * cakes[i].price;
            amount = 0;
        }
    }
    printf("%.2lf", ret);
    
    return 0;
}
