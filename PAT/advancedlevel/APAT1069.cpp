#include <iostream>
#include <algorithm>

using namespace std;

int getLarge(int x, char str[5]) {
    sprintf(str, "%04d", x);
    sort(str, str + 4);
    reverse(str, str + 4);
    return atoi(str);
}

int getSmall(int x, char str[5]) {
    sprintf(str, "%04d", x);
    sort(str, str + 4);
    return atoi(str);
}

int iter(int x)
{
    char large[5], small[5], result[5];
    large[4] = small[4] = result[4] = 0;
    int a = getLarge(x, large);
    int b = getSmall(x, small);
    sprintf(result, "%04d", a - b);
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
