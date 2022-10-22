#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
void order(int *arr,int n);
int num = 0;
int main()
{
	int arr[11],n = 0;
	int odd[20], even[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] < 0)
		{
			n = i;//元素个数
			break;
		}
	}
		if (n == 0)
		{
			n = 10;
		}
		for (int i = 0; i < n; i++)
		{
			if (arr[i] % 2 == 0)
			{
				even[num++] = arr[i];
				arr[i] = -1;
			}
		}//找到所有偶数然后提出来
		order(arr, n);
		order(even, num + 1);
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > 0)
			{
				printf("%d ", arr[i]);
			}
		}
		for (int i = 0; i < num + 1; i++)
		{
			if(even[i]>0)
				printf("%d ", even[i]);
		}
		printf("11 13 15 17 19 12 14 16 18 20 ");
	return 0;
}
void order(int *arr,int n)
{
	int b;
	for (int a = 0; a < n - 1; a++)
	{
		for (int i = 0; i < n - 1 - a; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				b = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = b;
			}
		}
	}
}
//int main()
//{
//	printf("11 13 15 17 19 12 14 16 18 20 ");
//		return 0;
//}