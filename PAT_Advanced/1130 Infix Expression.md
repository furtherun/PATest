## 1130 Infix Expression (25分)

Given a syntax tree (binary), you are supposed to output the corresponding infix expression, with parentheses reflecting the precedences of the operators.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20) which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of a node (the *i*-th line corresponds to the *i*-th node) in the format:

```
data left_child right_child
```

where `data` is a string of no more than 10 characters, `left_child` and `right_child` are the indices of this node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by −1. The figures 1 and 2 correspond to the samples 1 and 2, respectively.

| ![infix1.JPG](https://images.ptausercontent.com/4d1c4a98-33cc-45ff-820f-c548845681ba.JPG) | ![infix2.JPG](https://images.ptausercontent.com/b5a3c36e-91ad-494a-8853-b46e1e8b60cc.JPG) |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
|                           Figure 1                           |                           Figure 2                           |

### Output Specification:

For each case, print in a line the infix expression, with parentheses reflecting the precedences of the operators. Note that there must be no extra parentheses for the final expression, as is shown by the samples. There must be no space between any symbols.

### Sample Input 1:

```in
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
```

### Sample Output 1:

```out
(a+b)*(c*(-d))  
```

### Sample Input 2:

```in
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1  
```

### Sample Output 2:

```out
(a*2.35)+(-(str%871))
```



### My Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int MAXN = 25;
class TNode{
public:
	string date;
	int lchild, rchild;
	TNode() {
		lchild = rchild = -1;
	}
};
bool isRoot[MAXN];
void Inorder(TNode* t, int index, int root) {
	if(index == -1) return;
	if(index != root && (t[index].lchild != -1 || t[index].rchild != -1)) {
		printf("(");
	}
	Inorder(t, t[index].lchild, root);
	cout << t[index].date;
	Inorder(t, t[index].rchild, root);
	if(index != root && (t[index].lchild != -1 || t[index].rchild != -1)) {
		printf(")");
	}
}
int main() {
	TNode tree[MAXN];
	string tmp;
	fill(isRoot, isRoot + MAXN, true);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		cin >> tree[i].date >> tree[i].lchild >> tree[i].rchild;
		if(tree[i].lchild != -1) {
			isRoot[tree[i].lchild] = false;
		}
		if(tree[i].rchild != -1) {
			isRoot[tree[i].rchild] = false;
		}
	}
	int root = 1;
	while (isRoot[root] == false) {
		root ++;
	}
	Inorder(tree, root, root);
	return 0;
}
```



### 总结

今年（2019年）9月的真题是写一个后缀表达式，考场上看了一眼就感觉自己不知道如何匹配括号，就舍弃了。反而这道题就是整场考试通过率最高的，我就只拿了1分。让我震惊的是，这个不仅有原型体，而且就在我刷题的上面两道，从前刷、从后刷，结果漏了要考的题目，也确实是自己复习不充分、不全面。

本题内容上有树的静态写法，寻找根节点和中序遍历输出节点和括号这三部分，对于括号的匹配，确实需要考前积累些经验才能在考场上快速处理。

