#include <stdio.h>

int main()
{
	//freopen("G:\in.txt", "r", stdin);
	int n;
	while(scanf("%d", &n) != EOF){
		long long a = 0;
		long long b = 1;
		long long tmp;
		while(--n){
			tmp = b;
			b = a + b;
			a = tmp;
		}
		printf("%lld\n", b);
	}
	//fclose(stdin);
	return 0;
}


//变型：台阶
#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		long long pre = 1;
		long long cur = 1;
		long long tmp;
		while(--n) {
			tmp = cur;
			cur += pre;
			pre = tmp;
		}
		printf("%lld\n", cur);	
	}

	return 0;
}

//变形：变态台阶
#include <stdio.h>

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        long long v = 1;
        while (--n) {
            v *= 2;
        }
        printf("%lld\n", v);
    }
    return 0;
}

//变形题：矩形覆盖
#include <stdio.h>

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        long long prev = 1;
        long long cur = 1;
        long long tmp;
        while (--n){
            tmp = cur;
            cur += prev;
            prev = tmp;
        }
        printf("%lld\n", cur);
    }
}


