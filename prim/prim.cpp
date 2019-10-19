#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
void prim();

vector<int> edge[26]; // vector 实现的邻接表
int lowcost[26];      // 某点最小边的权值
int weight[26][26];   // 边的权值
int front[26];        // 记录索引点,即对于边 (u,v)来说,front[v]=u
int n, m, w;          // n顶点数,m边数
char u, v;            // w,u,v 为临时变量

int main()
{

    memset(weight, INF, sizeof(weight)); // 初始化,开始时最小花费和任意两点之间距离为INF
    memset(lowcost, INF, sizeof lowcost);

    cin >> n >> m;
    while (cin >> u >> v)
    {
        if (u == '0')
            break;
        u -= 'a', v -= 'a';
        cin >> w;
        edge[u].push_back(v); // 在邻接表中加入点
        edge[v].push_back(u);
        weight[u][v] = weight[v][u] = w;
    }

    prim();

    return 0;
}

void prim()
{

    lowcost[0] = 0;             //标记起点
    for (int i = 1; i < n; i++) // 处理起点与其它点的关系.
    {
        lowcost[i] = weight[i][0];
        front[i] = 0;
    }

    int minm, idx; // 临时变量
    for (int i = 1; i < n; i++)
    {
        minm = INF; // 从lowcost中寻找最小的边,并记录权值和标号
        for (int j = 1; j < n; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < minm)
            {
                minm = lowcost[j];
                idx = j;
            }
        }

        lowcost[idx] = 0; // 找到后做标记

        cout << char((front[idx] + 'a')) << " " << char((idx + 'a')) << " " << minm << endl;

        for (int v : edge[idx]) //对新加入的点周围的点遍历
        {

            // 如果没有使用过, 并且两点之间的权值之前的最小花费,那么最小花费就是该权值
            // 符合条件的要记录索引
            if (lowcost[v] != 0 && lowcost[v] > weight[v][idx])
            {
                lowcost[v] = weight[v][idx];
                front[v] = idx;
            }
        }
    }
}