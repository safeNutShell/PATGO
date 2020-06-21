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

bool cmp(string a, string b) {
	return a < b;
}

int main() {
	int n, k;
	scanf("%d %d",&n,&k);
	map<int, vector<string>>course;
	char name[4];
	int count, no;
	for (int i = 0; i < n; i++) {
		scanf("%s %d",name,&count);
		for (int j = 0; j < count; j++) {
			scanf("%d",&no);
			course[no].push_back(name);
		}

	}
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0; j < course[i].size(); j++)
			printf("%s\n",course[i][j].c_str());
	}
	return 0;
}
