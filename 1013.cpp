#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int n;
//map[0][0]不用，从1开始
bool cities[1010][1010];
bool C[1010][1010];
bool connected[1010];

bool copy() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            C[i][j] = cities[i][j];
        }
    }
}

void BFS(int target) {
    queue<int> Q;
    connected[target] = true;
    Q.push(target);
    while (Q.size()) {
        int nodeToVisit = Q.front();
        Q.pop();
        for (int i = 1; i <= n; ++i) {
            if (connected[i] == false && C[nodeToVisit][i] == 1) {
                Q.push(i);
                connected[i] = true;
            }
        }
    }
}

int main()
{
    int m, k, e1, e2;
    //所有的输入输出都是用scnaf和printf，这比cin和cout快得多！不容易超时，而且在输出的时候方便对输出格式进行控制。
    scanf("%d %d %d", &n, &m, &k);
    memset(cities, 0, sizeof(cities));
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &e1, &e2);
        cities[e1][e2] = cities[e2][e1] = 1;
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &e1);
        copy();
        for (int i = 1; i <= n; ++i)
            C[i][e1] = C[e1][i] = 0;
        memset(connected, 0, sizeof(connected));
        int count = 0;
        //本质上是通过对图的遍历完成的。删去一个点后，对剩下的点进行遍历，如果一次即可遍历所有的点则认为连通，每多遍历一次，就需要多建一条路
        for (int j = 1; j <= n; ++j) {
            if (connected[j] == false && j != e1) {
                BFS(j);
                count++;
            }
        }
        printf("%d\n", count - 1);
    }

    return 0;
}
