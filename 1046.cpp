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
	int n, m, rin = 0;
	cin >> n;
	int* dis = new int[n + 1];
	int* d1 = new int[n + 1];
	dis[0] = 0;
	d1[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> dis[i];
		d1[i] = rin;
		rin += dis[i];
	}
	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a > b) {
			int tmp = b;
			b = a;
			a = tmp;
		}
		if (a == 1) {
			int neg = rin - d1[b];
			int res = min(neg, d1[b]);
			cout << res << endl;
		}
		else {
			int pos = d1[b] - d1[a];
			int neg = rin - pos;
			int res = min(pos, neg);
			cout << res << endl;
		}
	}

	return 0;
}
