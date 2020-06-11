#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

struct bign {
    int len;
    int d[100];
    bign() {
        len = 0;
        memset(d, 0, sizeof(d));
    }
};

bign convert(char s[]) {
    bign a;
    a.len = strlen(s);

    return a;
}

bign add(bign a) {
    bign c = bign();
    int carry = 0;
    for (int i = 0; i < a.len; i++) {
        int tmp = a.d[i] + a.d[a.len - 1 - i] + carry;
        c.d[c.len++] = tmp % 10;
        carry = tmp / 10;
    }
    if(carry != 0) {
        c.d[c.len++] = carry % 10;
    }
    return c;
}

bool judge(bign a) {
    for (int i = 0; i < a.len / 2; i++) {
        if (a.d[i] != a.d[a.len - 1 - i])
            return false;
    }
    return true;
}

int main() {
    //代码尚未AC，可能是输入的时候处理有问题
    int num;
    int k;
    scanf("%d%d", &num, &k);
    bign a;
    int ptr = 0;
    while (num != 0) {
        a.d[ptr++] = num % 10;
        num /= 10;
    }
    //len表示确切长度，而不是末尾指针
    a.len = ptr;
    int step;
    for (step = 0; step < k; step++) {
        if (judge(a)) {
            break;
        }
        a = add(a);
    }
    for (int i = a.len - 1; i >= 0; i--) {
        cout << a.d[i];
    }
    printf("\n%d\n", step);
    return 0;
}
