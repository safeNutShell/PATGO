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
	string s1, s2, ans;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.size(); i++) {
		if (s2.find(s1[i]) == string::npos) {
			ans += s1[i];
		}
	}
	cout << ans << endl;
	return 0;
}
