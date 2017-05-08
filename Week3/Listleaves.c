#include <stdio.h>

#define MaxTree 10
#define Tree int
#define Null -1

struct TreeNode
{
	Tree Left;
	Tree Right;
}T[MaxTree];


Tree BuildTree(struct TreeNode T[]);


int main()
{
	Tree R;

	R = BuildTree(T);
	/*层序遍历的过程中打印输出根节点*/

	int queue[10]; /*使用队列实现层序遍历*/
	int head = 0, rear = 0;
	int flag = 0; /*输出格式中的空格标记，第一个输出前没有空格，flag=0，flag=1表示输出前有空格*/
	queue[rear++] = R;

	while(rear - head) {
		int h = queue[head++];
		if (T[h].Left == Null && T[h].Right == Null) {
			if(flag) 
				printf(" ");
			printf("%d", h);
			flag++;
		}

		if (T[h].Left != Null) {
			queue[rear++] = T[h].Left;
		}
		if (T[h].Right != Null) {
			queue[rear++] = T[h].Right;
		}
	}

	return 0;
}


Tree BuildTree(struct TreeNode T[])
{
	int N,Root,i;

	scanf("%d", &N);
	int check[N];
	char cl,cr;

	for(i=0; i<N; i++) check[i] = 0;

	for(i=0; i<N; i++) {
		scanf("\n%c %c", &cl, &cr);

		if (cl != '-') {
			T[i].Left = cl - '0';
			check[T[i].Left] = 1;
		}
		else { T[i].Left = Null; }

		if (cr !='-') {
			T[i].Right = cr - '0';
			check[T[i].Right] = 1;
		}
		else { T[i].Right = Null; }
	}

	for(i=0; i<N; i++) {
		if (!check[i]) break;
	}
		
	Root = i;

	return Root;
}


