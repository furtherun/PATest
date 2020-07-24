/*
1123 Is It a Complete AVL Tree (30分)
AVL的操作和层序遍历
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
int getHeight(Node* root) {
    return root== nullptr? 0: root->height;
}
void updateHeight(Node*& root) {
    if(root == nullptr) return;
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBalancedFact(Node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}
void leftRotation(Node*& root) {
    Node* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
void rightRotation(Node*& root) {
    Node* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}
Node* insertIntoAVL(Node* root, int key) {
    if(root == nullptr) {
        root = new Node(key);
    } else if(root->val < key) {
        root->rchild = insertIntoAVL(root->rchild, key);
        updateHeight(root);
        if(getBalancedFact(root) == -2) { //R
            if(getBalancedFact(root->rchild) == -1) { //RR
                leftRotation(root);
            } else if(getBalancedFact(root->rchild) == 1) { //RL
                rightRotation(root->rchild);
                leftRotation(root);
            }
        }
    } else {
        root->lchild = insertIntoAVL(root->lchild, key);
        updateHeight(root);
        if(getBalancedFact(root) == 2) { //L
            if(getBalancedFact(root->lchild) == 1) { //LL
                rightRotation(root);
            } else if(getBalancedFact(root->lchild) == -1) { //LR
                leftRotation(root->lchild);
                rightRotation(root);
            }
        }
    }
    return root;
}
vector<int> ans;
bool levelTraversal(Node* root) {
    bool isCBT = true;
    bool isLastChild = false;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int len = (int)q.size();
        for(int i = 0; i < len; ++ i) {
            Node* f = q.front();
            ans.emplace_back(f->val);
            q.pop();
            if(f->lchild != nullptr) {
                q.push(f->lchild);
                if(isLastChild) isCBT = false;
            } else {
                isLastChild = true;
            }
            if(f->rchild != nullptr) {
                q.push(f->rchild);
                if(isLastChild) isCBT = false;
            } else {
                isLastChild = true;
            }
        }
    }
    return isCBT;
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
    Node* root = nullptr; //一开始忘了指向mullptr了导致出了bug
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        root = insertIntoAVL(root, tmp);
    }
//    cout << " -- test --" << endl;
//    cout << root->val << endl;
    bool flag = levelTraversal(root);
    output(ans);
    puts(flag?"YES": "NO");
    return 0;
}
