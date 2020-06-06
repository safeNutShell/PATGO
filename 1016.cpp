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

//存储每小时价目
int toll[24];

struct bill {
    string startTime, endTime;
    int mins;
    double fee;
};

bool cmp1(pair<string, bool>a, pair<string, bool>b) {
    return a.first < b.first;
}

bool cmp2(bill b1, bill b2) {
    return b1.startTime < b2.startTime;
}

int toInt(string a) {
    int num = (a[0] - '0') * 10 + a[1] - '0';
    return num;
}

double calFee(string start, string end) {
    int d1 = toInt(start.substr(3, 2));
    int h1 = toInt(start.substr(6, 2));
    int m1 = toInt(start.substr(9, 2));
    int d2 = toInt(end.substr(3, 2));
    int h2 = toInt(end.substr(6, 2));
    int m2 = toInt(end.substr(9, 2));
    double fee = 0.0;
    while (d1 < d2 || h1 < h2 || m1 < m2) {
        fee += toll[h1];
        m1++;
        if (m1 == 60) {
            m1 = 0;
            h1++;
        }
        if (h1 == 24) {
            h1 = 0;
            d1++;
        }
    }
    return fee;
}

int calTime(string start, string end) {
    int startTime = ((start[3] - '0') * 10 + start[4] - '0') * 1440 + ((start[6] - '0') * 10 + start[7] - '0') * 60 + ((start[9] - '0') * 10 + start[10]);
    int endTime = ((end[3] - '0') * 10 + end[4] - '0') * 1440 + ((end[6] - '0') * 10 + end[7] - '0') * 60 + ((end[9] - '0') * 10 + end[10]);
    return endTime - startTime;
}

int main()
{
    for (int i = 0; i < 24; i++) {
        scanf("%d", &toll[i]);
    }
    int N;
    scanf("%d", &N);
    //人名以及对应的记录信息
    map<string, vector<pair<string, bool>>> mp;
    string name, time, flag;
    for (int i = 0; i < N; i++) {
        cin >> name >> time >> flag;
        if (flag == "on-line") {
            //注意pair也是一个对象，需要声明初始化，或者使用make_pair
            mp[name].push_back(make_pair(time, true));
        }
        else {
            mp[name].push_back(make_pair(time, false));
        }
    }
    //人名以及对应的账单信息
    map<string, vector<bill>> billMap;
    for (map<string, vector<pair<string, bool>>>::iterator it = mp.begin(); it != mp.end(); it++) {
        stable_sort(it->second.begin(), it->second.end(), cmp1);
        bool flag = true;
        int pre;
        for (int i = 0; i < it->second.size(); i++) {
            if (it->second[i].second == flag) {
                if (flag == true) {
                    pre = i;
                    flag = false;
                }
                else {
                    bill tmp;
                    tmp.startTime = it->second[pre].first;
                    tmp.endTime = it->second[i].first;
                    tmp.fee = calFee(tmp.startTime, tmp.endTime);
                    tmp.mins = calTime(tmp.startTime, tmp.endTime);
                    billMap[it->first].push_back(tmp);
                    flag = true;
                }
            }
            else {
                if (it->second[i].second == true)
                    pre = i;
            }
        }
    }
    //遍历账单map，准备输出
    for (map<string, vector<bill>>::iterator it = billMap.begin(); it != billMap.end(); it++) {
        stable_sort(it->second.begin(), it->second.end(),cmp2);
        //如果输出是用c的printf的话，当输出string时，最好在原指针后面调用一个c_str()，以满足c的兼容
        //如果是cout则不需要， cout << it->first << endl;即可
        printf("%s %s\n", it->first.c_str(), it->second[0].startTime.substr(0, 2).c_str());
        double total = 0;
        for (int i = 0; i < it->second.size(); i++) {
            double dollar = it->second[i].fee / 100;
            printf("%s %s %d $%.2f\n", it->second[i].startTime.substr(3, 8).c_str(), it->second[i].endTime.substr(3, 8).c_str(), it->second[i].mins, dollar);
            total += dollar;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}
