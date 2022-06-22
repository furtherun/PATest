## 1106 Lowest Price in Supply Chain (25分)

A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price *P* and sell or distribute them in a price that is *r* % higher than *P*. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

### Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: *N* (≤105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to *N*−1, and the root supplier's ID is 0); *P*, the price given by the root supplier; and *r*, the percentage rate of price increment for each distributor or retailer. Then *N* lines follow, each describes a distributor or retailer in the following format:

*Ki* ID[1] ID[2] ... ID[*Ki*]

where in the *i*-th line, *Ki* is the total number of distributors or retailers who receive products from supplier *i*, and is then followed by the ID's of these distributors or retailers. *Kj* being 0 means that the *j*-th member is a retailer. All the numbers in a line are separated by a space.

### Output Specification:

For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 1010.

### Sample Input:

```in
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0  
```

### Sample Output:

```out
1.8362 2
```



### My Code

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 100005;
vector <int> tree[MAXN];
bool isRoot[MAXN];
int minDepth = MAXN;
int minNum = 0;
void dfs(int index, int depth) {
	if(tree[index].empty() || depth > minDepth) {
	//pruning the path that longer than now shortest one
		if(depth < minDepth) {
			minDepth = depth;
			minNum = 1;
		} else if(depth == minDepth) {
			minNum ++;
		}
		return;
	}
	int len = tree[index].size();
	for(int i = 0; i < len; ++ i) {
		dfs(tree[index][i], depth + 1);
	}
}
int main() {
	fill(isRoot, isRoot + MAXN, true);
	int n, leafNum, tmp;
	double price, rate;
	scanf("%d %lf %lf", &n, &price, &rate);
	for(int i = 0; i < n; ++ i) {
		scanf("%d", &leafNum);
		while(leafNum --) {
			scanf("%d", &tmp);
			isRoot[tmp] = false;
			tree[i].push_back(tmp);
		}
	}
	int root = 0;
	while(isRoot[root] == false) {
		root ++;
	}
	dfs(root, 0);
	double retPrice = price * pow(1 + 0.01 * rate, minDepth);
	printf("%.4f %d\n", retPrice, minNum);
	return 0;
}
```



### 总结

本题求树根到叶子的**最短路径条数和长度**，明白抽象结构后，很容易就使用*DFS*写出来了。

