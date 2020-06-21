#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#define INT_MAX 2147483647

using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}

int main() {
	int n, m;
	vector<int> chain;
	chain.push_back(-1);
	vector<pair<int, int>>ans;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		chain.push_back(tmp);
	}
	int min = INT_MAX;
	for (int i = 1; i <= n; i++) {
  //基本思想是n^2地遍历
		int sum = chain[i];
		if (sum > m) {
			if (sum - m == min)
				ans.push_back(make_pair(i, i));
			if (sum - m < min) {
				ans.clear();
				min = sum - m;
				ans.push_back(make_pair(i, i));
			}
		}
		else if (sum == m) {
			if (min != 0) {
				ans.clear();
				min = 0;
			}
			ans.push_back(make_pair(i, i));
		}
		for (int j = i + 1; j <= n; j++) {
			sum += chain[j];
			if (sum > m) {
				if (sum - m == min)
					ans.push_back(make_pair(i, j));
				else if (sum - m < min) {
					ans.clear();
					min = sum - m;
					ans.push_back(make_pair(i, j));
				}
				else if (sum - m > min)
        //在合适的时候及时break，可以对一些测试用例加速
					break;
			}
			else if (sum == m) {
				if (min != 0) {
					ans.clear();
					min = 0;
				}
				ans.push_back(make_pair(i, j));
        //在合适的时候及时break，可以对一些测试用例加速
				break;
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << '-' << ans[i].second << endl;
	}
	return 0;
}
