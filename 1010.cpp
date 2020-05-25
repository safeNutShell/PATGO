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

long long int toNum(char c) {
    if (c >= '0' && c <= '9')
        return (long long int)c - '0';
    else
        return (long long int)c - 'a' + 10;
}

long long int toDecimal(string nums, long long int radix) {
    long long int res = 0;
    long long int coe = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        res += toNum(nums[i]) * coe;
        coe *= radix;
        //long long int 仍然可能越界，此时数值会变负，因此要给出判断
        if (res < 0 || coe < 0) {
            return -1;
        }
    }

    return res;
}

int main()
{
    //因为计算后数字可能非常大，因此存储转换来的十进制数都要用long long int存储
    string n1, n2;
    int tag;
    long long int radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2) {
        string tmp = n2;
        n2 = n1;
        n1 = tmp;
        swap(n1, n2);
    }
    long long int target = toDecimal(n1, radix);
    long long int minRadix = 2;
    //进制的上限有些巧妙，是目标数的十进制值。因为如果n2的进制比这个值还大，那么n2只要不为0就一定比n1大了
    long long int maxRadix = target;
    long long int midRadix;
    //进制的下限很简单，即目标数单位十进制最大值加一
    for (int i = 0; i < n2.size(); i++) {
        minRadix = max(minRadix, toNum(n2[i]) + 1);
    }
    //必须使用二分法，否则容易超时。二分循环的条件是上界大于等于下界
    while (minRadix <= maxRadix) {
        midRadix = (minRadix + maxRadix) / 2;
        long long int tmp = toDecimal(n2, midRadix);
        if (tmp == -1 || tmp >= target)
            maxRadix = midRadix - 1;
        else
            minRadix = midRadix + 1;
    }
    //由于判断条件是上界大于等于下界，因此返回时目标值在下界指针上（不是mid指针），这一点可以推算出来，也可以直接当成二分法的一个模板去记忆
    if (toDecimal(n2, minRadix) == target)
        cout << minRadix;
    else
        cout << "Impossible";
    return 0;
}
