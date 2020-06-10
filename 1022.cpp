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
//#define INT_MAX 2147483647

using namespace std;

int N;
//0:title; 1:author; 2:keyword; 3:publisher; 4:year
map <string, vector<int>> mp[5];

int main()
{
    scanf("%d", &N);
    int ID;
    string title, author, key, publisher, year;
    for (int i = 0; i < N; i++) {
        scanf("%d", &ID);
        //getchar()是用于读取被scanf忽略的ID后回车用的，否则'\n'会被读入title
        getchar();
        //读入的字符串包含空格，因此需要用getline.getline会读入换行符并把它解读成空字符
        getline(cin, title);
        mp[0][title].push_back(ID);
        getline(cin, author);
        mp[1][author].push_back(ID);
        getline(cin, key);
        int guard = 0;
        for (int j = 0; j < key.size(); j++) {
            string keyi;
            if (j == key.size() - 1) {
                keyi = key.substr(guard, j - guard + 1);
            }
            if (key[j] == ' ') {
                keyi = key.substr(guard, j - guard);
                guard = j + 1;
            }
            mp[2][keyi].push_back(ID);
        }
        getline(cin, publisher);
        mp[3][publisher].push_back(ID);
        getline(cin, year);
        mp[4][year].push_back(ID);
    }  
    int query;
    string check;
    scanf("%d", &query);
    getchar();
    for (int i = 0; i < query; i++) {
        getline(cin, check);
        //printf是C的写法，但是C没有string，因此需要string对象调用c_str()来返回一个指针供%s读取
        printf("%s\n", check.c_str());
        //减去一个字符表示和当前字符之间的相对距离
        int mapNum = check[0] - '1';
        string s = check.substr(3, check.size() - 3);
        if (mp[mapNum].count(s) != 0) {
            sort(mp[mapNum][s].begin(), mp[mapNum][s].end());
            for (int j = 0; j < mp[mapNum][s].size(); j++) {/
                //题目说给定7位ID，但居然有的不够7位，需要在输出的时候手动控制按7位输出并补0……
                printf("%07d\n", mp[mapNum][s][j]);
            }
        }
        else {
            printf("Not Found\n");
        }
    }
   
    return 0;
}
