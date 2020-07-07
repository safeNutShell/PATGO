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

const int maxn = 1010;
int a[maxn] = { 0 }, b[maxn] = { 0 };
int n, k = 0;

void in(int root) {
	if (root > n) return;
	int l = root * 2;
	int r = root * 2 + 1;
	in(l);
	b[root] = a[k++];
	in(r);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	in(1);
	for (int i = 1; i <= n; i++) {
		cout << b[i];
		if (i < n)
			cout << ' ';
		else
			cout << endl;
	}
	return 0;
}
