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
	int n;
	cin >> n;
	int num;
	map<int, int> mp;
	vector<int> tmp;
	for (int i = 0; i < n; i++) {
		cin >> num;
		tmp.push_back(num);
		if (mp.count(num) == 0)
			mp[num] = 1;
		else
			mp[num]++;
	}
	int ptr = 0;
	for (ptr; ptr < n; ptr++) {
		if (mp[tmp[ptr]] == 1) {
			cout << tmp[ptr] << endl;
			break;
		}
	}
	if (ptr == n)
		cout << "None" << endl;
	return 0;
}
