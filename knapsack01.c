#include <stdio.h>

#define N 5   // 物品数量
#define C 100 // 背包容量

int weight[N] = {20, 10, 30, 40, 50};
int value[N] = {30, 20, 35, 40, 100};

int f[N + 1][C + 1]; // 在有i个物品 容量为j 情况下的最优解

int max(int a, int b)
{
    return a > b ? a : b;
}

/**
 * 0 1 背包问题 动态规划
 */
void main()
{
    int i, j, n = 0;
    for (i = 0; i < N; i++)
    {
        n++; // 当前有几个物品
        for (j = 1; j <= C; j++)
        {
            if (weight[i] <= j)
                // 状态转移方程 在上一步的基础上 物品是否放入背包
                f[n][j] = max(f[n - 1][j], f[n - 1][j - weight[i]] + value[i]);
            else
                // 放不下
                f[n][j] = f[n - 1][j];

            //printf("%d -> %d = %d \n", n, j, f[n][j]);
        }
    }

    printf("result: %d \n", f[N][C]);
}
