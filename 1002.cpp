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
    int sizea, sizeb, exp;
    double coe;
    //利用map存储系数和指数的一一对应关系
    map<int, double> mp;
    std::cin >> sizea;
    for (int i = 0; i < sizea; i++) {
        std::cin >> exp >> coe;
        mp[exp] = coe;
    }
    std::cin >> sizeb;
    for (int i = 0; i < sizeb; i++) {
        std::cin >> exp >> coe;
        //首次出现则直接插入
        if (mp.count(exp) == 0) {
            mp[exp] = coe;
        }
        //否则执行+=
        else {
            mp[exp] += coe;
            //系数为0则删除该项
            if (mp[exp] == 0)
                mp.erase(exp);
        }
    }
    std::cout << mp.size();
    //利用map的逆向迭代器遍历map的元素，利用printf的fmt输出控制double的有效位数
    for (map<int, double>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++) {
        printf(" %d %.1f", it->first, it->second);
    }
    std::cout << std::endl;
    return 0;
}
