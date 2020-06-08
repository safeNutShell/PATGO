
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
//#define INT_MAX 2147483647

using namespace std;

typedef struct TreeNode* TNode;
struct TreeNode {
    int val;
    TNode left;
    TNode right;
    TreeNode(int a) {
        val = a;
        left = NULL;
        right = NULL;
    }
};
int postorder[30], inorder[30], levelorder[30];

TNode builder(int leftpost, int rightpost, int leftin, int rightin) {
    if (leftpost > rightpost || leftin > rightin) return NULL;
    TNode root = new TreeNode(postorder[rightpost]);
    int rootposition = leftin;
    while (rootposition <= rightin && inorder[rootposition] != postorder[rightpost]) rootposition++;
    int len = rootposition - leftin;
    root->left = builder(leftpost, leftpost + len - 1, leftin, rootposition - 1);
    root->right = builder(leftpost + len, rightpost - 1, rootposition + 1, rightin);
    return root;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> postorder[i];
    for (int i = 0; i < N; i++)
        cin >> inorder[i];
    TNode root = builder(0, N - 1, 0, N - 1);
    queue<TNode> Q;
    int ptr = 0;
    Q.push(root);
    while (!Q.empty()) {
        TNode tmp = Q.front();
        Q.pop();
        levelorder[ptr] = tmp->val;
        ptr++;
        if (tmp->left != NULL) Q.push(tmp->left);
        if (tmp->right != NULL) Q.push(tmp->right);
    }
    for (int i = 0; i < N; i++) {
        cout << levelorder[i];
        if (i != N - 1)
            cout << ' ';
        else
            cout << '\n';
    }
    return 0;
}
