/*
7-4 Cartesian Tree (30分)
感觉是最近最简单的30分的题目。
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;
struct Node{
    int val;
    Node* lchild, *rchild;
    Node(int v) : val(v), lchild(nullptr), rchild(nullptr) { };
    Node( ) { };
};
vector<int> inorder;
Node* buildTree(int left, int right) {
    if(left > right) {
        return nullptr;
    }
    int rootPos = left; //getMinId
    for(int i = left; i <= right; ++ i) {
        if(inorder[i] < inorder[rootPos]) {
            rootPos = i;
        }
    }
    Node* root = new Node(inorder[rootPos]);
    root->lchild = buildTree(left, rootPos-1);
    root->rchild = buildTree(rootPos+1, right);
    return root;
}
vector<int> ans;
void levelTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int len = (int)q.size();
        for(int i = 0; i < len; ++ i) {
            Node* f = q.front();
            q.pop();
            ans.emplace_back(f->val);
            if(f->lchild) q.push(f->lchild);
            if(f->rchild) q.push(f->rchild);
        }
    }
}
void output(const vector<int>& vi) {
    int len = (int)vi.size();
    for(int i = 0; i < len; ++ i) {
        printf("%d", vi[i]);
        printf(i == len-1?"\n": " ");
    }
}
int main() {
    int n, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        inorder.emplace_back(tmp);
    }
    Node* root = buildTree(0, n-1);
    levelTraversal(root);
    output(ans);
    return 0;
}
