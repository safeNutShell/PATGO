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

bool cmp(int a, int b) {
	return a < b;
}

int main() {
/*超时*/
	int n;
	cin >> n;
	stack<int> S;
	vector<int> v1, v2;
	string order;
	int data;
	while (n--) {
		cin >> order;
		if (order == "Push") {
			cin >> data;
			S.push(data);
			v1.push_back(data);
		}
		else if(order=="Pop"){
			if (S.size() == 0)
				cout << "Invalid" << endl;
			else {
				int tmp = S.top();
				cout << tmp << endl;
				S.pop();
				v1.pop_back();
			}
		}
		else if (order == "PeekMedian") {
			if (S.size() == 0)
				cout << "Invalid" << endl;
			else {
				v2 = v1;
				sort(v2.begin(), v2.end(), cmp);
				int ptr = (v2.size() % 2 == 0) ? v2.size() / 2 - 1 : (v2.size() + 1) / 2 - 1;
				cout << v2[ptr] << endl;
			}
		}
	}

	return 0;
}
/*
快速查找中间值，使用树状数组
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn=100010;
#define lowbit(x) ((x)&(-x))
int c[maxn]={0};
stack<int> st;
void update(int x,int n)
{
	for(int i=x;i<maxn;i+=lowbit(i))
		c[i]+=n;
}
int getSum(int k)
{
	int sum=0;
	for(int i=k;i>0;i-=lowbit(i))
	{
		sum+=c[i];
	}
	return sum;
}
void peek()
{
	int l=1,r=maxn,k=(st.size()+1)/2;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(getSum(mid)>=k)
			r=mid;
		else
			l=mid+1;
	}
	printf("%d\n",l);
}
int main()
{
	int n;
	char cmd[20];
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%s",cmd);
		if(!strcmp(cmd,"Pop"))
		{
			if(st.size()==0)
				printf("Invalid\n");
			else
			{
				printf("%d\n",st.top());
				update(st.top(),-1);
				st.pop();
			}
		}
		else if(!strcmp(cmd,"PeekMedian"))
		{
			if(st.size()==0)
				printf("Invalid\n");
			else
				peek();
		}
		else
		{
			int t;
			scanf("%d",&t);
			update(t,1);
			st.push(t);
		}
	}
	return 0;
}
*/

