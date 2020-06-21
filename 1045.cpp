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
	int n, m, l;
	cin >> n;
	cin >> m;
	int* a = new int[m+1];
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	cin >> l;
	int* b = new int[l+1];
	for (int i = 1; i <= l; i++) {
		cin >> b[i];
	}
	int** dp = new int* [m + 1];
	for (int i = 0; i < m + 1; i++)
		dp[i] = new int[l + 1];
	for (int i = 0; i < m + 1; i++)
		dp[i][0] = 0;
	for (int i = 0; i < l + 1; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= l; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[m][l] << endl;
	return 0;
}
