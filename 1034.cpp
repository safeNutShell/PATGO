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
const int maxn = 2010;
int n, k;
struct person {
	int time;
	int root;
	person() {
		time = 0;
		root = -1;
	}
}Tree[maxn];
map<string, int>mp;
map<int, string>rmp;

int findRoot(int a) {
	int x = a;
	while (Tree[a].root != -1) a = Tree[a].root;
	while (Tree[x].root != -1) {
		int tmp = x;
		x = Tree[x].root;
		Tree[tmp].root = a;
	}
	return a;
}

void merge(int a, int b) {
	a = findRoot(a);
	b = findRoot(b);
	if (a != b) {
		if (Tree[a].time < Tree[b].time) {
			Tree[a].root = b;
		}
		else {
			Tree[b].root = a;
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < maxn; i++) {
		Tree[i].root = -1;
	}
	string a, b;
	int time, no = 0;
	vector<pair<int, int>> tmp;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> time;
		if (mp.count(a) == 0) {
			rmp[no] = a;
			mp[a] = no++;
		}
		if (mp.count(b) == 0) {
			rmp[no] = b;
			mp[b] = no++;
		}
		Tree[mp[a]].time += time;
		Tree[mp[b]].time += time;
		tmp.push_back(make_pair(mp[a], mp[b]));
	}
	for (int i = 0; i < tmp.size(); i++) {
		merge(tmp[i].first, tmp[i].second);
	}
	int num[maxn] = { 0 };
	int totalTime[maxn] = { 0 };
	for (int i = 0; i < no; i++) {
		num[findRoot(i)]++;
		totalTime[findRoot(i)] += Tree[i].time;
	}
	vector<int> res;
	for (int i = 0; i < no; i++) {
		if (num[i] > 2 && totalTime[i] / 2 > k)
			res.push_back(i);
	}
	if (res.size() == 0)
		cout << 0 << endl;
	else {
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << rmp[res[i]] << ' ' << num[res[i]] << endl;
		}
	}
	return 0;
}
