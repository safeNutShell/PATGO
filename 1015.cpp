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

bool isPrime(int n)
{
    //质数的定义的特征
    //0和1不是质数
    int i;
    if (n < 2)
        return false;
    //遍历2到根方n，如果有数整除n，则n不是质数
    for (i = 2; i <= sqrt(n); i++)//判断素数
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int reverse(int n, int d) {
    //题意是先将n转化成d进制的数，然后将该数反转，再转换回十进制判断质数
    int seq[100] = { 0 };
    int ptr = 0;
    int x = 1;
    int res = 0;
    while (n != 0) {
        seq[ptr] = n % d;
        n = n / d;
        ptr++;
    }
    ptr--;
    while (ptr >= 0) {
        res += seq[ptr] * x;
        x *= d;
        ptr--;
    }
    return res;
}

int main()
{
    int N, D;
    while (1) {
        scanf("%d", &N);
        if (N < 0)
            break;
        else {
            scanf("%d", &D);
            int tmp = reverse(N, D);
            if (isPrime(N) && isPrime(tmp))
                printf("%s\n", "Yes");
            else
                printf("%s\n", "No");
        }
    }
    return 0;
}
