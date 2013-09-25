#include <stdio.h>
#include <queue>

using namespace std;

int main(){
	int mice[1000];
	int rank[1000];
	int m,n;
	scanf("%d%d", &m, &n);
	
	for (int i = 0; i != m; ++i) 
		scanf("%d", &mice[i]);
	int tmp;
	queue<int> order;
	for (int i = 0; i != m; ++i) {
		scanf("%d", &tmp);
		order.push(tmp);
	}
	
	while(order.size()!=1){
		int gameCounts = order.size()/n + ((order.size()%n == 0)?0:1);
		int currentRank = gameCounts + 1;
		queue<int> tmpQueue;
		for (int i = 0; i < gameCounts; i ++){
			int max = -1;
			int maxIndex = -1;
			for (int j = i*n; j != i*n + n && order.size() != 0; j ++ ){
				int index = order.front();
				order.pop();
				if (max < mice[index]){
					max = mice[index];
					if (maxIndex != -1)
						rank[maxIndex] = currentRank;
					maxIndex = index;
				}else 
					rank[index] = currentRank;
			}
			
			tmpQueue.push(maxIndex);
		}
		order = tmpQueue;
	}
	
	rank[order.front()] = 1;
	
	for (int i = 0; i!= m; ++ i){
		printf("%d", rank[i]);
		if (i != m -1)
			printf(" ");
	}
		
	
	getchar();
	return 0;
}

