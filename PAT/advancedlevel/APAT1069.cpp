#include <iostream>
#include <algorithm>

using namespace std;
void itoa(int x, char *ar) {
    int tmp = 1000;
    for (int i = 0; i != 4; ++ i) {
        ar[i] = x / tmp + '0';
        x -= x / tmp * tmp;
        tmp /= 10;
    }
}

int getLarge(int x, char large[5]) {
    itoa(x, large);
    sort(large, large + 4);
    reverse(large, large + 4);
    return atoi(large);
}

int getSmall(int x, char small[5]) {
    itoa(x, small);
    sort(small, small + 4);
    return atoi(small);
}

int iter(int x)
{
    char large[5], small[5], result[5];
    large[4] = small[4] = result[4] = 0;
    int a = getLarge(x, large);
    int b = getSmall(x, small);
    itoa(a - b, result);
    cout << large << " - " << small << " = " <<  result << endl;
    return a - b;
}

int main() {
    int n;
    cin >> n;

    do {
        n = iter(n);
    }while (n != 6174 && n != 0);

    return 0;
}
