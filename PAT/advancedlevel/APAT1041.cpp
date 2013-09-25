#include <stdio.h>

#define MAXCOUNT  100005
#define MAXNUM	  10005
int c[MAXNUM]={0};
int main()
{
    int n;
    
    scanf("%d",&n);
    int i, tmp;
    for(i=1;i<=n;i++){
        scanf("%d",&tmp);
        if (c[tmp] == 0) {
            c[tmp] = i;
        }else {
            c[tmp] = MAXCOUNT;
        }
    }

    int min = MAXCOUNT;
    int minIndex = 0;
    for(i=1;i<MAXNUM;i++){
        if(c[i]!=0 && c[i] < min ){
              min = c[i];
              minIndex = i;
        }
    }
    
    if (minIndex != 0) {
        printf("%d",minIndex);
    }else {
        printf("None");
    }
    return 0;
}

/*AnotherWay
#include <stdio.h>
#define MAXN 100005
#define MAXV 10005
int a[MAXN], f[MAXN], v[MAXV];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		if (v[a[i]] == 0) {
			v[a[i]] = i;
		} else {
			f[v[a[i]]] = 1;
			f[i] = 1;
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; ++ i) {
		if (f[i] == 0) {
			ret = i;
			break;
		}
	}
	
	if (ret > 0)
		printf("%d\n", a[ret]);
	else
		printf("None\n");

}

*/
