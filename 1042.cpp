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
	string card[55] = { "X","S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
	"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
	"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
	"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
	"J1","J2" };
	string tmp[55];
	for (int i = 0; i < 55; i++)
		tmp[i] = card[i];
	int shuff[55] = { 0 };
	int times;
	cin >> times;
	for (int i = 1; i < 55; i++) {
		cin >> shuff[i];
	}
	for (int i = 0; i < times; i++) {
		for (int j = 1; j < 55; j++) {
			tmp[shuff[j]] = card[j];
		}
		for (int i = 0; i < 55; i++)
			card[i] = tmp[i];
	}
	for (int i = 1; i < 55; i++) {
		cout << card[i];
		if (i < 54)
			cout << " ";
		else if (i == 54)
			cout << endl;
	}
	return 0;
}
