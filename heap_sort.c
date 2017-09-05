#include <stdio.h>

// 调整大根堆
void heapAdjust(int data[], int i, int n)
{
	int child, t;

	// 当节点i有子节点时 继续执行
	while (2 * i + 1 < n)
	{
		// 计算出左子节点
		child = 2 * i + 1;
		// 如果存在右子节点 使用数值较大的子节点
		if (child < n - 1 && data[child + 1] > data[child])
		{
			child++;
		}

		// 如果子节点大于父节点 子节点上移
		if (data[i] < data[child])
		{
			t = data[i];
			data[i] = data[child];
			data[child] = t;
			i = child; // i更新为与之交换的子节点 继续调整
		}
		else
		{
			break; // 不需要继续调整
		}
	}
}

void heapSort(int data[], int n)
{
	// 构建堆
	int i, t;
	// 从最后一个非叶子节点(n/2-1)到根 依次向上调整
	for (i = n / 2 - 1; i >= 0; i--)
	{
		heapAdjust(data, i, n);
	}
	// 堆排序
	for (i = n - 1; i > 0; i--)
	{
		// 交换根节点（最大值）和当前的最后一个节点
		t = data[0];
		data[0] = data[i];
		data[i] = t;
		// 缩小堆范围 调整堆 保证根节点是最大值
		heapAdjust(data, 0, i);
	}
}

void main()
{
	int n;
	printf("Data size:");
	scanf("%d", &n);

	int data[n];
	int i;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	heapSort(data, n);

	for (i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
}
