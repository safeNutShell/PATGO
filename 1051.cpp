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
		bool flag = true;
		vector<int> dp(n, 0);
		vector<int> check;
		dp[n - 1] = 1;
		for (int j = n - 2; j >= 0; j--) {
			if (num[j] > num[j + 1]) {
				dp[j] = dp[j + 1] + 1;
			}
			else {
				dp[j] = 1;
				if (dp[j + 1] > m) {
					flag = false;
					break;
				}
				check.push_back(num[j + 1]);
			}
			if (j == 0) {
				if (dp[j] > m) {
					flag = false;
					break;
				}
				if (num[j] > num[j + 1]) {
					check.push_back(num[j]);
				}
			}
		}
		if (check.size() > 1) {
			for (int i = 1; i < check.size(); i++) {
				if (check[i] > check[i - 1]) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
