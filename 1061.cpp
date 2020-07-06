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
//#define INT_MAX 2147483647
using namespace std;

int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int len1 = a.length() < b.length() ? a.length() : b.length();
	int len2 = c.length() < d.length() ? c.length() : d.length();
	bool flag = 0;
	for (int i = 0; i < len1; i++) {
		if (a[i] == b[i] && flag == 0 && a[i] >= 'A' && a[i] <= 'G') {
			cout << week[a[i] - 'A'] << ' ';
			flag = 1;
			continue;
		}
		if (a[i] == b[i] && flag == 1 && (a[i] >= 'A' && a[i] <= 'N' || isdigit(a[i]))) {
			int x;
			if (isupper(a[i]))
				x = a[i] - 'A' + 10;
			else
				x = a[i] - '0';
			printf("%02d:", x);
			break;
		}
	}
	for (int i = 0; i < len2; i++) {
		if (c[i] == d[i] && isalpha(c[i])) {
			printf("%02d\n", i);
			break;
		}
	}
	return 0;
}
