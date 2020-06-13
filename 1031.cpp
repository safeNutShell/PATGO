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
    string u;
    cin >> u;
    int len = u.length();
    int sum = len + 2;
    int n1, n2;
    int times = 0;
    while (sum % 3 != 0) {
        times++;
        sum -= times;
    }
    n1 = sum / 3;
    n2 = n1 + times;
    //遗憾有两个测试用例超时
    for (int i = 0; i < n1; i++) {
        if (i < n1 - 1) {
            printf("%c", u[i]);
            for (int j = 0; j < n2 - 2; j++)
                printf(" ");
            printf("%c\n", u[len - 1 - i]);
        }
        else {
            for (int j = i; j < n1 + n2 - 1; j++)
                printf("%c", u[j]);
            printf("\n");
        }
    }
    return 0;
}
