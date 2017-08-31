#include <stdio.h>

#define N 5

// 广度优先搜索 遍历 图
void bfs(int matrix[N][N], int book[], int cur, int sum)
{
    int head = 0;
    int tail = 0;
    int queue[N];

    queue[tail] = cur;
    book[cur] = 1;
    tail++;

    int i, j;
    while (head < tail)
    {
        cur = queue[head];
        for (i = 0; i < N; i++)
        {
            if (book[i] != 1 && matrix[cur][i] != 0)
            {
                queue[tail] = i;
                tail++;
                book[i] = 1;
            }
            // 所有顶点都被访问过
            if (tail >= N)
            {
                for (j = 0; j < tail; j++)
                {
                    printf("%d ", queue[j]);
                }
                return;
            }
        }
        head++; // 扩展下一个节点
    }
}

void main()
{
    int edgeNum;
    printf("edge num:");
    scanf("%d", &edgeNum);

    int book[N];
    // 图的邻接矩阵
    int matrix[N][N];

    int i, j, a, b;

    for (i = 0; i < N; i++)
    {
        book[i] = 0;
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = 0;
        }
    }

    printf("input %d edges, the first node is 0, the last node is %d: \n", edgeNum, N - 1);
    for (i = 0; i < edgeNum; i++)
    {
        scanf("%d %d", &a, &b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }

    printf("Adjacency Matrix:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int s;
    printf("start from:");
    scanf("%d", &s);

    printf("result:");
    bfs(matrix, book, s, 0);
    printf("\n");
}
