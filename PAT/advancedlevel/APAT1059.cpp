#include<stdio.h>
#include<vector>
#include<math.h>
/*
 http://pat.zju.edu.cn/contests/pat-a-practise/1059
 找出小于sqrt(l)的所有质数，分别用他们除l，得到答案。
 */
using namespace::std;
vector<long> primes;
vector<long> counts;
long l;
bool isPrime(long l) {
    for (long i = 0; i != primes.size(); ++ i)
        if (l%primes[i] == 0) return false;
    return true;
}

int main()
{
    scanf("%ld", &l);
    printf("%ld=", l);
    long s = sqrt(l);
    
    if (l == 2)
        printf("%d",2);
    else {
        for (long i = 2; i <= s; ++ i) {
            if (isPrime(i)) {
                int c = 0;
                primes.push_back(i);
                while(l%i == 0) {
                    l /= i;
                    ++ c;
                }
                counts.push_back(c);
            }
        }
    }
    
    bool flag = true;
    for (int i = 0; i != primes.size(); ++ i) {
        if (counts[i] != 0) {
            if (flag) flag = false;
            else printf("*");
            
            if (counts[i] == 1) printf("%ld", primes[i]);
            else printf("%ld^%ld", primes[i], counts[i]);
        }
    }
    if (flag) printf("%ld",l);
}