/*PTA�ġ����������Ŀ����6.6*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* PtrToNode;
struct Node {
    int Data; /* �洢������� */
    PtrToNode Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

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

/* ��Ĵ��뽫��Ƕ������ */
int FactorialSum(List L)
{
    int result = 0;
    int m = 0, n = 0;
    while(L)//�����ж�Ҫѡ��
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
            }//��ѭ����׳˿���������ʣ�����Ҫע������ж������ͱ��˵���������ͬ ��Ȼ�ͻᵼ��һֱ����
        }
        result += m;
        L = L->Next;
    } 
    return result;
}