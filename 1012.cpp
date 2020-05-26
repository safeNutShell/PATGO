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
int N, M;

int vecChecker(vector<pair<int, int>> v, int target) {
    int rank = 1;
    vector<pair<int, int>>::reverse_iterator it;
    //首先根据学号匹配找到学生
    for (it = v.rbegin(); it != v.rend(); it++) {
        if (it->second == target)
            break;
        rank++;
    }
    //如果找到学生，再处理一下分数并列的情况，注意不要越界
    if (it != v.rend()) {
        int thisScore = it->first;
        while (rank!=1) {
            it--;
            if (it->first == thisScore) {
                rank--;
            }
            else {
                break;
            }
        }
    }
    //否则认为排名中没有这个学生，根据题意将输出N/A
    else
        rank = N + 1;

    return rank;
}

//辅助单个学生各科成绩排名，指定对p.first进行从小到大排序，first指的是各科排名
bool cmpRes(pair<int, char>p1, pair<int, char>p2) {
    return p1.first < p2.first;
}

//辅助对每科成绩的所有学生进行排名，指定对p.first进行从小到大排序，first指的是该科目各个学生的分数
bool cmpVec(pair<int, int>p1, pair<int, int>p2) {
    return p1.first < p2.first;
}

int main()
{
    //第一次没有选择正确的STL，使用map的问题是它不能存储重复的数据，而分数明显是可以重复的
    //但不变的是pair中first存储分数，second存储ID，因此排序针对first
    vector<pair<int, int>>va;
    vector<pair<int, int>>vc;
    vector<pair<int, int>>vm;
    vector<pair<int, int>>ve;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int ID, C, M, E, A;
        cin >> ID;
        cin >> C;
        cin >> M;
        cin >> E;
        A = (C + M + E) / 3;
        va.push_back({ A,ID });
        vc.push_back({ C,ID });
        vm.push_back({ M,ID });
        ve.push_back({ E,ID });
    }
    //由于vector存储时没有map那么方便（红黑树存储自动排序），因此需要手动调用排序，注意要用stable_sort
    //前两个参数表示排序对象的起始，第三个参数是可选的，不过最好加上以明确定义排序的对象和从大到小/从小到大
    //stable_sort包含在头文件<algorithm> 中
    stable_sort(va.begin(), va.end(), cmpVec);
    stable_sort(vc.begin(), vc.end(), cmpVec);
    stable_sort(vm.begin(), vm.end(), cmpVec);
    stable_sort(ve.begin(), ve.end(), cmpVec);

    int* check = new int[M];
    for (int i = 0; i < M; i++)
        cin >> check[i];
    for (int i = 0; i < M; i++) {
        int tmp = check[i];
        //获取当前学生的各科分数排名
        int rankA = vecChecker(va, tmp);
        int rankC = vecChecker(vc, tmp);
        int rankM = vecChecker(vm, tmp);
        int rankE = vecChecker(ve, tmp);
        //这里对结果进行排序而且要求排序是稳定的
        vector<pair<int, char>>v;
        v.push_back({ rankA,'A' });
        v.push_back({ rankC,'C' });
        v.push_back({ rankM,'M' });
        v.push_back({ rankE,'E' }); 
        //稳定排序保证科目间的优先级
        stable_sort(v.begin(), v.end(),cmpRes);
        if (v[0].first == N + 1) {
            cout << "N/A" << endl;
        }
        else {
            cout << v[0].first << ' ' << v[0].second << endl;
        }
    }

    return 0;
}
