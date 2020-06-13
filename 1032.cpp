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
    int add1, add2, N;
    map<int, pair<char, int>> ans;
    scanf_s("%d %d %d", &add1, &add2, &N);
    int curAdd, nextAdd;
    char c;
    for (int i = 0; i < N; i++) {
        scanf_s("%d %c %d", &curAdd, &c, 1, &nextAdd);
        if (ans.count(nextAdd) == 0)
            ans[nextAdd] = make_pair(c, curAdd);
        else
            printf("%d\n", nextAdd);
    }
    return 0;
}
