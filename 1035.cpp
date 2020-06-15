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
    int n, modify = 0;
    string name, passwd;
    vector<pair<string, string>> ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> name >> passwd;
        bool flag = false;
        for (int j = 0; j < passwd.length(); j++) {
            if (passwd[j] == '1') {
                passwd[j] = '@';
                flag = true;
            }
            if (passwd[j] == '0') {
                passwd[j] = '%';
                flag = true;
            }
            if (passwd[j] == 'l') {
                passwd[j] = 'L';
                flag = true;
            }
            if (passwd[j] == 'O') {
                passwd[j] = 'o';
                flag = true;
            }
        }
        if (flag) {
            ans.push_back(make_pair(name, passwd));
        }
    }
    if (ans.size() == 0){
        if (n == 1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n", n);
    }
    else {
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
    }
    return 0;
}
