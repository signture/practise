#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int chance, left, round;
char s[100], s2[100];

int guess()
{
	int chance = 7;
	int size = strlen(s);
	int size2 = strlen(s2);
	int left = size2;
	int record = -1;
	for (int i = 0; i < size2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (s[j] == s2[i])
			{
				s[j] = 0;
				left--;
				record++;
			}
		}
		if (record >=0)
		{
			chance++;
			record = -1;
		}
		chance--;
	}
	if (chance < 0)
		return 0;
	for (int i = 0; i < size; i++)
	{
		if (s[i] != 0)
		{
			break;
		}
		if(i == size-1)
		return 1;
	}
	if (chance == 0)
		return 0;
	return 2;
}


int main()
{
	while (1)
	{
		scanf("%d", &round);
		getchar();
		gets_s(s, 100);
		gets_s(s2, 100);
		switch (round)
		{
		case -1:
			return 0;
		default:
			printf("round%d\n", round);
			switch (guess())
			{
			case 1:
				printf("win\n");
				break;
			case 0:
				printf("lose\n");
				break;
			case 2:
				printf("give up\n");
				break;
			default:
				printf("error\n");
			}
		}
	}
	return 0;
}