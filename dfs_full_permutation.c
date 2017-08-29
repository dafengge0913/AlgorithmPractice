#include <stdio.h>

// depth first search 深度优先搜索
void dfs(int step, int n, int data[], int book[], int result[])
{
    int i;
    // 已经满足n个数
    if (step == n)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (book[i] == 0) // 第i个数据未被使用
        {
            result[step] = data[i];               // 作为当前步骤的值
            book[i] = 1;                          // 标记数据为已被使用
            dfs(step + 1, n, data, book, result); // 下一步骤
            book[i] = 0;                          // 取消使用标记
        }
    }
}

void main()
{
    int n;
    printf("Data size:");
    scanf("%d", &n);

    int i;
    int data[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    int book[n], result[n];
    for (i = 0; i < n; i++)
    {
        book[i] = 0;
    }

    printf("result: \n");
    dfs(0, n, data, book, result);
}
