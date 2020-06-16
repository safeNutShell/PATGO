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
  //最后一个测试用例运行超时
	int n, k;
	cin >> n >> k;
	map<string, vector<int>> stu;
	string name;
	for (int i = 0; i < k; i++) {
		int no, count;
		cin >> no >> count;
		for (int j = 0; j < count; j++) {
			cin >> name;
			stu[name].push_back(no);
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> name;
		if (stu.count(name) != 0) {
			sort(stu[name].begin(), stu[name].end());
			cout << name << ' ' << stu[name].size() << ' ';
			for (int j = 0; j < stu[name].size(); j++) {
				cout << stu[name][j];
				if (j < stu[name].size() - 1)
					cout << ' ';
				else if (j == stu[name].size() - 1)
					cout << endl;
			}
		}
		else {
			cout << name << ' ' << 0 << endl;
		}
	}
	return 0;
}
