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
//#define INT_MAX 2147483647
using namespace std;

struct node {
	int v;
	string cur, next;
};

bool cmp(node a, node b) {
	return a.v < b.v;
}

int main() {
	int n, val;
	string startAdd, thisAdd, nextAdd;
	map<string,node>list;
	vector<node>ans;
	cin >> n >> startAdd;
	if (n == 0) {
		cout << 0 << ' ' << -1 << endl;
		return 0;
	}
	while (n--) {
		cin >> thisAdd >> val >> nextAdd;
		node a;
		a.v = val;
		a.cur = thisAdd;
		a.next = nextAdd;
		list[thisAdd] = a;
	}
	//sort(list.begin(), list.end(), cmp);
	string adr = startAdd;
	int count = 0;
	while (adr != "-1") {
		count++;
		ans.push_back(list[adr]);
		adr = list[adr].next;
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << count << ' ' << ans[0].cur << endl;
	for (int i = 0; i < count; i++) {
		printf("%s %d ", ans[i].cur.c_str(), ans[i].v);
		if (i < count - 1)
			printf("%s\n", ans[i + 1].cur.c_str());
		else
			cout << -1 << endl;
	}
	return 0;
}
