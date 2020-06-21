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

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> coins;
	int coinNum[1010] = { 0 };
	int cur;
	for (int i = 0; i < n; i++) {
		scanf("%d", &cur);
		coins.push_back(cur);
		if (cur <= m) {
			coinNum[cur]++;
		}
	}
	sort(coins.begin(), coins.end(), cmp);
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (2 * coins[i] == m && coinNum[coins[i]] >= 2 || 2 * coins[i] != m && coinNum[coins[i]] && coinNum[m - coins[i]]) {
			flag = true;
			printf("%d %d", coins[i], m - coins[i]);
			break;
		}
	}
	if (!flag) {
		cout << "No Solution\n";
	}
	return 0;
}
