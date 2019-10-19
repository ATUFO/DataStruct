#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int size = 100000;

typedef struct DulNode
{
    int data;
    int len;
    struct DulNode *prior;
    struct DulNode *next;
} DulNode, *DuLinkList;

void creatlist(DuLinkList L, char *str);

int main()
{
    char a1[size], b1[size], c;
    printf("请输入第一个整数：");
    scanf("%s", a1);
    //printf("%s",a1);
    printf("请输入符号：");
    scanf(" %c", &c);
    //getchar();
    //printf("%c",c);
    printf("请输入第二个整数：");
    scanf("%s", b1);
    DuLinkList a = (DuLinkList)malloc(sizeof(DulNode));
    DuLinkList b = (DuLinkList)malloc(sizeof(DulNode));
    creatlist(a, a1);
    creatlist(b, b1);
}

void creatlist(DuLinkList L, char *str)
{
    DuLinkList p, q;
    int i, LEN = 0;
    (L) = (DuLinkList)malloc(sizeof(DulNode));
    int len = strlen(str);
    (L)->prior = NULL;
    (L)->next = NULL;

    p = (L);
    for (i = len - 1; i >= 0; i--)
    {
        q = (DuLinkList)malloc(sizeof(DulNode));
        q->data = str[i] - '0';
        q->prior = p;
        p->next = q;
        p = q;
    }
    DuLinkList s = L->next;
    while (s)
    {
        printf("%d", s->data);
        s = s->next;
    }
    printf("\n");
}