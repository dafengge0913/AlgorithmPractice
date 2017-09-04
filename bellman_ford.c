#include <stdio.h>

#define INFINITE 99999

/*
 * Bellman-Ford 支持负权边
 */
void main()
{
    int n, e, i, s;
    printf("Node number:");
    scanf("%d", &n);
    printf("Edge number:");
    scanf("%d", &e);

    int origin[n], dest[n], weight[n];
    int dis[n], book[n], queue[100];
    int head = 0, tail = 0;
    int first[n]; // first 保存节点origin[i]的第一条边的编号
    int next[e];  // next 保存编号为i的边的 下一条边的编号
    for (i = 0; i < n; i++)
    {
        dis[i] = INFINITE;
        book[i] = 0;
        first[i] = -1;
    }

    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d", &origin[i], &dest[i], &weight[i]);
        // 建立邻接表
        next[i] = first[origin[i]];
        first[origin[i]] = i;
    }

    printf("Start from:");
    scanf("%d", &s);

    // 起点入队
    queue[tail++] = s;
    book[s] = 1;
    dis[s] = 0;

    int cur;
    while (head < tail)
    {
        cur = first[queue[head]]; // 当前需要处理的队首节点
        while (cur != -1)         // 遍历节点的所有边
        {
            // 是否松弛成功
            if (dis[dest[cur]] > dis[origin[cur]] + weight[cur])
            {
                // 更新到dest[cur]的距离
                dis[dest[cur]] = dis[origin[cur]] + weight[cur];
                // 对最短路程发生变化的节点的相邻边 进行松弛
                if (book[dest[cur]] == 0)
                {
                    // 如果不在队列中 加入队列
                    queue[tail++] = dest[cur];
                    book[dest[cur]] = 1;
                }
            }
            cur = next[cur];
        }
        // 出队
        book[queue[head]] = 0;
        head++;
    }

    printf("Shortest distance: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", dis[i]);
    }
}
