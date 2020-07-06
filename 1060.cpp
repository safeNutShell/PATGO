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
	int n;
	double a, b;
	cin >> n >> a >> b;
	int expa = 0, expb = 0;
	if (a > 1) {
		while (a > 1) {
			expa++;
			a /= 10;
		}
	}
	else if (a < 0.1 && a > 0) {
		while (a < 0.1) {
			expa--;
			a *= 10;
		}
	}
	if (b > 1) {
		while (b > 1) {
			expb++;
			b /= 10;
		}
	}
	else if (b < 0.1 && b > 0) {
		while (b < 0.1) {
			expb--;
			b *= 10;
		}
	}
	string A = to_string(a).substr(0, 2 + n);
	string B = to_string(b).substr(0, 2 + n);
	if (A == B && expa == expb) {
		cout << "YES " << A << "*10^" << expa << endl;
	}
	else {
		cout << "NO " << A << "*10^" << expa << ' ' << B << "*10^" << expb << endl;
	}
	return 0;
}
