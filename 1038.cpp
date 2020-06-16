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

bool cmp(string a, string b) {
    int i;
    for (i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    if (i < a.size())
        return a[i] <= a[0];
    if (i < b.size())
        return b[i] > b[0];
}

int main() {
    int n;
    cin >> n;
    string tmp;
    vector<string> a[10];
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a[tmp[0] - '0'].push_back(tmp);
    }
    for (int i = 0; i < 10; i++)
        sort(a[i].begin(), a[i].end(), cmp);
    string ans;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < a[i].size(); j++)
            ans += a[i][j];
    }
    int ptr = 0;
    while (ans[ptr] == '0' && ptr < ans.size() - 1)
        ptr++;
    cout << ans.substr(ptr, ans.size() - ptr);
    return 0;
}
