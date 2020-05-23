#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main()
{
    //STL的map在存储时会使用红黑树，自带排序，且排序是以key为准的，因此ID变成value
    map<int, string> in;
    map<int, string> out;
    int count = 0;
    cin >> count;
    string ID;
    string signInTime;
    string signOutTime;
    for (int i = 0; i < count; i++) {
        cin >> ID >> signInTime >> signOutTime;
        //把标准时间变成秒数，用秒数进行排序，得出最早和最晚
        int signIn = (signInTime[0] * 10 + signInTime[1]) * 3600 + (signInTime[3] * 10 + signInTime[4]) * 60 + (signInTime[6] * 10 + signInTime[7]);
        int signOut= (signOutTime[0] * 10 + signOutTime[1]) * 3600 + (signOutTime[3] * 10 + signOutTime[4]) * 60 + (signOutTime[6] * 10 + signOutTime[7]);
        in[signIn] = ID;
        out[signOut] = ID;
    }
    //迭代器赋值begin()指向第一个元素
    map<int, string>::iterator it = in.begin();
    cout << it->second << ' ';
    //反向迭代器赋值rbegin()指向最后一个元素
    map<int, string>::reverse_iterator it2 = out.rbegin();
    cout << it2->second;
    return 0;
}
