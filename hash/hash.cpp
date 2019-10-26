#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct node
{
    int x;
    node *next;
} node;

int T, N, M;   // T hashTable size,N the module of hash ,M count of input
int *lenCount; //record the count of Length of each Link;
node *hashTable;

void insertToLink(node *head, int x);
void displayLink();
void displayASL();

int main()
{
    int x; // temp var
    cin >> T >> N >> M;
    hashTable = (node *)malloc(sizeof(node) * T);
    lenCount = (int *)malloc(sizeof(int) * T);
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        insertToLink(hashTable + x % N, x);
    }
    displayLink();
    displayASL();
}

void insertToLink(node *head, int x)
{
    node *ptr = head;
    ptr->x++;
    lenCount[ptr->x]++;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->x = x;
    while (ptr->next)
    {
        if (x < ptr->next->x)
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
            return;
        }
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void displayLink()
{
    for (int i = 0; i < T; i++)
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

void displayASL()
{
    cout << "ASL="
         << "(";
    int sum = 0;
    for (int i = 1; i < T; i++)
    {
        sum += lenCount[i] * i;
        if (lenCount[i])
            cout << i << (lenCount[i] > 1 ? ("*" + to_string(lenCount[i])) : "") << "+";
    }
    cout << "\b"
         << ")/" << M << "=" << (1.0 * sum / M) << endl;
}