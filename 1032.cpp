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
    int add1, add2, N;
    map<int, int> ans;
    scanf("%d %d %d", &add1, &add2, &N);
    int curAdd, nextAdd;
    char c;
    for (int i = 0; i < N; i++) {
        scanf("%d %c %d", &curAdd, &c, &nextAdd);
        ans[curAdd] = nextAdd;
    }
    int joint = -1;
    int start = add1;
    while (add2 != -1) {
        while (add1 != -1) {
            if (add1 == add2) {
                joint = add1;
                break;
            }
            else {
                add1 = ans[add1];
            }
        }
        if (joint != -1)
            break;
        add2 = ans[add2];
        add1 = start;
    }
    printf("%d", joint);
    return 0;
}
