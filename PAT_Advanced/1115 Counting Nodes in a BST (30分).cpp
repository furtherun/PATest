/*
1115 Counting Nodes in a BST (30分)
读懂题目很简单的一道树的题目
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
struct Node {
    int value, depth;
    Node* left, *right;
    Node(): value(0), depth(0), left(nullptr), right(nullptr) { };
    Node(int v, int d): value(v), depth(d), left(nullptr), right(nullptr) { };
};
void insertIntoBST(Node*& root, int value, int& depth) {
    if(root == nullptr) {
        root = new Node(value, depth);
        return;
    }
    ++ depth;
    if(root->value < value) {
        insertIntoBST(root->right, value, depth);
    } else {
        insertIntoBST(root->left, value, depth);
    }
}
int main()
{
    int n, tmp;
    int tmpDepth, maxDepth = -1;
    vector<int> arr;
    Node* root = nullptr;
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        tmpDepth = 0;
        insertIntoBST(root, tmp, tmpDepth);
        arr.emplace_back(tmpDepth);
        maxDepth = max(maxDepth, tmpDepth);
    }
    int n1 = 0, n2 = 0;
    for(int i = 0; i < n; ++ i) {
        if(arr[i] == maxDepth) {
            n1 ++;
        } else if(arr[i] == maxDepth-1) {
            n2 ++;
        }
    }
    printf("%d + %d = %d\n", n1, n2, n1+n2);
    return 0;
}
