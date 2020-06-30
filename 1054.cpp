#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int m, n, bound;
	cin >> m >> n;
	bound = m * n / 2;
	map<int, int>image;
	int pixel;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pixel;
			if (image.count(pixel) == 0)
				image[pixel] = 1;
			else
				image[pixel]++;
		}
	}
	map<int, int>::iterator it = image.begin();
	int dominant = -1;
	int index = -1;
	for (it; it != image.end(); it++) {
		if (it->second > dominant) {
			index = it->first;
			dominant = it->second;
		}
	}
	cout << index << endl;
	return 0;
}
