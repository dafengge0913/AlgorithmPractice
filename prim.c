#include <stdio.h>

#define nodeNum 6
#define INFINITE 99999

int book[nodeNum] = {0}; // 标记节点是否已经加入生成树
int edge[nodeNum][nodeNum];
int dis[nodeNum];

// prim 最小生成树
void prim(int start)
{
    // 将节点加入生成树
    book[start] = 1; // 标记已经加入
    int count = 0, min, i, k, cur = start, sum = 0;
    count++;

    for (i = 0; i < nodeNum; i++)
    {
        dis[i] = edge[start][i];
    }

    while (count < nodeNum)
    {
        min = INFINITE;
        for (i = 0; i < nodeNum; i++)
        {
            if (book[i] == 0 && dis[i] < min)
            {
                // 找出离树最近的节点
                min = dis[i];
                cur = i;
            }
        }
        // 加入生成树
        book[cur] = 1;
        count++;
        sum += dis[cur];

        for (k = 0; k < nodeNum; k++)
        {
            // 以cur为中间点 更新生成树到非树节点的距离（松弛）
            if (book[k] == 0 && dis[k] > edge[cur][k])
            {
                dis[k] = edge[cur][k];
            }
        }
    }

    printf("Sum: %d", sum);
}

void main()
{
    int i, j;
    for (i = 0; i < nodeNum; i++)
    {
        for (j = 0; j < nodeNum; j++)
        {
            if (i == j)
                edge[i][j] = 0;
            else
                edge[i][j] = INFINITE;
        }
    }
    edge[1][3] = 11;
    edge[3][1] = 11;
    edge[2][4] = 13;
    edge[4][2] = 13;
    edge[3][5] = 3;
    edge[5][3] = 3;
    edge[4][5] = 4;
    edge[5][4] = 4;
    edge[1][2] = 6;
    edge[2][1] = 6;
    edge[3][4] = 7;
    edge[4][3] = 7;
    edge[0][1] = 1;
    edge[1][0] = 1;
    edge[2][3] = 9;
    edge[3][2] = 9;
    edge[0][2] = 2;
    edge[2][0] = 2;

    printf("Edges: \n");
    for (i = 0; i < nodeNum; i++)
    {
        for (j = 0; j < nodeNum; j++)
        {
            if (edge[i][j] != INFINITE && edge[i][j] != 0)
            {
                printf("%d %d %d \n", i, j, edge[i][j]);
            }
        }
    }
    prim(0);
}
