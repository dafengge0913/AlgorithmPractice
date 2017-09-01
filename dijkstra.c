#include <stdio.h>

#define N 6
#define INFINITE 99999

void dijkstra(int matrix[N][N], int book[], int start)
{
    int dis[N];
    int i, j;

    for (i = 0; i < N; i++)
    {
        dis[i] = matrix[start][i];
    }

    book[start] = 1;

    int min;
    int minNode;

    for (i = 0; i < N; i++)
    {
        min = INFINITE;
        minNode = INFINITE;
        // 找到距源点最近的点minNode
        for (j = 0; j < N; j++)
        {
            if (book[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                minNode = j;
            }
        }
        printf("min node:%d \n", minNode);
        if (minNode == INFINITE)
        {
            break;
        }
        book[minNode] = 1;
        for (j = 0; j < N; j++)
        {
            // 对每一条边 进行松弛
            if (matrix[minNode][j] < INFINITE && dis[j] > dis[minNode] + matrix[minNode][j])
            {
                // 如果通过minNode走 距离更近
                dis[j] = dis[minNode] + matrix[minNode][j];
            }
        }
    }

    printf("result:");
    for (i = 0; i < N; i++)
    {
        printf("%d ", dis[i]);
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

    int i, j, a, b, c;

    for (i = 0; i < N; i++)
    {
        book[i] = 0;
        for (j = 0; j < N; j++)
        {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INFINITE;
        }
    }

    printf("input %d edges, the first node is 0, the last node is %d: \n", edgeNum, N - 1);
    for (i = 0; i < edgeNum; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        matrix[a][b] = c; // 有向图
    }

    printf("Adjacency Matrix:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }

    int s;
    printf("start from:");
    scanf("%d", &s);
    dijkstra(matrix, book, s);
    
}
