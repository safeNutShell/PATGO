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
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		vector<int> num;
		int a;
		for (int j = 0; j < n; j++) {
			cin >> a;
			num.push_back(a);
		}
		int ptr = 0;
		int len = 1;
		vector<int> check;
		bool flag = true;
		for (int j = 1; j < n; j++) {
			if (num[j] > num[j - 1]) {
				check.push_back(num[ptr]);
				if (len > m) {
					flag = false;
					break;
				}
				len = 1;
				ptr = j;
			}
			else if (num[j] < num[j - 1]) {
				len++;
			}
			if (j == n - 1) {
				check.push_back(num[ptr]);
				if (len > m)
					flag = false;
			}
		}
		for (int j = 0; j < check.size(); j++) {
			if (j != 0 && check[j] < check[j - 1]) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
