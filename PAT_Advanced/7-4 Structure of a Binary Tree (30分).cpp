/*
7-4 Structure of a Binary Tree (30分)
这题应该是我写过的最炫酷的一题了，超长，并且在模拟中写了很多没考虑过的递归。
原来考试就考前序中序建树，然后后序遍历，这题着实让人无语，我一开始还觉得用太多string.find()
和substr()太容易超时了。这题本身就是考逻辑，其实我觉得可以拆成多个题目了， 不然之前没处理过的，
难度还是不小。
我看有人写了这题满分，第三题没写，当时大约1h10min，感觉还是很有信心的，写的时候，
前几个逻辑大约10min处理出来，后面的稍微简单些，5min做出来，最后还有7min的时候修改warning。
压线通过，太惊险了。
感觉几个函数不太好精简了，输出格式上可能还能优化，但是当时已经来不及美化了。
每次测试的时候，用好txt调整好后，进行复制粘贴，每次测试一个函数，逻辑要保持清晰。
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode( ) { };
    TreeNode(int v): val(v), left(nullptr), right(nullptr) { };
};
const int MAXN = 1005;
vector<int> postorder, inorder;
TreeNode* buildTree(int postL, int postR,int inL, int inR) {
    if(postR < postL) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(postorder[postR]);
    int mid = inL;
    for(; mid<= inR; ++ mid) {
        if(inorder[mid] == postorder[postR]) {
            break;
        }
    }
    int leftNum = mid - inL;
    root->left = buildTree(postL, postL+leftNum-1, inL, mid - 1);
    root->right = buildTree(postL+leftNum, postR-1, mid + 1, inR);
    return root;
}
bool isSiblings(TreeNode* root, int a, int b) {
    if(root == nullptr) {
        return false;
    }
    if(root->left && root->right) {
        if((root->left->val == a && root->right->val == b) || (root->left->val == b && root->right->val == a)) {
            return true;
        }
    }
    return isSiblings(root->left, a, b) || isSiblings(root->right, a, b);
}
bool isParent(TreeNode* root, int a, int b) { //if a is parent of b?
    if(root == nullptr) {
        return false;
    }
    bool lson = false;
    bool rson = false;
    if(root->val == a) {
        if(root->left && root->left->val == b) {
            lson = true;
        }
        if(root->right && root->right->val == b) {
            rson = true;
        }
    }
    //一开始这里rson写成了rchild了竟然还能通过编译，幸好有warning，之后纠错顺利AC
    return (lson || rson)? true: isParent(root->left, a, b) || isParent(root->right, a, b);
}
bool isLeftChild(TreeNode* root, int a, int b) { //if a is lchild of b?
    if(root == nullptr) {
        return false;
    }
    if(root->val == b) {
        if(root->left && root->left->val == a) {
            return true;
        } else {
            return false;
        }
    }
    return isLeftChild(root->left, a, b) || isLeftChild(root->right, a, b);
}
bool isRightChild(TreeNode* root, int a, int b) { //if a is rchild of b?
    if(root == nullptr) {
        return false;
    }
    if(root->val == b) {
        if(root->right && root->right->val == a) {
            return true;
        } else {
            return false;
        }
    }
    return isRightChild(root->left, a, b) || isRightChild(root->right, a, b);
}
void getDepth(TreeNode* root, int x, int d, int& ans) {
    if(!root) return;
    if(root->val == x) {
        ans = d;
        return;
    }
    getDepth(root->left, x, d+1, ans);
    getDepth(root->right, x, d+1, ans);
}
bool isFullTree(TreeNode* root) {
    if(root == nullptr) {
        return true;
    } else if(!root->left && !root->right) {
        return true;
    } else if(!root->left || !root->right) {
        return false;
    } else {
        return isFullTree(root->left) && isFullTree(root->right);
    }
}
void output(TreeNode* root, string& state) {
    if(state.substr(state.size()-4, 4) == "root") {
        puts(root->val == stoi(state)? "Yes": "No");
    } else if( state.substr(state.size()-8, 8) == "siblings") {
        int afterAnd = state.find("and") + 3;
        int a = stoi(state);
        int b = stoi(string(state, afterAnd));
        puts(isSiblings(root, a, b)? "Yes": "No");
    } else if(state.find("parent") != -1) {
        int afterOf = state.find("of") + 2;
        int a = stoi(state);
        int b = stoi(string(state, afterOf));
        puts(isParent(root, a, b)? "Yes": "No");
    } else if(state.find("left") != -1) {
        int afterOf = state.find("of") + 2;
        int a = stoi(state);
        int b = stoi(string(state, afterOf));
//        cout << a << " and " <<b << endl;
        puts(isLeftChild(root, a, b)? "Yes": "No");
    } else if(state.find("right") != -1) {
        int afterOf = state.find("of") + 2;
        int a = stoi(state);
        int b = stoi(string(state, afterOf));
        puts(isRightChild(root, a, b)? "Yes": "No");
    } else if(state.substr(state.size()-5, 5) == "level") {
        int afterAnd = state.find("and") + 3;
        int a = stoi(state);
        int b = stoi(string(state, afterAnd));
//        cout << a << " and b =  " <<b << endl;
        int aLevel,  bLevel;
        getDepth(root, a, 0, aLevel);
        getDepth(root, b, 0, bLevel);
//        cout << aLevel << "and " << bLevel << endl;
        puts(aLevel == bLevel? "Yes": "No");
    } else {
        puts(isFullTree(root)? "Yes": "No");
    }
}
int main() {
    int n, m, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        postorder.emplace_back(tmp);
    }
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        inorder.emplace_back(tmp);
    }
    TreeNode* root = buildTree(0, n-1, 0, n-1);
//    cout << root->val <<endl;
    scanf("%d", &m);
    getchar(); //吞掉换行符
    string state;
    for(int i = 0; i < m; ++ i) {
        getline(cin, state);
//        cout << state << endl;
        output(root, state);
    }
    return 0;
}
