/*
1099 Build A Binary Search Tree (30分)
当年的30分和现在的30分题目根本不是一个难度级别的。。。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
struct Node {
    int value, lchild, rchild;
    Node() :value(0), lchild(-1), rchild(-1) { };
    Node(int left, int right) : value(0), lchild(left), rchild(right) { };
};
vector<Node> tree;
vector<int> arr;
void inTraversal(int idx, int& p) {
    if(idx == -1) {
        return;
    }
    inTraversal(tree[idx].lchild, p);
    tree[idx].value = arr[p];
    ++ p;
    inTraversal(tree[idx].rchild, p);
}
vector<int> ans; //存储层序遍历id
void levelTraversal(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int len = q.size();
        for(int i = 0; i < len; ++ i) {
            int f = q.front();
            q.pop();
            ans.emplace_back(f);
            if(tree[f].lchild != -1) {
                q.push(tree[f].lchild);
            }
            if(tree[f].rchild != -1) {
                q.push(tree[f].rchild);
            }
        }
    }
}
int main()
{
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i) {
        scanf("%d %d", &a, &b);
        tree.emplace_back(Node(a, b));
    }
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &a);
        arr.emplace_back(a);
    }
    sort(arr.begin(), arr.end());
    a = 0;
//    for(int i = 0; i < n; ++ i) {
//        cout << arr[i] << endl;
//    }
    inTraversal(0, a);
    levelTraversal(0);
    for(int i = 0; i < n; ++ i) {
        printf("%d", tree[ans[i]].value); //一开始写成了tree[arr[i]].value
        printf(i == n-1?"\n": " ");
    }
    return 0;
}
