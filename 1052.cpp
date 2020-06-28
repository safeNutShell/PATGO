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

bool cmp(pair<int, string> a, pair<int, string>b) {
	return a.first < b.first;
}

int main() {
	int num, startAdd, val;
	string thisAdd, nextAdd;
	cin >> num >> startAdd;
	vector<pair<int, string>>link;
	while (num--) {
		cin >> thisAdd >> val >> nextAdd;
		link.push_back(make_pair(val, thisAdd));
	}
	sort(link.begin(), link.end(), cmp);
	cout << link.size() << ' ' << link[0].second << endl;
	for (int i = 0; i < link.size(); i++) {
		cout << link[i].second << ' ' << link[i].first << ' ';
		if (i < link.size() - 1)
			cout << link[i + 1].second << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
