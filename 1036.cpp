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
    int n;
    scanf("%d", &n);
    string name, ID;
    char gender;
    int score;
    map<int, pair<string, string>>f;
    map<int, pair<string, string>>m;
    for (int i = 0; i < n; i++) {
        cin >> name >> gender >> ID >> score;
        if (gender == 'M') {
            m[score] = make_pair(name, ID);
        }
        else if (gender == 'F') {
            f[score] = make_pair(name, ID);
        }
    }
    int score1 = -1, score2 = -1;
    if (!f.empty()) {
        map<int, pair<string, string>>::reverse_iterator rit = f.rbegin();
        score1 = rit->first;
        cout << rit->second.first << ' ' << rit->second.second << endl;
    }
    else {
        cout << "Absent" << endl;
    }
    if (!m.empty()) {
        map<int, pair<string, string>>::iterator it = m.begin();
        score2 = it->first;
        cout << it->second.first << ' ' << it->second.second << endl;
    }
    else {
        cout << "Absent" << endl;
    }
    if (score1 != -1 && score2 != -1) {
        cout << score1 - score2 << endl;
    }
    else {
        cout<<"NA"<<endl;
    }
    return 0;
}
