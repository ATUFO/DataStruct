#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node
{
    int x;
    node *prior;
    node *next;
} num;
typedef struct bigNum
{
    int len;
    bool positive = true;
    num *head;
    num *tail;
} bigNum;

void bigNum_plus(bigNum ba, bigNum bb, bigNum *bc);               //大数加
void bigNum_minus(bigNum ba, bigNum bb, bigNum *bc);              //大数减
void bigNum_slove(bigNum ba, bigNum bb, bigNum *bc, bool method); //大数计算，method-》true为加，
void bigNum_addTotail(bigNum *b, int x);                          //从左向右写数字
void bigNum_addToHead(bigNum *b, int x);                          //反上
bool bigNum_compareAbs(bigNum a, bigNum b);                       //大数绝对值比较
void bigNum_init(bigNum *b);                                      //大数初始化
void bigNum_destory(bigNum *a);                                   //大数销毁
void bigNum_print(bigNum x);                                      //输出大数
void readBigNum(bigNum *b);                                     //字符串转大数

int main()
{
    bigNum ba, bb, res; //操作数a, 操作数b，结果res

    readBigNum(&ba);

    char m; //m操作方法+/-
    m = getchar();
    getchar();

    readBigNum(&bb);

    bigNum_slove(ba, bb, &res, m == '+');
    bigNum_print(res);
    // bigNum_destory(&ba);
    // bigNum_destory(&bb);
    // bigNum_destory(&res);
}

void bigNum_slove(bigNum ba, bigNum bb, bigNum *bc, bool method)
{

    bigNum_init(bc);
    if (!method) //消除减号
        bb.positive = !bb.positive;
    if (bb.positive == ba.positive)
    {
        bc->positive = ba.positive;
        bigNum_plus(ba, bb, bc);
        return;
    }
    else
    {

        // cout<<ba.positive<<bb.positive<<endl;
        if (bigNum_compareAbs(ba, bb))
        {
            bc->positive = ba.positive;
            bigNum_minus(ba, bb, bc);
        }
        else
        {
            bc->positive = bb.positive;
            bigNum_minus(bb, ba, bc);
        }
        return;
    }
}
void bigNum_plus(bigNum ba, bigNum bb, bigNum *bc)
{

    int ext = 0, tem = 0; //ext进位数,tem当前位结果
    num *cura = ba.tail->prior;
    num *curb = bb.tail->prior;
    num *rhead = bc->head;
    num *rtail = bc->tail;
    while (cura != ba.head && curb != bb.head)
    {
        num *newNum = (num *)malloc(sizeof(num));
        tem = cura->x + curb->x + ext;
        ext = tem / 10;
        tem %= 10;
        newNum->x = tem;
        bigNum_addToHead(bc, tem);
        // cout << cura->x << " " << curb->x << " " << endl;
        cura = cura->prior, curb = curb->prior;
    }
    while (cura != ba.head)
    {
        num *newNum = (num *)malloc(sizeof(num));
        tem = cura->x + ext;
        ext = tem / 10;
        tem %= 10;
        newNum->x = tem;
        bigNum_addToHead(bc, tem);
        // cout << cura->x << endl;
        cura = cura->prior;
    }
    while (curb != bb.head)
    {
        num *newNum = (num *)malloc(sizeof(num));
        tem = curb->x + ext;
        ext = tem / 10;
        tem %= 10;
        bigNum_addToHead(bc, tem);
        curb = curb->prior;
    }
    if (ext)
    {
        num *newNum = (num *)malloc(sizeof(num));
        bigNum_addToHead(bc, ext);
    }
}
void bigNum_minus(bigNum ba, bigNum bb, bigNum *bc)
{
    int ext = 0, tem = 0; //借位树
    num *cura = ba.tail->prior;
    num *curb = bb.tail->prior;
    num *rhead = bc->head;
    num *rtail = bc->tail;
    while (cura != ba.head && curb != bb.head)
    {
        num *newNum = (num *)malloc(sizeof(num));
        tem = cura->x - curb->x - ext;
        if (tem < 0)
        {
            tem += 10;
            ext = 1;
        }
        else
            ext = 0;
        newNum->x = tem;
        bigNum_addToHead(bc, tem);
        // cout << cura->x << " " << curb->x << " " << endl;
        cura = cura->prior, curb = curb->prior;
    }
    while (cura != ba.head)
    {
        num *newNum = (num *)malloc(sizeof(num));
        tem = cura->x - curb->x - ext;
        if (tem < 0)
        {
            tem += 10;
            ext = 1;
        }
        else
            ext = 0;
        newNum->x = tem;
        bigNum_addToHead(bc, tem);
        // cout << cura->x << endl;
        cura = cura->prior;
    }
    while (curb != bb.head)
    {
        num *newNum = (num *)malloc(sizeof(num));
        tem = cura->x - curb->x - ext;
        if (tem < 0)
        {
            tem += 10;
            ext = 1;
        }
        else
            ext = 0;
        bigNum_addToHead(bc, tem);
        curb = curb->prior;
    }
    if (ext)
    {
        num *newNum = (num *)malloc(sizeof(num));
        bigNum_addToHead(bc, ext);
    }
}

bool bigNum_compareAbs(bigNum a, bigNum b)
{
    if (a.len == b.len)
    {
        num *cura = a.tail->prior;
        num *curb = b.tail->prior;
        while (cura != a.head && curb != b.head)
        {
            if (cura->x < curb->x)
                return false;
            cura = cura->prior, curb = curb->prior;
        }
        return true;
    }
    else
        return a.len > b.len;
}

void bigNum_init(bigNum *b)
{
    b->len = 0;
    b->head = (num *)malloc(sizeof(num));
    b->tail = (num *)malloc(sizeof(num));
    b->head->next = b->tail;
    b->head->prior = NULL;
    b->tail->prior = b->head;
    b->tail->next = NULL;
{
    num *head = b->head;
    num *newNum = (num *)malloc(sizeof(num));
    newNum->x = x;
    newNum->next = head->next;
    newNum->prior = head;
    head->next->prior = newNum;
    head->next = newNum;
}

void bigNum_addTotail(bigNum *b, int x)
{
    num *tail = b->tail;
    num *newNum = (num *)malloc(sizeof(num));
    newNum->prior = tail->prior;
    newNum->next = tail;
    tail->prior->next = newNum;
    tail->prior = newNum;
    newNum->x = x;
}

void bigNum_print(bigNum x)
{
    bool prefixx = false, zero = false;

    if (x.positive == false)
        cout << "-";

    num *p = x.head->next;
    while (p != x.tail)
    {
        int tem = (p->x);
        if (tem)
            prefixx = true;
        if (prefixx)
            cout << tem;
        p = p->next;
    }
    if (!prefixx)
        cout << "0";
    cout << endl;
}

void bigNum_destory(bigNum *a)
{
    num *p = a->head;
    while (p)
    {
        p = p->next;
        free(p);
    }
}

void readBigNum(bigNum *b)
{
    bigNum_init(b);
    char x;

    while (1)
    {
        x = getchar();
        if (x == 10)
            break;
        bigNum_addTotail(b, x - 48);
        b->len++;
    }
}
