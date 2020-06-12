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
    vector<long long int> ans;
    int count;
    int num;
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &num);
        ans.push_back(num);
    }
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &num);
        ans.push_back(num);
    }
    //这题简单了，还以为会超时……
    sort(ans.begin(), ans.end());
    int mid = ans.size() / 2 - (1 - ans.size() % 2);
    printf("%d", ans[mid]);
    return 0;
}
