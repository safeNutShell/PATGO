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
#include<set>
//#define INT_MAX 2147483647

using namespace std;

int main() {
	int n; 
	cin >> n;
	vector<set<int>>data;
	for (int i = 0; i < n; i++) {
		int num, element;
		cin >> num;
		set<int>tmp;
		while (num--) {
			cin >> element;
			tmp.insert(element);
		}
		data.push_back(tmp);
	}
	int m;
	cin >> m;
	int s1, s2;
	while (m--) {
		cin >> s1 >> s2;
		int sum = data[s1 - 1].size();
		int sub = 0;
		set<int>::iterator it = data[s2 - 1].begin();
		for (it; it != data[s2 - 1].end(); it++) {
			set<int>::iterator it1 = data[s1 - 1].find(*it);
			if (it1 == data[s1 - 1].end())
				sum++;
			else
				sub++;
		}
		double res = (double)sub / sum * 100.0;
		printf("%.1f", res);
		cout << "%" << endl;
	}
	return 0;
}
