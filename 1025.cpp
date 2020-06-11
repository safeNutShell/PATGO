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
//当数据对象的结果过于复杂时，使用结构体进行存储
struct student {
    long long int no;
    int score;
    int location;
    int localrank;
    int finalrank;
};

//活用cmp，对模板类对象进行排序时可以指定多种判断条件
bool cmp(student a, student b) {
    if (a.score != b.score)
        return a.score > b.score;
    return a.no < b.no;
}

int main() {
    int n, k;
    cin >> n;
    vector<student> tmp, ans;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        tmp.clear();
        for (int j = 0; j < k; j++) {
            student a;
            scanf("%lld %d", &a.no, &a.score);
            a.location = i;
            tmp.push_back(a);
        }
        sort(tmp.begin(), tmp.end(), cmp);
        tmp[0].localrank = 1;
        ans.push_back(tmp[0]);
        for (int k = 1; k < tmp.size(); k++) {
            tmp[k].localrank = k + 1;
            if (tmp[k].score == tmp[k - 1].score)
                tmp[k].localrank = tmp[k - 1].localrank;
            ans.push_back(tmp[k]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", ans.size());
    ans[0].finalrank = 1;
    //输出的时候变量不要加&，否则输出的时地址。输入变量的时候需要加&表示地址。
    printf("%013lld %d %d %d\n", ans[0].no, ans[0].finalrank, ans[0].location, ans[0].localrank);
    for (int i = 1; i < ans.size(); i++) {
        ans[i].finalrank = i + 1;
        if (ans[i].score == ans[i - 1].score)
            ans[i].finalrank = ans[i - 1].finalrank;
        printf("%013lld %d %d %d\n", ans[i].no, ans[i].finalrank, ans[i].location, ans[i].localrank);
    }
    return 0;
}
