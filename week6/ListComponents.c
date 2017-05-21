#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 10
typedef int Vertex;


int G[MAXN][MAXN], Nv, Ne;
bool d_visited[MAXN];
bool b_visited[MAXN];

void BuildGraph() 
{
	int i, j, v1, v2;

	scanf("%d", &Nv);

	for (i = 0; i < Nv; i++)
		for (j = 0; j < Nv; j++)
			G[i][j] = 0;
	scanf("%d", &Ne);
	for (j = 0; j < Ne; j++)
	{
		scanf("%d %d", &v1, &v2);
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
}

void DFS(Vertex V)
{

	d_visited[V] = true;
	printf("%d ", V);

	for(int i = 0; i < Nv; i++) {
		if ((!d_visited[i]) && (G[V][i] == 1)) {
			DFS (i);
		}
	}

}


void BFS(Vertex V)
{
	int queue[MAXN];
	int head = 0, rear = 0;

	b_visited[V] = true;
	queue[rear++] = V;

	while(rear - head) {
		int h = queue[head++];

		printf("%d ", h);
		for (int i = 0; i< Nv; i++)
		{
			if ((!b_visited[i]) && (G[h][i] == 1)) {
				b_visited[i] = true;
				queue[rear++] = i;
			}
		}

	}
}


void ListDFSComponents() 
{
	for (int i = 0; i < Nv; i++) {
		if (!d_visited[i]) {
			printf("{ ");
			DFS(i);
			printf("}\n");
		}
	}

}

void ListBFSComponents()
{
	for (int i = 0; i < Nv; i++) {
		if (!b_visited[i]) {
			printf("{ ");
			BFS(i);
			printf("}\n");
		}
	}

}


int main()
{
	BuildGraph();
	ListDFSComponents();
	ListBFSComponents();

}
