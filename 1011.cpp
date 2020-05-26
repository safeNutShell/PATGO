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
    //理解题意即可，就是判断最大值，ez
    char res[3];
    double a[3];
    for (int i = 0; i < 3; i++) {
        double w, t, l;
        cin >> w;
        cin >> t;
        cin >> l;
        if (w >= t && w >= l) {
            res[i] = 'W';
            a[i] = w;
        }
        else if(t >= w && t >= l) {
            res[i] = 'T';
            a[i] = t;
        }
        else if (l >= w && l >= t) {
            res[i] = 'L';
            a[i] = l;
        }
    }
    double profit = (a[0] * a[1] * a[2] * 0.65 - 1) * 2;
    for (int i = 0; i < 3; i++) {
        cout << res[i] << ' ';
    }
    printf("%.2f", profit);
    return 0;
}
