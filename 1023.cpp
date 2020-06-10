#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

int main() {
    string num;
    cin >> num;
    int a[30] = { 0 };
    int b[30] = { 0 };
    for (int i = num.size() - 1; i >= 0; i--) {
        a[num.size() - 1 - i] = num[i] - '0';
    }
    int carry = 0;
    int ptr = 0;
    for (ptr; ptr < num.size(); ptr++) {
        int now = a[ptr] * 2 + carry;
        b[ptr] = now % 10;
        carry = now / 10;
    }
    ptr--;
    if (carry != 0) {
        cout << "No" << endl;
    }
    else {
        int recorda[10] = { 0 };
        int recordb[10] = { 0 };
        for (int j = 0; j <= ptr; j++) {
            recorda[a[j]]++;
            recordb[b[j]]++;
        }
        bool flag = true;
        for (int k = 0; k < 10; k++) {
            if (recorda[k] != recordb[k]) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    for (int k = ptr; k >= 0; k--) {
        printf("%d", b[k]);
    }
    cout << endl;
    return 0;
}
