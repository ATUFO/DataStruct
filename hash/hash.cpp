#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node
{
    int x;
    node *next;
} node;

int T, N, M;     // T hashTable size,N the module of hash ,M count of input
int *lenTable;   // 长度表，记录每一个链的长度
node *hashTable; // 哈希表

void insertToLink(node *head, int num); // 插入链表
void displayLink();                     // 输出链表
void displayASL();                      // 输出ASL

int main()
{
    int x; // temp var
    cin >> T >> N >> M;
    hashTable = (node *)malloc(sizeof(node) * T); // 初始化hash表
    lenTable = (int *)malloc(sizeof(int) * T);    // 初始化长度表
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        insertToLink(hashTable + x % N, x);
    }
    displayLink();
    displayASL();
}

void insertToLink(node *head, int num)
{
    node *ptr = head;

    ptr->x++; // 增长链表长度并记录
    lenTable[ptr->x]++;

    node *newNode = (node *)malloc(sizeof(node)); // 生成新节点
    newNode->x = num;

    while (ptr->next) // 如果待插入节点比ptr->next->x 小，那么插入。否则在56行插入至尾部
    {
        if (num < ptr->next->x)
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
            return;
        }
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void displayLink()
{
    for (int i = 0; i < T; i++) // 遍历每一条链
    {
        node *cur = hashTable + i;
        cout << i;
        cur = cur->next;
        while (cur)
        {
            cout << " -> " << cur->x;
            cur = cur->next;
        }
        cout << "^" << endl;
    }
}

void displayASL() // 计算及输出ASL ，控制格式稍微麻烦一点
{
    cout << "ASL="
         << "(";
    int sum = 0;
    for (int i = 1; i < T; i++)
    {
        sum += lenTable[i] * i;
        if (lenTable[i])
            cout << i
                 << (lenTable[i] > 1 ? ("*" + to_string(lenTable[i])) : "")
                 << "+";
    }
    cout << "\b"
         << ")/" << M << "=" << (1.0 * sum / M) << endl;
}