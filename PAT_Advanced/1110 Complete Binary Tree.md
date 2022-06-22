## 1110 Complete Binary Tree (25分)

Given a tree, you are supposed to tell if it is a complete binary tree.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer *N* (≤20) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to *N*−1. Then *N* lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a `-` will be put at the position. Any pair of children are separated by a space.

### Output Specification:

For each case, print in one line `YES` and the index of the last node if the tree is a complete binary tree, or `NO` and the index of the root if not. There must be exactly one space separating the word and the number.

### Sample Input 1:

```in
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -   
```

### Sample Output 1:

```out
YES 8 
```

### Sample Input 2:

```in
8
- -
4 5
0 6
- -
2 3
- 7
- -
- - 
```

### Sample Output 2:

```out
NO 1
```



### My Code

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
const int MAXN = 25;
class TNode{
public:
	int lchild, rchild;
	TNode() {
		lchild = rchild = -1;
	}
};
bool isRoot[MAXN];
int completeBT[MAXN];
TNode tree[MAXN];
void dfs(int index, int root) {
    //index in static tree array, root in new build completeBT
	if(index == -1) {
		return;
	}
	completeBT[root] = index;
	dfs(tree[index].lchild, root * 2);
	dfs(tree[index].rchild, root * 2 + 1);
}
int main() {
	fill(isRoot, isRoot + MAXN, true);
	int n, child;
	char tmp[MAXN];
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i) { //Init
		scanf("%s", &tmp);
		if(strcmp(tmp, "-") != 0) {
			sscanf(tmp, "%d", &child);
			tree[i].lchild = child;
			isRoot[child] = false;
		}
		scanf("%s", &tmp);
		if(strcmp(tmp, "-") != 0) {
			sscanf(tmp, "%d", &child);
			tree[i].rchild = child;
			isRoot[child] = false;
		}
	}
	int root;
	for(int i = 0; i < n; ++ i) { //get root
//		printf("%d %d\n", tree[i].lchild, tree[i].rchild);
		if(isRoot[i] == true) {
			root = i;
			break;
		}
	}
	fill(completeBT, completeBT + MAXN, -1);
	dfs(root, 1); //static tree root in CBT cursor is 1
	int last = 0;
	for(int i = 1; i < MAXN; ++ i) {
//		printf("%d ", completeBT[i]);
		if(completeBT[i] != -1) {
			last = i;
		}
	}
	if(last == n) {
		printf("YES %d\n", completeBT[n]);
	} else {
		printf("NO %d\n", root);
	}
	return 0;
}
```



### 总结

本题考察了如何构造静态的完全二叉树（CBT)，用到了其中的技巧`parent=2*lchild`和`parent=2*rchild+1`。一开始没注意是否为CBT之后输出内容不一样，`YES`要输出的是最后一个节点，显然这需要构造出CBT。顺便一提，这里读入的节点号可能是2位数（范围是$N \le 20$），再次运用之前学的`sscanf`进行字符串和数值的转化。