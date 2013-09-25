#include <stdio.h>

int main()
{
	freopen("G:\in.txt", "r", stdin);
	int n;
	while(scanf("%d", &n) != EOF){
		int cur;
		int ret = -1;
		int first = -1;
		for (int i = 0; i != n; ++i ) {
			scanf("%d", &cur);
			if (first == -1) {
				first = cur;
			}
			if (first > cur && ret == -1){
				ret = cur;
			}
		}
		if (ret == -1)
			ret = first;
		printf("%d\n", ret);
	}
	fclose(stdin);
	return 0;
}
