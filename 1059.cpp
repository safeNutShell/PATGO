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

const int maxn = 100010;
int flag[maxn] = { false }, prime[maxn];
int primeNum = 0;

void findPrime() {
	flag[0] = flag[1] = true;
	for (int i = 2; i < maxn; i++) {
		if (flag[i] == false) {
			prime[primeNum++] = i;
			for (int j = i + i; j < maxn; j += i)
				flag[j] = true;
		}
	}
}

struct p {
	int exp;
	int num;
}num[10];

int main() {
	findPrime();
	int n;
	cin >> n;
	if (n == 1)
		cout << "1=1" << endl;
	else {
		cout << n << "=";
		int bound = (int)sqrt(n);
		int c = 0;
		for (int i = 0; prime[i] < bound; i++) {
			if (n % prime[i] == 0) {
				num[c].exp = 0;
				num[c].num = prime[i];
				while (n % prime[i] == 0) {
					num[c].exp++;
					n /= prime[i];
				}
				c++;
			}
		}
		if (n != 1) {
			num[c].num = n;
			num[c++].exp = 1;
		}
		if (num[0].exp == 1)
			cout << num[0].num;
		else
			cout << num[0].num << "^" << num[0].exp;
		for (int i = 1; i < c; i++) {
			if (num[i].exp == 1)
				cout << "*" << num[i].num;
			else
				cout << "*" << num[i].num << "^" << num[i].exp;
		}
		cout << endl;
	}
	return 0;
}
