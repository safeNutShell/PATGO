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

using namespace std;

int val[110] = { 0 };
int parent[110];
bool isLeaf[110];
vector<int>ans;
vector<vector<int>> res;
int n, m, target;

void DFS(int start, int sum) {
	if (sum + val[start] == target && isLeaf[start]) {
		ans.push_back(val[start]);
		res.push_back(ans);
		/*
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i < ans.size() - 1)
				cout << ' ';
			else
				cout << endl;
		}
		*/
		ans.pop_back();
		return;
	}
	ans.push_back(val[start]);
	for (int i = 0; i < n; i++) {
		if (parent[i] == start) {
			DFS(i, sum + val[start]);
		}
	}
	ans.pop_back();
}

bool cmp(vector<int>a, vector<int>b) {
	int alen = a.size(), blen = b.size();
	int len = alen < blen ? alen : blen;
	for (int i = 0; i < len; i++) {
		if (a[i] >= b[i])
			return a > b;
		else
			return a < b;
	}
	if (alen >= blen)
		return a > b;
	else
		a < b;
}

int main() {
	cin >> n >> m >> target;
	fill(parent, parent + 110, -1);
	memset(isLeaf, true, sizeof(isLeaf));
	for (int i = 0; i < n; i++) cin >> val[i];
	int father, child, num;
	for (int i = 0; i < m; i++) {
		cin >> father >> num;
		isLeaf[father] = false;
		for (int j = 0; j < num; j++) {
			cin >> child;
			parent[child] = father;
		}
	}
	DFS(0, 0);
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
			if (j < res[i].size() - 1)
				cout << ' ';
			else cout << endl;
		}
	}
	return 0;
}
