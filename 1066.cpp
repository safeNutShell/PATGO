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

struct node {
	int data, height;
	node* lchild;
	node* rchild;
	node(int v) :data(v), height(1), lchild(NULL), rchild(NULL) {

	}
};

int getHeight(node* root) {
	if (root == NULL)
		return 0;
	else
		return root->height;
}

void updateHeight(node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalance(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(node* &root) {
	node* tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void R(node* &root) {
	node* tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void insert(int val, node* &root) {
	if (root == NULL) {
		root = new node(val);
		return;
	}
	if (val < root->data) {
		insert(val, root->lchild);
		updateHeight(root);
		if (getBalance(root) == 2) {
			if (getBalance(root->lchild) == 1)
				R(root);
			else {
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		insert(val, root->rchild);
		updateHeight(root);
		if (getBalance(root) == -2) {
			if (getBalance(root->rchild) == -1)
				L(root);
			else {
				R(root->rchild);
				L(root);
			}
		}
	}
}

int main() {
	int n, t;
	cin >> n;
	node* root = NULL;
	while (n--) {
		cin >> t;
		insert(t, root);
	}
	cout << root->data << endl;
	delete root;
	return 0;
}
