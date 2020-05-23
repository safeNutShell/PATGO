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
    string input = "";
    cin >> input;
    string res = "0";
    int test = 0;//想多了，即使是100位10其和也仅有1000，用int即可，无需实现string的大数加法
    for (int i = 0; i < input.size(); i++) {
        test += input[i] - '0';
    }
    //把int转称string方便对0的处理
    res = to_string(test);
    //用一个数组枚举，别用switch...，不仅繁琐还不明爆了两个测试用例
    string ans[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (int i = 0; i < res.size(); i++) {
        cout << ans[res[i] - '0'];
        if (i + 1 == res.size()) {
            cout << endl;
        }
        else {
            cout << ' ';
        }
    }

    return 0;
}
