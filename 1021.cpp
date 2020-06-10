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
//#define INT_MAX 2147483647

using namespace std;

//此代码针对测试用例3运行超时，原因是使用了邻接矩阵，搜索了大量冗余表项
//图改用邻接表存储可大大减少时间消耗
bool Graph[10001][10001] = { false };
bool visited[10001] = {false};
int N;
int deepest;

void DFS(int start, int depth) {
    visited[start] = true;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false && Graph[start][i] == 1) {
            DFS(i, depth + 1);
        }
    }
    if (depth > deepest)
        deepest = depth;
}

int main()
{

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int v1, v2;
        scanf_s("%d%d", &v1, &v2);
        Graph[v1][v2] = true;
        Graph[v2][v1] = true;
    }
    vector<int> res;
    int deep = -1;
    int k = 1;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        deepest = -1;
        //基于对图的遍历，遍历时寻找当前起点可得到的树的最深深度
        DFS(i, 1);
        //利用deep中间变量存储上次的deepset，用于判断res整体是否需要更新
        if (deepest > deep) {
            res.clear();
            deep = deepest;
            res.push_back(i);
        }
        else if (deepest == deep) {
            res.push_back(i);
        }
        for (int j = 1; j <= N; j++) {
            if (visited[j] == false) {
                DFS(j, 1);
                k++;
            }
        }
        if (k != 1)
            break;
        //只要一次出发发现没有遍历完所有节点，那么它就是一个非连通图
        //而对非联通图的计数在j的循环中已经完成，因此此时可以退出
    }
    if (k != 1) {
        printf("Error: %d components", k);
    }
    else {
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << endl;
        }
    }
    return 0;
}
