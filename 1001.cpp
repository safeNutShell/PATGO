#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main()
{
    int a, b;
    //编译器g++6.5.0不知为何不识别using namespace stdf，因此加上std::
    std::cin >> a >> b;
    int sum = a + b;
    if (sum == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    string res = "";
    string tmp = "";
    if (sum < 0)
        res += '-';
    sum = sum < 0 ? -sum : sum;
    int remainder = 0;
    int commaCount = 0;
    while (sum != 0) {
        remainder = sum % 10;
        sum = sum / 10;
        commaCount++;
        tmp += (remainder + '0');
        if (commaCount == 3) {
            tmp += ',';
            commaCount = 0;
        }
    }
    for (int i = tmp.size() - 1; i >= 0; i--) {
        if (i == tmp.size() - 1 && tmp[i] == ',')
            continue;
        res += tmp[i];
    }
    std::cout << res << std::endl;

    return 0;
}
