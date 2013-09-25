#include<stdio.h>
#include<queue>
#include<stdlib.h>
using namespace std;

//注意，在17:00前开始服务的都可以得到结果，而不是17:00前结束的

struct person{
	int id, timeLeft; //还需要多长时间的处理，才能完成
};

int n, m, k, q;
int t[1001];
int result[1001];
queue< person> windows[21];//用queue模拟窗口

#define LIMIT 60*9

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= k; ++i)
		scanf("%d", &t[i]);

	for (int i = 1; i <= n; ++i){
		queue<person> pq;
		windows[i] = pq;
	}

	int timer = 0;//全局时钟
	int pLeft = k;//还没有进入黄线内的等待区域的人数
	while(true){
		if (timer < LIMIT)
			for (int i = 0; i != m; ++ i) { //按照哪个窗口最短，如果同等队列长度则选编号最小窗口的原则补进黄线外等候的人
				for (int j = 0; j != n; j ++)
					if (windows[j].size() == i && pLeft > 0) {
						person p;
						p.id = k - (pLeft--) + 1;
						p.timeLeft = t[p.id];
						windows[j].push(p); //将该人加入队列中。
					}
			}

		//找到各个窗口中，下一个离开窗口的时间
		int min = 0;
		for (int i = 0; i != n; ++i){
			if (windows[i].size() != 0) {
				if (min == 0 || min > windows[i].front().timeLeft)
					min = windows[i].front().timeLeft;
			}
		}

		timer += min;

		if (min == 0)//如果没有下一个离开窗口的时间，则表明所有人都服务完毕。
			break;

		for (int i = 0; i != n ; ++ i){
			if (windows[i].size() != 0){
				windows[i].front().timeLeft -= min;
				if (windows[i].front().timeLeft == 0){ //在timer时间点离开窗口的情况
					result[windows[i].front().id] = timer; //记录下这个人结束服务的时间
					windows[i].pop();

					if (timer >= LIMIT){ //大于LIMIT时间点之后，还没接受处理的人都被清空出队列，不做处理了。
						while(!windows[i].empty())
							windows[i].pop();
					}

				}
			}
		}
	}

	int query;
	for (int i = 0; i !=q; ++i){
		scanf("%d", &query);
		if (result[query] == 0)
			printf("Sorry\n");
		else{
			int tmp = result[query];
			printf("%02d:%02d\n", 8 + tmp/60, tmp%60);
		}
	}
	return 0;
}
