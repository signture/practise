#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int arr[10] = { 0 };
int copy[10] = { 0 };
int box[10] = { 0 };
int save[10][10] = { 0 };
//���д����ϣ���������
void dfs(int capacity,int deepth,int path,int turn)//capacity�������Ԫ��������deepth����Ԫ����ȡ���ٸ���Ҳ���Ƕ���������ȣ�
{
	//�����㷨Ҫ�õ��ݹ飬������Ҫ���õݹ��������
	if (path == deepth)//�ﵽ���ʱ
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
				if (capacity - turn < deepth - path)//��֦��������������Ԫ�ز�֧�ּ�����ϾͿ���ֱ���ж���
					break;
				box[i] = 1;
				copy[path] = arr[i];
				dfs(capacity, deepth, path + 1, i);//ȫ���оͰ�turn����β�ɾ���ͺ�
				box[i] = 0;
			}
		}
		return;
	}

	return;
}//���ǻ����㷨������д�������ǵ�deepth��capacity�ܽӽ�ʱ��ÿһ֧�����кܶ���
//�����㷨��ϰ




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