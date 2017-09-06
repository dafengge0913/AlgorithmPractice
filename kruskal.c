#include <stdio.h>

#define nodeNum 6
#define edgeNum 9

// 边
struct edge
{
    int a; // 节点
    int b; // 节点
    int w; // 权重
};

int r[nodeNum]; // 记录节点的祖先节点
struct edge es[edgeNum] = {
    {1, 3, 11},
    {2, 4, 13},
    {3, 5, 3},
    {4, 5, 4},
    {1, 2, 6},
    {3, 4, 7},
    {0, 1, 1},
    {2, 3, 9},
    {0, 2, 2}};

void quickSort(int left, int right)
{
    if (left >= right)
    {
        return;
    }

    struct edge key = es[left];
    int i = left;
    int j = right;
    struct edge t;

    while (i < j)
    {
        //从右面找到第一个比key小的数
        while (j > i && es[j].w >= key.w)
        {
            j--;
        }
        //从左面找到第一个比key大的数
        while (i < j && es[i].w <= key.w)
        {
            i++;
        }
        //交换这两个数
        t = es[i];
        es[i] = es[j];
        es[j] = t;
    }

    //i和j相遇 比key小的在i左面 比key大的在i右面 交换i和key
    t = es[i];
    es[i] = es[left];
    es[left] = t;

    //对i左面和右面的部分 再分别排序
    quickSort(left, i - 1);
    quickSort(i + 1, right);
}

// 递归查找 获取根节点
int getRoot(int x)
{
    if (r[x] != x)
    {
        r[x] = getRoot(r[x]); // 路径压缩 指向根节点
    }
    return r[x];
}

// 并查集合并
int merge(int a, int b)
{

    int t1 = getRoot(a);
    int t2 = getRoot(b);
    // 判断两个节点 是否在一棵树中（具有相同祖先）
    if (t1 != t2)
    {
        r[t2] = t1; // 加入生成树（设置相同的根）
        return 1;
    }
    return 0;
}

// kruskal 最小生成树
void kruskal()
{
    int i;
    int count = 0;
    struct edge result[nodeNum - 1];
    // 初始化 并查集
    for (i = 0; i < nodeNum; i++)
    {
        r[i] = i;
    }

    // 按照权重从小到大排序
    quickSort(0, edgeNum - 1);
    printf("After sort: \n");
    for (i = 0; i < edgeNum; i++)
    {
        printf("%d %d %d \n", es[i].a, es[i].b, es[i].w);
    }

    // 按照权重从小到大枚举每条边
    for (i = 0; i < edgeNum; i++)
    {
        // 判断两个节点是否已经连通
        if (merge(es[i].a, es[i].b))
        {
            // 如果没有连通 使用这条边
            result[count++] = es[i];
            if (count == nodeNum - 1)
            {
                break; // 所有的点 已经连通
            }
        }
    }

    printf("Result: \n");
    for (i = 0; i < count; i++)
    {
        printf("%d %d %d \n", result[i].a, result[i].b, result[i].w);
    }
}

void main()
{
    int i;
    printf("Edges: \n");
    for (i = 0; i < edgeNum; i++)
    {
        printf("%d %d %d \n", es[i].a, es[i].b, es[i].w);
    }
    kruskal();
}
