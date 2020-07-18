/*
04-树5 Root of AVL Tree (25分)
2020 code
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct TreeNode{
    int val, height;
    TreeNode* left, *right;
    //一开始将新节点高度初始化为0了，一直出错
    TreeNode() : val(0), height(1), left(nullptr), right(nullptr) { };
    TreeNode(int v): val(v), height(1), left(nullptr), right(nullptr) { };
};
int getHeight(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    return root->height;
}
void updateHeight(TreeNode* root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getBalanceFactor(TreeNode* root) {
    return getHeight(root->left) - getHeight(root->right);
}
void leftRotation(TreeNode*& root) {
    TreeNode* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root); //root目前在下层
    updateHeight(tmp);
    root = tmp;
}
void rightRotation(TreeNode*& root) {
    TreeNode* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

TreeNode* insertIntoAVL(TreeNode* root, int val) {
    if(root == nullptr) {
        root = new TreeNode(val);
        return root;
    }
    if(val < root->val) {
        root->left = insertIntoAVL(root->left, val);
        updateHeight(root); //一开始写漏掉了，插入后需要更新高度
        if(getBalanceFactor(root) == 2) { //插入左子树只可能>1
            if(getBalanceFactor(root->left) == 1) {  //LL
                rightRotation(root);
//                cout << "right rotation, the now root is " <<root->val << endl;
            } else if(getBalanceFactor(root->left) == -1) {  //LR
                leftRotation(root->left);
                rightRotation(root);
            }
        }
    } else {
        root->right = insertIntoAVL(root->right, val);
        updateHeight(root); //一开始写漏掉了，插入后需要更新高度
        if(getBalanceFactor(root) == -2) {
            if(getBalanceFactor(root->right) == -1) { //RR
                leftRotation(root);
            } else if(getBalanceFactor(root->right) == 1) { //RL
                rightRotation(root->right);
                leftRotation(root);
            }
        }
    }
    return root;
}
int main()
{
    TreeNode* root = nullptr;
    int n, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i) {
        scanf("%d",&tmp);
        root = insertIntoAVL(root, tmp);
    }
    printf("%d\n", root->val);
    return 0;
}
/*
2017 - old code
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> vi;
class Node {
public:
	int value, height;
	Node* lchild, * rchild;
};
Node* newNode(int v) {
	Node* tmp = new Node;
	tmp->value = v;
	tmp->lchild = tmp->rchild = nullptr;
	tmp->height = 1;
	return tmp;
}
int getHeight(Node* root) {
	if (!root) return 0;
	return root->height;
}
int getBlanceFactor(Node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}
void updateHeight(Node* root) {
	//这里注意，节点的高度更新为比最高的子树还要高1
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
//学习AVL树的插入操作，如何进行平衡
void LeftRotation(Node*& root) {
	Node* tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
void RightRotation(Node*& root) {
	Node* tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
//只要把最靠近插入结点的失衡节点调整到正常，路径（从根节点到插入节点）上所有节点就会平衡
void Insert(Node*& root, int v) {
	if (!root) {
		root = newNode(v);
		return;
	}
	if (v < root->value) {
		Insert(root->lchild, v);
		updateHeight(root);
		if (getBlanceFactor(root) == 2) {
			if (getBlanceFactor(root->lchild) == 1) {
				RightRotation(root);
			}
			else {
				LeftRotation(root->lchild);
				RightRotation(root);
			}
		}
	}
	else {
		Insert(root->rchild, v);
		updateHeight(root);
		if (getBlanceFactor(root) == -2) {
			if (getBlanceFactor(root->rchild) == -1) {
				LeftRotation(root);
			}
			else {
				RightRotation(root->rchild);
				LeftRotation(root);
			}
		}
	}
}
int main() {
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		vi.push_back(tmp);
	}
	Node* root = newNode(vi[0]);
	for (int i = 1; i < n; ++i) {
		Insert(root, vi[i]);
	}
	cout << root->value << endl;
	return 0;
}
