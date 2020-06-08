#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#define INT_MAX 2147483647

using namespace std;
//最多500个点，加上管理中心
const int maxn = 501;
//每个点的最大容量，目标点，每个点的当前容量，用于dijkstra算法的距离向量,实际节点数,实际路径数
int Cmax, Destination, C[maxn], Distance[maxn], n, m;
//用于dijkstra算法的访问向量
bool visited[maxn];
//邻接表的节点定义
struct node {
    int v, e;//v表示邻接的点，e表示边权重
    node(int a, int b) :v(a), e(b) {}
};
//图的邻接表存储
vector<node> adj[maxn];
//最短路径存储
vector<int> pre[maxn];
//存储探寻时的路径和最终路径
vector<int> tmp, path;
//存储当前路径需要带去的车辆数和需要带回的车辆数
int carry = INT_MAX, takeBack = INT_MAX;

//最短路径就用dijkstra，如果要存储多条最短路径，就再借助一个邻接表(pre)
void Dijkstra(int start) {
    memset(visited, 0, sizeof(visited));
    fill(Distance, Distance + maxn, INT_MAX);
    Distance[start] = 0;
    while(1) {
        int min = INT_MAX, index = -1;
        for (int j = 0; j <= n; j++) {
            if (Distance[j] < min && visited[j] == false) {
                index = j;
                min = Distance[j];
            }
        }
        if (index == -1)
            return;
        visited[index] = true;
        for (int k = 0; k < adj[index].size(); k++) {
            int neighbor = adj[index][k].v;
            int edge = adj[index][k].e;
            if (visited[neighbor] == false) {
                if (Distance[index] + edge < Distance[neighbor]) {
                    Distance[neighbor] = Distance[index] + edge;
                    pre[neighbor].clear();
                    pre[neighbor].push_back(index);
                }
                else if (Distance[index] + edge == Distance[neighbor]) {
                    pre[neighbor].push_back(index);
                }
            }
        }

    }
}

//邻接表pre存储的是从出发点到每个点的最短路径，DFS遍历即可把每条最短路径探寻一遍
void DFS(int start) {
    if (start == 0) {
    //当探寻到出发点时，对该路径经行必要的检查，以满足特定题目的要求
    //基础结构不变，仍是push
        tmp.push_back(start);
        int thisCarry = 0, thisRemain = 0;
        for (int i = tmp.size() - 2; i >= 0; i--) {
            int diff = abs(Cmax / 2 - C[tmp[i]]);
            if (C[tmp[i]] < Cmax / 2) {
                if (thisRemain > diff) {
                    thisRemain -= diff;
                }
                else {
                    thisCarry += diff - thisRemain;
                    thisRemain = 0;
                }
            }
            else {
                thisRemain += diff;
            }
        }
        if (thisCarry < carry) {
            carry = thisCarry;
            takeBack = thisRemain;
            path = tmp;
        }
        if (thisCarry == carry && thisRemain < takeBack) {
            takeBack = thisRemain;
            path = tmp;
        }
        //基础结构不变，pop
        tmp.pop_back();
        return;
    }
    //探寻从目标点开始，主体结构是vector的push与pop
    tmp.push_back(start);
    for (int i = 0; i < pre[start].size(); i++) {
        DFS(pre[start][i]);
    }
    tmp.pop_back();
}

int main()
{
    scanf("%d%d%d%d", &Cmax, &n, &Destination, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    int v1, v2, edge;
    for (int i = 0 ; i < m; i++) {
        scanf("%d%d%d", &v1, &v2, &edge);
        adj[v1].push_back(node(v2, edge));
        adj[v2].push_back(node(v1, edge));
    }
    Dijkstra(0);
    DFS(Destination);
    cout << carry << ' ';
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0)
            cout << "->";
        else
            cout << ' ';
    }
    cout << takeBack << endl;
    return 0;
}
