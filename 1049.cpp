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
	long int n;
	cin >> n;
	int count = 0;
	for (long int i = 1; i <= n; i++) {
		string tmp = to_string(i);
		for (int j = 0; j < tmp.length(); j++) {
			if (tmp[j] == '1')
				count++;
		}
	}
	cout << count << endl;
	return 0;
}
