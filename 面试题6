#include <stdio.h>
#include <stack>
using namespace std;
int ar[1005], br[1005];
int n, flag;
stack<int> st;

void findP(int aleft, int aright, int bleft, int bright) {
	if (!flag || aleft > aright || bleft > bright)
		return;

	st.push(ar[aleft]);
	int i= -1;
	for (i = bleft; i <= bright; ++ i){
		if (br[i] == ar[aleft])
			break;
	}
	if (i > bright){
		flag = false;
		return;
	}

	findP(aleft + i - bleft + 1, aright, i + 1, bright);
	findP(aleft + 1, aleft + i - bleft, bleft, i - 1);
}

int main()
{
	//freopen("G:\in.txt", "r", stdin);
	while(scanf("%d", &n) != EOF) {
		flag = true;
		while(!st.empty())
			st.pop();
		for (int  i = 0; i < n; ++ i) {
			scanf("%d", &ar[i]);
		}
		for (int  i = 0; i < n; ++ i) {
			scanf("%d", &br[i]);
		}
		findP(0, n - 1, 0 , n - 1);

		if (flag) {
			while(!st.empty()) {
				printf("%d ", st.top());
				st.pop();
			}
			printf("\n");
		}else {
			printf("No\n");
		}
		
	}

	//fclose(stdin);
	return 0;
}
