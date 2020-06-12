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
struct student {
    int ID;
    //用string有时会在scanf和printf的兼容性上出问题
    char name[10];
    int score;
};
vector<student> ans;

bool cmp1(student a, student b) {
    return a.ID < b.ID;
}

bool cmp2(student a, student b) {
//比较char[]时用strcmp,它根据每位字符的ascii值进行比较
//左边小返回<0，相等返回0，左边大返回>0
//A-Z a-z
    if (strcmp(a.name ,b.name)==0)
        return a.ID < b.ID;
    return strcmp(a.name, b.name) < 0;
}
bool cmp3(student a, student b) {
    if (a.score==b.score)
        return a.ID < b.ID;
    return a.score < b.score;
}

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        student stu;
        cin >> stu.ID >> stu.name >> stu.score;
        ans.push_back(stu);
    }
    if (c == 1)
        sort(ans.begin(), ans.end(), cmp1);
    else if (c == 2)
        sort(ans.begin(), ans.end(), cmp2);
    else if (c == 3)
        sort(ans.begin(), ans.end(), cmp3);
    for (int i = 0; i < ans.size(); i++) {
        printf("%06d %s %d\n", ans[i].ID, ans[i].name, ans[i].score);
    }
    return 0;
}
