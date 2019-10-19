#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <cstdlib>
#include <map>
using namespace std;

typedef struct node // 节点
{
    float w;
    char data;
    node *lf = NULL, *rt = NULL;
} node;
bool operator<(node a, node b)
{
    if (a.w == b.w)
        return a.data > b.data;
    return a.w > b.w;
}

priority_queue<node> p; // 优先队列
map<char, string> path; //　保存０１信息
node root;


inline void createTable(node *root, string key);        //　创建Ｔａｂｌｅ
inline void printAlphaStream(string str);               //　输出字符流
inline void printZeroStream(string str);                //　输出０１流
inline void readData();                                 // 读取数据
inline char getValue(node *root, string str, int &idx); //　递归取值

int main()
{
    readData();
    createTable(&root, "");
    string str ;
    cin>>str;
    // printZeroStream(str);
     printAlphaStream(str);
}

void readData()
{
    char ch;
    float feq;
    while (cin >> ch >> feq,ch!='0')
    {
        node nd;
        nd.data = ch, nd.w = feq;
        p.push(nd);
    }
    while (p.size() != 1)
    {
        node *a = (node *)malloc(sizeof(node));
        node *b = (node *)malloc(sizeof(node));
        node *c = (node *)malloc(sizeof(node));
        memcpy(a, &p.top(), sizeof(node));
        p.pop();
        memcpy(b, &p.top(), sizeof(node));
        p.pop();
        c->w = a->w + b->w;
        // c->data = b->data;
        c->lf = a, c->rt = b;
        p.push(*c);
    }
    root = p.top();
}

void createTable(node *root, string key)
{

    if (root->lf != NULL)
        createTable(root->lf, key + "0");
    if (root->rt != NULL)
        createTable(root->rt, key + "1");
    if (root->lf == NULL && root->rt == NULL)
    {
        path[root->data] = key;

        cout << root->data << " " << root->w << " " << key << endl;
    }
}

char getValue(node *root, string str, int &idx)
{
    if (root->lf == NULL && root->rt == NULL)
    {
        return root->data;
    }
    if (str[idx] == '0')
    {
        return getValue(root->lf, str, ++idx);
    }
    if (str[idx] == '1')
    {
        return getValue(root->rt, str, ++idx);
    }
}

void printAlphaStream(string str)
{
    int idx = 0;

    while (idx < str.length())
        cout << getValue(&root, str, idx);
}

void printZeroStream(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        cout << path[str[i]];
    }
    cout << endl;
}