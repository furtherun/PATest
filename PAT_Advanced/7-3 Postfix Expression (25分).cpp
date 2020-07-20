/*
7-3 Postfix Expression (25分)
这题我记得当年是通过率最高的一道，但是我就是不知道怎么匹配括号
可能也是灵活性不足吧，虽然现在灵活性也不是很好。。。
这题因为之前看过别人的评论，但是没有看过别人的代码，
只是听说要注意左子树为空的情况，题目没说明，就看输出案例。好好理解递归。
原来出现过的那题（1130 Infix Expression (25分)），也是有些特殊吧，那个是根节点不输出括号。
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 25;
struct Node{
    string data;
    int left, right;
    Node() { };
    Node(string d, int lchild, int rchild): data(d), left(lchild), right(rchild) { };
};
vector<Node> tree;
void postTraversal(int root) {
    if(root == -1) {
        return;
    }
    if(tree[root].left == -1 && tree[root].right == -1) {
        printf("(%s)", tree[root].data.c_str());
    } else if(tree[root].left == -1 && tree[root].right != -1) {
        printf("(%s", tree[root].data.c_str());
        postTraversal(tree[root].right);
        printf(")");
    } else {
        printf("(");
        postTraversal(tree[root].left);
        postTraversal(tree[root].right);
        printf("%s)", tree[root].data.c_str());
    }
}
int main() {
    int n, left, right;
    string data;
    scanf("%d", &n);
    vector<int> visited(n, false);
    for(int i = 0; i < n; ++ i) {
        cin >> data;
        scanf("%d %d", &left, &right);
        if(left != -1) {
            left --;
            visited[left] = true;
        }
        if(right != -1) {
            right --;
            visited[right] = true;
        }
        tree.emplace_back(Node(data, left, right));
    }
    int root = 0;
    for(int i = 0; i < n; ++ i) {
        if(visited[i] == false) {
            root = i;
            break;
        }
    }
    postTraversal(root);
    return 0;
}
