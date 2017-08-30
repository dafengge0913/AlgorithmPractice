#include <stdio.h>

#define N 5

void dfs(int matrix[N][N], int book[], int cur, int sum)
{
    printf("%d ", cur);
    book[cur] = 1;
    sum++;
    if (sum == N)
    {
        return;
    }
    int i;
    for (i = 0; i < N; i++)
    {
        if (book[i] != 1 && matrix[cur][i] != 0)
        {
            dfs(matrix, book, i, sum);
        }
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
    dfs(matrix, book, s, 0);
    printf("\n");
}
