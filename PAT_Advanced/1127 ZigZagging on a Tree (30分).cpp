/*
1127 ZigZagging on a Tree (30分)
之前在Leet上get层序这样每次添加上一层的所有子节点，
一直都保持这个习惯，根据这个每次一层，进行奇偶反转即可。
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
struct Node{
    int val, height;
    Node* lchild, *rchild;
    Node() { };
    Node(int v) : val(v), height(1), lchild(nullptr), rchild(nullptr) { };
};
vector<int> ans, inorder, postorder;
Node* buildTree(int inL, int inR, int postL, int postR) {
    if(inL > inR) return nullptr;
    Node* root = new Node(postorder[postR]);
    int i = inL;
    for(; i <= inR; ++i) {
        if(inorder[i] == postorder[postR]) {
            break;
        }
    }
    int numL = i - inL;
    root->lchild = buildTree(inL, i - 1, postL, postL + numL - 1);
    root->rchild = buildTree(i + 1, inR, postL + numL, postR-1);
    return root;
}
void levelTraversal(Node* root) {
    bool isRightFirst = true;
    queue<Node*> q;
    q.push(root);
    int pre = 0;
    while(!q.empty()) {
        int len = (int)q.size();
        for(int i = 0; i < len; ++ i) {
            Node* f = q.front();
            ans.emplace_back(f->val);
            q.pop();
            if(f->lchild) q.push(f->lchild);
            if(f->rchild) q.push(f->rchild);
        }
        if(isRightFirst) {
            isRightFirst = false;
            reverse(ans.begin() + pre, ans.end());
        } else {
            isRightFirst = true;
        }
        pre += len;
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
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        postorder.emplace_back(tmp);
    }
    Node* root = buildTree(0, n-1, 0, n-1);
//    cout << "-- test --" << endl << root->val << endl;
    levelTraversal(root);
    output(ans);
    return 0;
}
