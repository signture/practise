#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int arr[10] = { 0 };
int copy[10] = { 0 };
int box[10] = { 0 };
int save[10][10] = { 0 };
//这个写个组合，不是排列
void dfs(int capacity,int deepth,int path,int turn)//capacity是数组的元素总数，deepth是在元素中取多少个（也就是二叉树的深度）
{
	//回溯算法要用到递归，所以先要设置递归结束条件
	if (path == deepth)//达到深度时
	{
		for (int i = 0; i < deepth; i++)
		{
			printf("%d ", copy[i]);
			save[turn][i] = copy[i];
		}
		printf("\n");
		return;
	}
	else
	{
		for (int i = turn; i < capacity; i++)
		{
			if (box[i] == 0)
			{
				if (capacity - turn < deepth - path)//剪枝操作，当数组里元素不支持继续组合就可以直接中断了
					break;
				box[i] = 1;
				copy[path] = arr[i];
				dfs(capacity, deepth, path + 1, i);//全排列就把turn这个形参删掉就好
				box[i] = 0;
			}
		}
		return;
	}

	return;
}//这是回溯算法的正常写法，但是当deepth与capacity很接近时，每一支都会有很多余
//回溯算法练习




int main()
{
	int capacity, deepth;
	printf("how many number in it?");
	scanf("%d", &capacity);
	printf("how many number do you want to use?");
	scanf("%d", &deepth);
	printf("waht are they?");
	for (int i = 0; i < capacity; i++)
	{
		scanf("%d", &arr[i]);
	}
	dfs(capacity, deepth,0,0);
	return 0;
}