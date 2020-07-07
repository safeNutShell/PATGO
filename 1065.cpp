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
#include<set>
//#define INT_MAX 2147483647

using namespace std;


int main() {
	int n;
	cin >> n;
	long long int a, b, c;
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld",&a,&b,&c);
    //cin>>a>>b>>c;
    //必须用scanf，猜测可能是cin对longlong的输入处理有问题
		long long int tmp = a + b;
		bool flag;
		if (a > 0 && b > 0 && tmp < 0)
			flag = 1;
		else if (a < 0 && b < 0 && tmp>=0)
			flag = 0;
		else
			flag = tmp > c;
		printf("Case #%d: %s\n", i , flag ? "true" : "false");
	}
	return 0;
}
