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

int MaxSubseq(int nums[], int K, int &l, int &r) {
    int curSum, MaxSum = INT_MIN;//注意这里将综合初始化为INT_MIN而不是0，因为有可能最大和就是0甚至负数中的一个，所以初始化为最小int最为保险
    for (int i = 0; i < K; i++) {
        curSum = 0;
        for (int j = i; j < K; j++) {
            curSum += nums[j];
            if (curSum > MaxSum) {
                MaxSum = curSum;
                l = i;
                r = j;
            }
        }
    }
    return MaxSum;
}

int main()
{
    int K;
    cin >> K;
    int* nums = new int[K];
    for (int i = 0; i < K; i++) {
        cin >> nums[i];
    }
    bool isNegative = true;
    for (int i = 0; i < K; i++) {
        if (nums[i] >= 0)
            isNegative = false;
    }
    if (isNegative) {
        cout << '0' << ' ' << nums[0] << ' ' << nums[K - 1];
        return 0;
    }
    int l = 0;
    int r = 0;
    int MaxSum = MaxSubseq(nums, K, l, r);
    cout << MaxSum << ' ' << nums[l] << ' ' << nums[r];
    delete []nums;
    return 0;
}

//mark一个在线处理算法
//即，如果加上当前值是的总和变大，则更新各数指，如果变小则继续前行不更新，如果变为负则跳过此前重新计数
#include <cstdio>
#include <cstring>
const int maxn=10010;
 
struct node
{
	int start,end;
	int sum;
	int value;
}dp[maxn];
int main()
{
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;++i)
	{
		scanf("%d",&dp[i].value);
	}
	int maxsum=dp[0].value;
	dp[0].sum=dp[0].value;
	dp[0].start=0;
	dp[0].end=0;
	for(int i=1;i<k;++i)
	{
		if(dp[i].value+dp[i-1].sum>=dp[i].value)
		{
			dp[i].sum=dp[i].value+dp[i-1].sum;
			dp[i].start=dp[i-1].start;
			dp[i].end=i;
		}
		else
		{
			dp[i].sum=dp[i].value;
			dp[i].start=i;
			dp[i].end=i;
		}
		maxsum=maxsum>dp[i].sum?maxsum:dp[i].sum;
	}
	if(maxsum<0)
	{
		printf("0 %d %d\n",dp[0].value,dp[k-1].value);
	}
	else
	{
		printf("%d ",maxsum);
		for(int i=0;i<k;++i)
		{
			if(maxsum==dp[i].sum)
			{
				printf("%d %d\n",dp[dp[i].start].value,dp[dp[i].end].value);
				break;
			}
		}
	}
	return 0;
}

