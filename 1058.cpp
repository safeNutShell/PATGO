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
	int g1, s1, k1, g2, s2, k2;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	int k = (k1 + k2) % 29;
	int s = ((k1 + k2) / 29 + s1 + s2) % 17;
	int g = ((k1 + k2) / 29 + s1 + s2) / 17 + g1 + g2;
	printf("%d.%d.%d\n", g, s, k);
	return 0;
}
