/*PTA的《基础编程题目集》6.6*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum(List L);

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for (i = 0; i < N; i++) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */
int FactorialSum(List L)
{
    int result = 0;
    int m = 0, n = 0;
    while(L)//条件判断要选好
    {
        m = L->Data;
        n = m;
        if (m == 0 || m == 1)
        {
            m = 1;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                m *= i;
            }//用循环算阶乘可以提高速率，其中要注意的是判断条件和被乘的数不能相同 不然就会导致一直计算
        }
        result += m;
        L = L->Next;
    } 
    return result;
}