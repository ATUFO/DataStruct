#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
void prim();

vector<int> edge[26]; // vector 实现的邻接表
int lowcost[26];
int weight[26][26];
int used[26];
int idex[26];
int n, m;

int main()
{
    char u, v;
    int w;

    memset(weight, INF, sizeof(weight));
    cin >> n >> m;

    while (cin >> u >> v)
    {
        if (u == '0')
            break;
        u -= 'a', v -= 'a';
        cin >> w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        weight[u][v] = weight[v][u] = w;
    }
    prim();
    return 0;
}

void prim()
{
    int minm, idx;
    lowcost[0] = INF;
    used[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lowcost[i] = weight[i][0];
        idex[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        minm = INF;
        for (int j = 1; j < n; j++)
        {
            if (!used[j] && lowcost[j] < minm)
            {
                minm = lowcost[j];
                idx = j;
            }
        }
        used[idx] = 1;
        cout << char((idex[idx] + 'a')) << " " << char((idx + 'a')) << " " << minm << endl;
        for (int v : edge[idx])
        {
            if (!used[v] && lowcost[v] > weight[v][idx])
            {
                lowcost[v] = weight[v][idx];
                idex[v] = idx;
            }
        }
    }
}