/*
1135 Is It A Red-Black Tree (30分)
三目运算符要加括号！
这次写的并不好，我是考虑把黑结点数放到结构体中，插入时计算，但是似乎这一点有些问题后两个测试都过不去（21分）
看了之前的通过码，逻辑上几个判断都是一直的，就是对黑节点路径的理解，一开始想了递归统计处理，但没有这样做。
看着之前通过码修改了一个函数，通过了。并且发现三目运算符需要自己在外面加括号才能和别的运算搭配。
*/
#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int val;
    Node* left, *right;
    Node(int v) {
        val = v;
        left = right = nullptr;
    };
};
void insertInto(Node*& root, int x) {
    if(root == nullptr) {
        root = new Node(x);
        return;
    } else if(abs(root->val) < abs(x)) {
        insertInto(root->right, x);
    } else {
        insertInto(root->left, x);
    }
}
bool isCorrectRad(Node* root) {
    if(root == nullptr) {
        return true;
    } else if(root->val < 0) {
        if(root->left && root->left->val < 0) {
            return false;
        } else if(root->right && root->right->val < 0) {
            return false;
        }
    }
    return isCorrectRad(root->left) && isCorrectRad(root->right);
}
int getBlackNum(Node* root) {
    if(root == nullptr) return 1;
//    int tmp = max(getBlackNum(root->left), getBlackNum(root->right));
    return max(getBlackNum(root->left), getBlackNum(root->right)) + (root->val >0? 1: 0);
}
//int getBlackNum(Node* root) { //从叶子节点到该节点的路径黑色节点数，空节点为黑节点
//    if (root == nullptr) {
//        return 1;
//    }
//    int numL = getBlackNum(root->left);
//    int numR = getBlackNum(root->right);
//    return root->val > 0? max(numL, numR) + 1: max(numL, numR); //算上自生节点
//}
bool isSameBlackNode(Node* root) {
    if(root == nullptr) {
        return true;
    }
    return (getBlackNum(root->left) == getBlackNum(root->right)) && isSameBlackNode(root->left) && isSameBlackNode(root->right);
}
bool isRBT(Node* root) {
    return (root->val > 0) && isCorrectRad(root) && isSameBlackNode(root);
}
int main() {
	int k, n, tmp;
	scanf("%d", &k);
	while(k --) {
        scanf("%d", &n);
        Node* root = nullptr;
        for(int i = 0; i < n; ++ i) {
            scanf("%d", &tmp);
            insertInto(root, tmp);
        }
        puts(isRBT(root)?"Yes": "No");
	}
}
