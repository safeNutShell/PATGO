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

using namespace std;

//N表示顾客数，K表示窗口数
int N, K;

int timeToInt(string str) {
    int h = (str[0] - '0') * 10 + str[1] - '0';
    int m = (str[3] - '0') * 10 + str[4] - '0';
    int s = (str[6] - '0') * 10 + str[7] - '0';
    return h * 3600 + m * 60 + s;
}

bool cmp1(pair<int, int>a1, pair<int, int>a2) {
    return a1.first < a2.first;
}

int main()
{
    scanf("%d %d", &N, &K);
    vector<pair<int, int>> customer;
    string arrive;
    int process;
    for (int i = 0; i < N; i++) {
        cin >> arrive >> process;
        int tmp = timeToInt(arrive);
        if (tmp >= 61201)
            continue;
        int tmp2 = process * 60;
        pair<int, int> a = make_pair(tmp, tmp2);
        customer.push_back(a);
    }
    stable_sort(customer.begin(), customer.end(), cmp1);
    int* availableTime = new int[K];
    for (int i = 0; i < K; i++) {
        availableTime[i] = 28800;
    }
    int count = customer.size();
    int* waitTime = new int[count];
    for (int i = 0; i < count; i++) {
        pair<int, int> cur = customer[i];
        int window = 0;
        int time = availableTime[window];
        for (int i = 1; i < K; i++) {
            if (availableTime[i] < time) {
                window = i;
                time = availableTime[i];
            }
        }
        int wait = availableTime[window] - cur.first;
        waitTime[i] = wait;
        availableTime[window] += cur.second;
    }
    double totalTime = 0;
    for (int i = 0; i < count; i++) {
        totalTime += waitTime[i];
    }
    double k = count * 60;
    double res = totalTime / k;
    printf("%.1f", res);
    return 0;
}
