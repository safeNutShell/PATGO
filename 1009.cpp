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
    int k1, k2;
    //使用map，对key-value分别进行数学运算，结果再存储到map中
    map<int, double> mp1;
    map<int, double> mp2;
    map<int, double> mpres;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int exp;
        double coe;
        cin >> exp >> coe;
        mp1[exp] = coe;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int exp;
        double coe;
        cin >> exp >> coe;
        mp2[exp] = coe;
    }
    map<int, double>::iterator it1 = mp1.begin();
    map<int, double>::iterator it2;
    for (it1; it1 != mp1.end(); it1++) {
        for (it2 = mp2.begin(); it2 != mp2.end(); it2++) {
            int exp;
            double coe;
            exp = it1->first + it2->first;
            coe = it1->second * it2->second;
            if (mpres.count(exp)) {
                mpres[exp] += coe;
                //注意！把所有系数为0的项清除
                if (mpres[exp] == 0) {
                    mpres.erase(exp);
                }
            }
            else {
                mpres[exp] = coe;
            }
        }
    }
    
    cout << mpres.size();
    for (map<int, double>::reverse_iterator it = mpres.rbegin(); it != mpres.rend(); it++) {
        printf(" %d %.1f", it->first, it->second);
    }
    return 0;
}
