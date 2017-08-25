#include <stdio.h>

void quickSort(int *d, int left, int right)
{

	if (left >= right)
	{
		return;
	}

	int key = d[left];
	int i = left;
	int j = right;
	int t;

	while (i < j)
	{
		//从右面找到第一个比key小的数
		while (j > i && d[j] >= key)
		{
			j--;
		}
		//从左面找到第一个比key大的数
		while (i < j && d[i] <= key)
		{
			i++;
		}
		//交换这两个数
		t = d[i];
		d[i] = d[j];
		d[j] = t;
	}

	//i和j相遇 比key小的在i左面 比key大的在i右面 交换i和key
	t = d[i];
	d[i] = d[left];
	d[left] = t;

	//对i左面和右面的部分 再分别排序
	quickSort(d, left, i - 1);
	quickSort(d, i + 1, right);
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

	quickSort(data, 0, n - 1);

	for (i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}

}
