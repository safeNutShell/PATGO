#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>

#define INT_MAX 2147483647

using namespace std;

//使用静态数组时通过所有测试用例，但是使用new申请动态数组时只通过部分
int G[501][501];
int dist[501] = { INT_MAX };
bool collected[501] = { false };
int diffPath[501] = { 0 };
int maxTeams[501] = { 0 };

int main()
{
    //分别代表顶点数、边数、原点、目标点
    int Nv, Ne, src, dst;
    int data[501];
    cin >> Nv >> Ne >> src >> dst;
    for (int i = 0; i < Nv; i++)
        cin >> data[i];
    //初始化邻接矩阵
    for (int i = 0; i < Nv; i++)
        for (int j = 0; j < Nv; j++) {
            if (i != j)
                G[i][j] = INT_MAX;
            else
                G[i][j] = 0;
        }
    //构建图，非连接的边其权重用无限大代替
    for (int i = 0; i < Ne; i++) {
        int v1, v2, weight;
        cin >> v1;
        cin >> v2;
        cin >> weight;
        G[v1][v2] = weight;
        G[v2][v1] = weight;
    }
    diffPath[src] = 1;
    maxTeams[src] = data[src];
    for (int i = 0; i < Nv; i++) {
        dist[i] = G[src][i];
    }

    dist[src] = 0;
    //collected[s] = true;
    //特殊需求，在判断diffPath的时候需要原点的邻接点判断能够与原点匹配，实现对邻接的那条边的计数

    //dijkstra
    while (1) {
        int minDist = INT_MAX;
        int minV;
        for (int i = 0; i < Nv; i++) {
            if (collected[i] == false && dist[i] < minDist) {
                minDist = dist[i];
                minV = i;
            }
        }
        collected[minV] = true;
        for (int i = 0; i < Nv; i++) {
            if (collected[i] == false && G[minV][i] < INT_MAX && dist[minV] + G[minV][i] < dist[i]) {
                dist[i] = dist[minV] + G[minV][i];
                diffPath[i] = diffPath[minV];
                maxTeams[i] = maxTeams[minV] + data[i];
            }
            else if (collected[i] == false && G[minV][i] < INT_MAX && dist[minV] + G[minV][i] == dist[i]) {
                diffPath[i] += diffPath[minV];
                maxTeams[i] = max(maxTeams[i], maxTeams[minV] + data[i]);
            }

        }
        if (minV == dst) break;
    }
    cout << diffPath[dst] << ' ' << maxTeams[dst] << endl;

    return 0;
}
