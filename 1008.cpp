#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int* nums = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    int cur = 0;
    int cost = 0;
    //对数组进行遍历即可，ez
    for (int i = 0; i < N; i++) {
        int gap = nums[i] - cur;
        if (gap >= 0) {
            cost += 6 * gap;
        }
        else {
            cost += 4 * abs(gap);
        }
        cur = nums[i];
    }
    cost += 5 * N;
    cout << cost << endl;
    return 0;
}
