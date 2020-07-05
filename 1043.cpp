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

bool flag = false;
vector<int> pre, post, tmp;

typedef struct node* TN;
struct node {
	int val;
	TN left, right;
};


void insert(TN &root, int data) {
	if (root == NULL) {
		root = new node;
		root->val = data;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (data < root->val)
		insert(root->left, data);
	else
		insert(root->right, data);
}

void preorder(TN root) {
	if (root == NULL)
		return;
	tmp.push_back(root->val);
	if (flag) {
		preorder(root->right);
		preorder(root->left);
	}
	else {
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TN root) {
	if (root == NULL)
		return;
	if (flag) {
		postorder(root->right);
		postorder(root->left);
	}
	else {
		postorder(root->left);
		postorder(root->right);
	}
	tmp.push_back(root->val);
}

int main() {
	int n;
	cin >> n;
	TN root = NULL;
	pre.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
		insert(root, pre[i]);
	}
	preorder(root);
	if (tmp != pre) {
		tmp.clear();
		flag = true;
		preorder(root);
	}
	if (tmp == pre) {
		tmp.clear();
		postorder(root);
		cout << "YES" << endl;
		for (int i = 0; i < tmp.size(); i++) {
			cout << tmp[i];
			if (i < tmp.size() - 1)
				cout << ' ';
			else
				cout << endl;
		}
	}
	else
		cout << "NO" << endl;
	return 0;
}
