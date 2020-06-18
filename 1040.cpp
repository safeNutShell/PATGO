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
	string a;
	getline(cin, a);
	int count = 1;
	for (int i = 0; i < a.length(); i++) {
		int tmp = 1;
		int l, r;
		l = i - 1;
		r = i + 1;
		while (l >= 0 && r <= a.length() - 1) {
			if (a[l] == a[r]) {
				tmp += 2;
				l--;
				r++;
			}
			else
				break;
		}
		count = tmp > count ? tmp : count;
		tmp = 0;
		l = i;
		r = i + 1;
		while (l >= 0 && r <= a.length()) {
			if (a[l] == a[r]) {
				tmp += 2;
				l--;
				r++;
			}
			else
				break;
		}
		count = tmp > count ? tmp : count;
	}
	cout << count << endl;
	return 0;
}
