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
    int N, b;
    cin >> N >> b;
    //存储输入的时候，尽量用与输入数据类型匹配的数据结构存储，避免过多的转换
    int c[40];
    int len = 0;
    while (N != 0) {
        int remainder = N % b;
        c[len] = remainder;
        len++;
        N /= b;
    }
    bool flag = true;
    for (int i = 0; i < len / 2; i++) {
        if (c[i] != c[len - 1 - i])
            flag = false;
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (i != 0)
            cout << c[i] << " ";
        else
            cout << c[i] << endl;
    }
    return 0;
}
