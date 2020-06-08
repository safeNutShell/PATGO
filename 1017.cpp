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

int main()
{
    
    return 0;
}
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
        //注意这里是第一个关键点，即每名顾客最多服务一小时
        tmp2 = tmp2 <= 3600 ? tmp2 : 3600;
        pair<int, int> a = make_pair(tmp, tmp2);
        customer.push_back(a);
    }
    stable_sort(customer.begin(), customer.end(), cmp1);
    int* availableTime = new int[K];
    for (int i = 0; i < K; i++) {
        availableTime[i] = 28800;
    }
    int count = customer.size();
    double totalTime = 0;
    for (int i = 0; i < count; i++) {
        pair<int, int> cur = customer[i];
        int window = -1;
        int time = INT_MAX;
        for (int i = 0; i < K; i++) {
            if (availableTime[i] < time) {
                window = i;
                time = availableTime[i];
            }
        }
        //注意这里是第二个关键点，即存在窗口已空而顾客暂时没到的情况
        //只要17:00之前到，该顾客就一定会服务，不存在排队超时而排除顾客的情况
        if (availableTime[window] < customer[i].first) {
            availableTime[window] = customer[i].first + customer[i].second;
        }
        else {
            totalTime += availableTime[window] - customer[i].first;
            availableTime[window] += customer[i].second;
        }

    }
    printf("%.1f\n", totalTime / (60 * customer.size()));
    return 0;
}
