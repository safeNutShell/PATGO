#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>

using namespace std;
struct customer {
    //与时间相关的数据都用秒计算
    int arrive, start, play, wait, vip;
};
bool isvip[110] = { false };
int table[110], num[110] = { 0 }, k;
vector<customer> ans;
int convert(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}
int start = convert(8, 0, 0), endt = convert(21, 0, 0);

bool cmp1(customer a1, customer a2) {
    return a1.arrive < a2.arrive;
}

int main() {
    int n, h, m, s, t, v;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        customer a;
        scanf_s("%d:%d:%d %d %d", &h, &m, &s, &t, &v);
        a.arrive = convert(h, m, s);
        if (a.arrive >= endt)
            continue;
        a.play = t <= 120 ? t * 60 : 7200;
        a.start = endt;
        a.vip = v;
        ans.push_back(a);
    }
    sort(ans .begin(), ans.end(), cmp1);
    int vipsum;
    int vipnum;
    scanf_s("%d %d", &k, &vipsum);
    for (int i = 0; i < vipsum; i++) {
        scanf_s("%d", &vipnum);
        isvip[vipnum] = true;
    }
    for (int i = 1; i <= k; i++)
        table[i] = start;

    return 0;
}
