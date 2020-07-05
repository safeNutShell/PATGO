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
int n, k, num[maxn], total[maxn];
struct person {
	int time;
	int father;
	person():time(0){}
}Tree[maxn];
map<string, int>mp, rec;
map<int, string>rmp;

int findRoot(int x) {
	int a = x;
	while (Tree[x].father != x) {
		x = Tree[x].father;
	}
	while (Tree[a].father != a) {
		int tmp = a;
		a = Tree[a].father;
		Tree[tmp].father = x;
	}
	return x;
}

void Union(int a, int b) {
	int a1 = findRoot(a);
	int b1 = findRoot(b);
	if (a1 != b1) {
		if (Tree[a].time < Tree[b].time)
			Tree[a].father = b1;
		else
			Tree[b].father = a1;
	}
}

int main() {
	cin >> n >> k;
	string a, b;
	for (int i = 0; i < maxn; i++)
		Tree[i].father = i;
	int t, no = 0;
	vector<pair<int, int>> ope;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> t;
		if (mp.count(a) == 0) {
			rmp[no] = a;
			mp[a] = no++;
		}
		if (mp.count(b) == 0) {
			rmp[no] = b;
			mp[b] = no++;
		}
		Tree[mp[a]].time += t;
		Tree[mp[b]].time += t;
		ope.push_back(make_pair(mp[a], mp[b]));
	}
	for (int i = 0; i < ope.size(); i++)
		Union(ope[i].first, ope[i].second);
	fill(num, num + maxn, 0);
	fill(total, total + maxn, 0);
	for (int i = 0; i < no; i++) {
		int tmp = findRoot(i);
		num[tmp]++;
		total[tmp] += Tree[i].time;
	}
	for (int i = 0; i < no; i++) {
		if (num[i] > 2 && total[i] / 2 > k)
			rec[rmp[i]] = num[i];
	}
	cout << rec.size() << endl;
	for (map<string, int>::iterator it = rec.begin(); it != rec.end(); it++) {
		cout << it->first << ' ' << it->second << endl;
	}
	return 0;
}
