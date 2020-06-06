#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#define INT_MAX 2147483647
using namespace std;

//每个窗口的处理队列
queue <int> Queue[20];
//每个窗口前的人数
int personNum[20] = { 0 };
//每个窗口当前处理时间
int consumedTime[20] = { 0 };
//每位顾客的处理时间
int processTime[1001] = { 0 };
//每位顾客应该离开的时间
int leaveTime[1001] = { 0 };
//每位顾客的查询结果
int response[1001] = { 0 };
//N表示窗口数，M表示黄线内等待数，K表示顾客数，Q表述有查询要求的顾客数
int N, M, K, Q;

int search() {
    int window = -1;
    int tmpPerson = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (personNum[i] < M && personNum[i] < tmpPerson) {
            window = i;
            tmpPerson = personNum[i];
        }
    }
    if (window == -1) {
        //同一时间点可能有多个人完成业务离开
        //需要使用客户的response属性值进行判断
        int windowToPop = 0;
        int a = Queue[windowToPop].front();
        int leaveTime = response[a];
        for (int i = 1; i < N; i++) {
            int tmp = Queue[i].front();
            if (response[tmp] < leaveTime) {
                windowToPop = i;
                leaveTime = tmp;
            }
        }
        for (int i = 0; i < N; i++) {
            if (i == windowToPop)
                continue;
            int tmp = Queue[i].front();
            if (leaveTime == response[tmp]) {
                Queue[i].pop();
                personNum[i] --;
            }
        }
        Queue[windowToPop].pop();
        personNum[windowToPop]--;
        window = windowToPop;
    }
    return window;
}

int main()
{
    //尚未完全AC
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &processTime[i]);
    }
    for (int i = 1; i <= K; i++) {
        int window = search();
        Queue[window].push(i);
        personNum[window]++;
        consumedTime[window] += processTime[i];
        response[i] = consumedTime[window];
    }
    for (int i = 1; i <= Q; i++) {
        int tmp;
        scanf("%d", &tmp);
        int time = response[tmp];
        int hour = 8 + time / 60;
        int min = time % 60;
        if (hour * 60 + min > 1020) {
            printf("%s\n", "Sorry");
        }
        else {
            printf("%02d:%02d\n", hour, min);
        }
    }

    return 0;
}
