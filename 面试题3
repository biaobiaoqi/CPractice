#include <stdio.h>
int ar[1001][1001];
int t, m, n;
bool res;
void find(int a, int b, int c, int d)
{
	if (res)
		return;
	if (a > c || b > d)
		return;

	int x = (a + c)/2;
	int y = (b + d)/2;
	
	if (ar[x][y] == t){
		res = true;
	} else if (ar[x][y] < t) {
		find(x + 1, y + 1, c, d);
		find(a, y + 1, x, d);
		find(x + 1, b, c, y);
	} else {
		find(a, b, x - 1, y - 1);
		find(a, y, x - 1, d);
		find(x, b, c, y - 1);
	}
}

int main()
{
	//freopen("G:\in.txt", "r", stdin);
	//freopen("G:\out.txt", "w", stdout);
	while(scanf("%d%d%d",&m, &n, &t) != EOF){
		for (int i = 1; i <=m; ++ i) {
			for (int j = 1; j <=n; ++ j){
				scanf("%d", &ar[i][j]);
			}
		}
		res = false;

		find(1, 1, m, n);

		if (res)
			printf("Yes\n");
		else
			printf("No\n");
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
