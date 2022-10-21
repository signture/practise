#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct 
{
	int sp;
	int* data;
} Stack;
Stack* creatstack(int size);
void push(Stack*stack, int a);
int pop(Stack*stack);
int calculate(Stack *stack,char d[]);
char d[10]={'2','1','-','6','*','8','*','8','/'};
int arr[10];
int main()
{
	Stack* stack = creatstack(100);
	assert(calculate(stack,d) == 6);
	free(stack);
	return 0;
}

Stack* creatstack(int size)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->sp = 0;
	stack->data = (int*)malloc(sizeof(int) * size);
	return stack;
}

void push(Stack *stack, int a)
{
	stack->data[stack->sp++] = a;
}

int pop(Stack*stack)
{
	return stack->data[--stack->sp];
}

int calculate(Stack*stack,char d[])
{
	for (int i = 0; i < 10; i++)
	{
		int c, b;
		if (d[i] >='0' && d[i] <= '10')
		{
			arr[i] = d[i] - 48;
			push(stack, arr[i]);
		}
		switch (d[i])
		{
		case '-':
			c = pop(stack);
			b = pop(stack);
			push(stack, b -c);
			break;
		case '+':
			c = pop(stack);
			b = pop(stack);
			push(stack, b+c);
			break;
		case '*':
			c = pop(stack);
			b = pop(stack);
			push(stack, b*c);
			break;
		case '/':
			c = pop(stack);
			b = pop(stack);
			push(stack, b / c);
			break;
		default:
			break;
		}
	}
	return pop(stack);
}
