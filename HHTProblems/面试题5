#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int value;
	node *prev;
};

int main()
{
	//freopen("G:\in.txt", "r", stdin);
	int v;
	node *tail = (node *)malloc(sizeof(node));
	tail->prev = 0;
	while(scanf("%d", &v) != EOF) {
		if (v != -1) {
			node *n = (node *)malloc(sizeof(node));
			n->value = v;
			n->prev = tail->prev;
			tail->prev = n;
		} else {
			node *tmp = tail->prev;
			while(tmp != 0) {
				printf("%d\n", tmp->value);
				tmp = tmp->prev;
			}
		}
	}
	//fclose(stdin);
	return 0;
}
