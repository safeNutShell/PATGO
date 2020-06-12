#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#define INT_MAX 2147483647

using namespace std;
const int maxn = 500;
int n;
struct node {
    int neighbor;
    int distance;
    int cost;
    node(int a, int b, int c) {
        neighbor = a;
        distance = b;
        cost = c;
    }
};
//用于dijksrta
bool visited[maxn] = { false };
int Distance[maxn];
//计算总金额
int minCost = INT_MAX;
//原图的邻接表
vector<node> adj[maxn];
//最短路径图的邻接表
vector<int> pre[maxn];
//用于记录路径
vector<int> tmp, path;

//首先这是一个最短路径问题，就需要从确定出发点开始执行dijkstra算法
void dijkstra(int start) {
    //先初始化，从start点开始
    memset(visited, false, sizeof(visited));
    fill(Distance, Distance + maxn, INT_MAX);
    Distance[start] = 0;
    //循环
    while (1) {
         //先从剩下未遍历的点中找一个到当前visited集合距离最小的
        int min = INT_MAX, index = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false && Distance[i] < min) {
                min = Distance[i];
                index = i;
            }
        }
        //如果没找到跳出循环（已经全部完成）
        if (index == -1)
            return;
        //标记当前点
        visited[index] = true;
        //遍历当前点，对尚未visited的点更新最短距离
        for (int i = 0; i < adj[index].size(); i++) {
            int neighbor = adj[index][i].neighbor;
            int distance = adj[index][i].distance;
            if (visited[neighbor] == false) {
                if (Distance[index] + distance < Distance[neighbor]) {
                    Distance[neighbor] = Distance[index] + distance;
                    pre[neighbor].clear();
                    pre[neighbor].push_back(index);
                }
                else if (Distance[index] + distance == Distance[neighbor]) {
                    pre[neighbor].push_back(index);
                }
            }
        }
    }
}

//由于最短路径不唯一，需要用邻接表pre存储所有的最短路径
//此时邻接表pre存储的其实是一个target最短路径的子图
//用DFS遍历图，在过程中根据其他判据决定使用哪条路径
void DFS(int start, int target) {
    if (start == target) {
        tmp.push_back(start);
        int thisCost = 0;
        for (int i = tmp.size() - 1; i > 0; i--) {
            for (int j = 0; j < adj[tmp[i]].size(); j++) {
                if (adj[tmp[i]][j].neighbor == tmp[i - 1]) {
                    thisCost += adj[tmp[i]][j].cost;
                    break;
                }
            }
        }
        if (thisCost < minCost) {
            minCost = thisCost;
            path = tmp;
        }
        tmp.pop_back();
        return;
    }
    tmp.push_back(start);
    for (int i = 0; i < pre[start].size(); i++) {
        DFS(pre[start][i], target);
    }
    tmp.pop_back();
}

int main() {
    int m, s, d;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    //图中点比较多的时候建议用邻接表，邻接矩阵太费时间
    for (int i = 0; i < m; i++) {
        int e1, e2, dis, cost;
        scanf("%d %d %d %d", &e1, &e2, &dis, &cost);
        adj[e1].push_back(node(e2, dis, cost));
        adj[e2].push_back(node(e1, dis, cost));
    }
    dijkstra(s);
    DFS(d, s);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d", Distance[d], minCost);
    return 0;
}
