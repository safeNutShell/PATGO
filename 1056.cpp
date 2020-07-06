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
//#define INT_MAX 2147483647
using namespace std;

const int maxn = 1010;
struct mouse {
	int rank, weight;
}mice[maxn];

int main() {
	int np, ng, t;
	cin >> np >> ng;
	for (int i = 0; i < np; i++)
		cin >> mice[i].weight;
	queue<int>q;
	for (int i = 0; i < np; i++) {
		cin >> t;
		q.push(t);
	}
	int tmp = np, group;
	while (q.size() != 1) {
		if (tmp % ng == 0)
			group = tmp / ng;
		else
			group = tmp / ng + 1;
		for (int i = 0; i < group; i++) {
			int x = q.front();
			for (int j = 0; j < ng; j++) {
				if (i * ng + j >= tmp)
					break;
				int front = q.front();
				if (mice[front].weight > mice[x].weight) {
					x = front;
				}
				mice[front].rank = group + 1;
				q.pop();
			}
			q.push(x);
		}
		tmp = group;
	}
	mice[q.front()].rank = 1;
	for (int i = 0; i < np; i++) {
		cout << mice[i].rank;
		if (i < np - 1)
			cout << ' ';
		else
			cout << endl;
	}
	return 0;
}
