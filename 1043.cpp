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

int s;
vector<int> res;

bool judge(vector<int> test, int start,int left,int right) {
	if (left >= right && start >= 0&&start<test.size()) {
		res.push_back(test[start]);
		return true;
	}
	int ptr = -1;
	for (int i = left; i <= right; i++) {
		if (test[i] < test[start])
			continue;
		else if (test[i] >= test[start]) {
			ptr = i;
			break;
		}
	}
	if (ptr != -1) {
		for (int i = ptr; i <= right; i++) {
			if (test[i] < test[start])
				return false;
		}
	}
	bool child = judge(test, start + 1, start + 2, ptr - 1) && judge(test, ptr, ptr + 1, right);
	if (child)
		res.push_back(test[start]);
	return child;
}

bool judge2(vector<int> test, int start, int left, int right) {
	if (left >= right && start >= 0 && start < test.size()) {
		res.push_back(test[start]);
		return true;
	}
	int ptr = -1;
	for (int i = left; i <= right; i++) {
		if (test[i] >= test[start])
			continue;
		else if (test[i] < test[start]) {
			ptr = i;
			break;
		}
	}
	if (ptr != -1) {
		for (int i = ptr; i <= right; i++) {
			if (test[i] >= test[start])
				return false;
		}
	}
	bool child = judge2(test, start + 1, start + 2, ptr - 1) && judge2(test, ptr, ptr + 1, right);
	if (child)
		res.push_back(test[start]);
	return child;
}

int main() {
	int num;
	cin >> s;
	vector<int> tree;
	for (int i = 0; i < s; i++) {
		cin >> num;
		tree.push_back(num);
	}
	if (judge(tree, 0, 1, s - 1)) {
		cout << "YES" << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i < res.size() - 1)
				cout << ' ';
			else if (i == res.size() - 1)
				cout << endl;
		}
	}
	else {
		if (judge2(tree, 0, 1, s - 1)) {
			cout << "YES" << endl;
			for (int i = 0; i < res.size(); i++) {
				cout << res[i];
				if (i < res.size() - 1)
					cout << ' ';
				else if (i == res.size() - 1)
					cout << endl;
			}
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
