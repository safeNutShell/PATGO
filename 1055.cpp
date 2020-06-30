#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;

struct person {
	string name;
	int age, worth;
}q[100010];

bool cmp(person a, person b) {
	if (a.worth != b.worth)
		return a.worth > b.worth;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return a.name < b.name;

}

int main() {
	int n, k;
	cin >> n >> k;

	string Name;
	int Age, Worth;
	vector<person>data;
	while (n--) {
		cin >> Name >> Age >> Worth;
		person a;
		a.name = Name;
		a.age = Age;
		a.worth = Worth;
		data.push_back(a);
	}
	sort(data.begin(), data.end(), cmp);

  //年龄限制不言而喻，每个年龄又限制100人，因为查询的最大输出量就为100
  //不做筛选直接使用data的话，测试用例2会超时（猜测有死循环），但暂时不知原因
	int realnum = 0;
	int what[210] = { 0 };
	for (int i = 0; i < data.size(); i++) {
		if (data[i].age <= 200 && data[i].age > 0 && what[data[i].age] < 100) {
			what[data[i].age]++;
			q[realnum++] = data[i];
		}
	}

	int m, amin, amax;
	int no = 1;
	while (k--) {
		cin >> m >> amin >> amax;
		cout << "Case #" << no << ":" << endl;
		no++;
		int count = 0;
		for (int i = 0; i < realnum && count < m; i++) {
			if (q[i].age >= amin && q[i].age <= amax) {
				cout << q[i].name << ' ' << q[i].age << ' ' << q[i].worth << endl;
				count++;
			}
		}
		if (count == 0)
			cout << "None" << endl;
	}
	
	return 0;
}
