## 1102 Invert a Binary Tree (25分)

The following is from Max Howell @twitter:

> Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.

Now it's your turn to prove that YOU CAN invert a binary tree!

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer *N* (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to *N*−1. Then *N* lines follow, each corresponds to a node from 0 to *N*−1, and gives the indices of the left and right children of the node. If the child does not exist, a `-` will be put at the position. Any pair of children are separated by a space.

### Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

### Sample Input:

```in
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6  
```

### Sample Output:

```out
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
```



### My Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class TNode {
public:
	int lchild, rchild;
	TNode() {
		lchild = rchild = -1;
	}
};
const int MAXN = 12;
vector <int> inTraversal;
vector <int> layerTraversal;
bool isRoot[MAXN];

void inorder(TNode* t, int root) {
	if (t[root].lchild != -1) {
		inorder(t, t[root].lchild);
	}
	inTraversal.push_back(root);
	if (t[root].rchild != -1) {
		inorder(t, t[root].rchild);
	}
}
void layerorder(TNode* t, int root) {
	queue <int> q;
	q.push(root);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		layerTraversal.push_back(front);
		if(t[front].lchild != -1) {
			q.push(t[front].lchild);
		}
		if(t[front].rchild != -1) {
			q.push(t[front].rchild);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	TNode mirrorTree[MAXN];
	char tmp;
	fill(isRoot, isRoot + MAXN, true);  //mark the root of static tree
	for (int i = 0; i < n; ++ i) {
		tmp = getchar();
//		cout << "tmp = " << tmp << endl;
		getchar();
		if (tmp == '-') {
			mirrorTree[i].rchild = -1;
		} else {
			mirrorTree[i].rchild = tmp - '0';
			isRoot[mirrorTree[i].rchild] = false;
		}
		tmp = getchar();
//		cout << "tmp = " << tmp << endl;
		getchar();
		if (tmp == '-') {
			mirrorTree[i].lchild = -1;
		} else {
			mirrorTree[i].lchild = tmp - '0';
			isRoot[mirrorTree[i].lchild] = false;
		}
	}
	int root = 0;
	for (int i = 0; i < n; ++ i) {
		if(isRoot[i]) {
			root = i;
			break;
		}
	}
//	cout << "root = " << root << endl;
	layerorder(mirrorTree, root);
	inorder(mirrorTree, root);
	for (int i = 0; i < n; ++ i) {
		cout << layerTraversal[i];
		printf(i == n-1? "\n": " ");
	}
	for (int i = 0; i < n; ++ i) {
		cout << inTraversal[i];
		printf(i == n-1? "\n": " ");
	}
	return 0;
}
```



### 总结

没想到好久没写、比较复杂的层序遍历一次就写过了，反而中序遍历出了点错误，笑。本题考察了**树的静态存储**和**中序遍历**和**层序遍历**，顺带着有学会**寻找树的根节点**（排除法判断哪一个不是子节点）。比较中规中矩，而且数据量比较小，可以随心所欲写结构。值得一提的是，在读入数据的阶段，单个字符串的`getchar()`会读入` `以及`\n`，所以一开始在这里费了些心思。