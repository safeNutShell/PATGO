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

int main() {
    int nc, np;
    long long int tmp = 0;
    vector<long long int>c;
    vector<long long int>p;
    long long int money = 0;
    cin >> nc;
    for (int i = 0; i < nc; i++) {
        cin >> tmp;
        c.push_back(tmp);
    }
    cin >> np;
    for (int i = 0; i < np; i++) {
        cin >> tmp;
        p.push_back(tmp);
    }
    sort(c.begin(), c.end());
    sort(p.begin(), p.end());
    int len = nc > np ? np : nc;
    for (int i = 0; i < len; i++) {
        if (c[i] < 0 && p[i] < 0)
            money += c[i] * p[i];
        else
            break;
    }
    nc--;
    np--;
    while (nc >= 0 && np >= 0) {
        if (c[nc] > 0 && p[np] > 0)
            money +=  c[nc] * p[np];
        else
            break;
        nc--;
        np--;
    }
    cout << money << endl;
    return 0;
}
