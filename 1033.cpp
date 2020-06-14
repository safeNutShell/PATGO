#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
//#define INT_MAX 2147483647

using namespace std;

const int maxn = 510;
double Cmax, D, Davg;
int N;
struct station {
    double price;
    double dis;
}sta[maxn];

bool cmp(station a, station b) {
    return a.dis < b.dis;
}

int main() {
    scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &N);
    for (int i = 0; i < N; i++)
        scanf("%lf %lf", &sta[i].price, &sta[i].dis);
    sta[N].dis = D;
    sta[N].price = 0;
    sort(sta, sta + N + 1, cmp);
    if (sta[0].dis != 0)
        printf("The maximum travel distance = 0.00\n");
    else {
        double cost = 0, tank = 0, curlen = 0, maxdis = Cmax * Davg;
        curlen = maxdis;
        int pos = 0;
        for (int i = 1; i <= N; i++) {
            if (sta[i].dis > D)
                break;
            //判断当前加油站可以到达，并且可以让我开的更远
            if (sta[i].dis <= curlen && sta[i].dis + maxdis >= curlen) {
                int first = 0, min = i;
                //搜寻后面的加油站，找到下一个目标
                for (int j = i; j <= N; j++) {
                    if (sta[j].dis <= curlen && sta[j].dis + maxdis >= curlen) {
                        if (sta[j].price < sta[min].price) {
                            min = j;
                        }
                        if (sta[j].price < sta[pos].price) {
                            first = j;
                            break;
                        }
                    }
                    else
                        break;
                }
                //表示找到了一个最小点，比当前位置的油价还低
                if (first != 0) {
                    //只需要花费最少到达该点即可
                    double need = (sta[first].dis - sta[pos].dis) / Davg;
                    if (tank < need) {
                        cost += (need - tank) * sta[pos].price;
                        tank = 0;
                    }
                    else {
                        tank -= need;
                    }
                    curlen = sta[first].dis + maxdis;
                    i = pos = first;
                }
                //没有找到最小，而是极小，当前点的油价是范围内最低的
                else {
                    //尽可能地加满油
                    cost += (Cmax - tank) * sta[pos].price;
                    tank = Cmax - (sta[min].dis - sta[pos].dis) / Davg;
                    curlen = sta[min].dis + maxdis;
                    i = pos = min;
                }
            }
            else
                break;         
        }
        if (pos == N)
            printf("%.2f", cost);
        else
            printf("The maximum travel distance = %.2f\n", curlen);
    }
    return 0;
}
