#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, k;
int ar[51][10001];

int getnc(int a, int b)
{
    int c1 = ar[a][0], c2 = ar[b][0];
    int i = 1, j = 1;
    int ret = 0;
    
    while(i <= c1 && j <= c2) {
        if (ar[a][i] < ar[b][j]) {
            i ++;
        } else if(ar[a][i] == ar[b][j]) {
            i ++;
            j ++;
            ret ++;
        } else {
            j ++;
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d", &m);
        ar[i][0] = m;
        for (int j = 1; j <= m; j ++) {
            scanf("%d", &ar[i][j]);
        }
        sort(ar[i]+1, ar[i]+m+1);
        int index = 1;
        
        for (int j = 1; j <= m; j ++) {
            ar[i][index ++] = ar[i][j];
            while (j <= m && ar[i][j] == ar[i][j + 1])
                j ++;
        }
        ar[i][0] = index - 1;
    }
    
    scanf("%d", &k);
    for (int i = 0; i != k; ++ i) {
        int a, b;
        scanf("%d %d", &a, &b);
        int nc = getnc(a,b);
        printf("%.1lf%%\n", nc *100.0/(ar[a][0] + ar[b][0] - nc));
    }
    
    return 0;
}

//Antoher way to solve this problem. Using stl set<int>
/*
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
set<int> ss[55];
int n,m,k;
int getnt(int a, int b) {
	int ret = 0;
	for (set<int>::iterator it = ss[a].begin(); it != ss[a].end(); it ++) {
		if (ss[b].find(*it) == ss[b].end()) 
			ret ++;
	}
	ret += ss[b].size();
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &m);
		int tmp;
		for (int j = 0; j != m; ++ j){
			scanf("%d", &tmp);
			ss[i].insert(tmp);
		}
	}

	scanf("%d", &k);
	int a,b;
	int nt;
	for (int i = 0; i != k ; ++ i) {
		scanf("%d %d", &a, &b);
		nt = getnt(a, b);
		printf("%02.1lf%%\n", (ss[a].size() + ss[b].size() - nt)*100.0/nt);
	}
}
*/
