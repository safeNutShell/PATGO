#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
#include<stack>
//#define INT_MAX 2147483647
using namespace std;

const int maxn = 100010;

struct node {
	int id, virtue, talent, level;
}ans[maxn];

bool cmp(node a, node b) {
	if (a.level != b.level)
		return a.level < b.level;
	else if (a.virtue + a.talent != b.virtue + b.talent)
		return a.virtue + a.talent > b.virtue + b.talent;
	else if (a.virtue != b.virtue)
		return a.virtue > b.virtue;
	else
		return a.id < b.id;
}

int main() {
	int n, L, H, num = 0;
	cin >> n >> L >> H;
	for (int i = 0; i < n; i++) {
		cin >> ans[i].id >> ans[i].virtue >> ans[i].talent;
		int v = ans[i].virtue;
		int t = ans[i].talent;
		if (v >= L && t >= L) {
			if (v >= H && t >= H) {
				ans[i].level = 1;
				num++;
			}
			else if (v >= H && t < H) {
				ans[i].level = 2;
				num++;
			}
			else if (v >= t && v < H && t < H) {
				ans[i].level = 3;
				num++;
			}
			else {
				ans[i].level = 4;
				num++;
			}
		}
		else
			ans[i].level = 5;
	}
	sort(ans, ans + n, cmp);
	cout << num << endl;
	for (int i = 0; i < num; i++) {
		cout << ans[i].id << ' ' << ans[i].virtue << ' ' << ans[i].talent << endl;
	}
	return 0;
}
