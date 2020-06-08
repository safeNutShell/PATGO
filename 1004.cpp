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
const int maxn = 100;
struct Node {
    int child[maxn];
    int childCount;
    int level;
    Node() {
        memset(child, 0, sizeof(child));
        childCount = 0;
    }
}Tree[maxn];

int level[maxn];
int levelCount() {
    memset(level, 0, sizeof(level));
    queue<Node> Q;
    Tree[1].level = 0;
    Q.push(Tree[1]);
    int maxlevel = -1;
    //层序一般就是利用队列
    while (!Q.empty()) {
        Node tmp = Q.front();
        Q.pop();
        //一边遍历队列，一边对每个节点的level进行赋值
        if (tmp.level > maxlevel)
            maxlevel = tmp.level;
        //用于记录结果的值独立存储，方便不同功能之间调用和操作
        if (tmp.childCount == 0)
            ++level[tmp.level];
        else {
            for (int i = 0; i < tmp.childCount; i++) {
                Tree[tmp.child[i]].level = tmp.level + 1;
                Q.push(Tree[tmp.child[i]]);
            }
        }
    }
    return maxlevel;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int ID, K;
        cin >> ID >> K;
        Tree[ID].childCount = K;
        for (int i = 0; i < K; i++) {
            cin >> Tree[ID].child[i];
        }
    }
    int maxlevel = levelCount();
    for (int i = 0; i <= maxlevel; i++) {
        cout << level[i];
        if (i != maxlevel)
            cout << ' ';
        else
            cout << '\n';
    }
    return 0;
}
