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

int main() {
    int rgb[3];
    char a[13] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };
    scanf("%d %d %d", &rgb[0], &rgb[1], &rgb[2]);
    cout << "#";
    for (int i = 0; i < 3; i++) {
        int first = rgb[i] / 13;
        int second = rgb[i] % 13;
        cout << a[first] << a[second];
    }
    cout << endl;
    return 0;
}
