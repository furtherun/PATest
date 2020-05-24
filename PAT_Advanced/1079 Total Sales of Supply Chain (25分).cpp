#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;
struct Node{
	int amount;
	vector<int> child;
};
void dfs(vector<Node>& tree, int index, double price, double rate, double& total) {
	if(tree[index].amount!= 0) {
		total += price * tree[index].amount;
		return;
	}
	int len = tree[index].child.size();
	for(int i = 0; i < len; ++ i) {
		dfs(tree, tree[index].child[i], price*(1+rate), rate, total);
	}
};
double dfsTraverse(vector<Node>& tree, int root, double price, double rate) {
	double total = 0;
	dfs(tree, root, price, rate, total);
	return total;
}
int main() {
	int n;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	vector<Node> staticTree(n);
	int tmp, k;
	for(int i = 0; i < n; ++ i) {
		scanf("%d", &k);
		if(k == 0) {
			scanf("%d", &tmp);
			staticTree[i].amount = tmp;
		} else {
			while(k--) {
				scanf("%d", &tmp);
				staticTree[i].child.push_back(tmp);
			}
		}
	}
	double totalSale = dfsTraverse(staticTree, 0, p, r*0.01);
	printf("%.1f\n", totalSale);
	return 0;
}
/*
超时原因分析：
因为对于每一个叶子结点，都需要计算他到根节点的距离 
*/
//struct Node{
//	int father;
//	int amount;
//	Node() {
//		father = -1;
//		amount = 0;
//	}
//};
//void backtrack(vector<Node>& tree, int index, int root, int amount,
//			   double price, double rate, double& total) {
//	if(index == root) { //向上查找到根节点 
//		total += price * amount;
//		return;
//	}
//	backtrack(tree, tree[index].father, root, amount, price*(1+rate), rate, total);
//}
//double getTotal(vector<Node>& tree, int root, double price, double rate) {
//	double total = 0;
//	int len = tree.size();
//	for(int i = 0; i < len; ++ i) {
//		if(tree[i].amount != 0) {
//			backtrack(tree, i, root, tree[i].amount, price, rate, total);
//		}
//	}
//	return total;
//}
////int findRoot(vector<Node>& tree) {
////	int len = tree.size();
////	int idx = -1;
////	for(int i = 0; i < len; ++ i) {
////		if(tree[i].father == -1) {
////			idx = i;
////			break;
////		}
////	}
////	return idx;
////}
//int main() {
//	int n, k, tmp;
//	double p, r;
//	scanf("%d %lf %lf", &n, &p, &r);
//	vector<int> staticTree(n);
//	for(int i = 0; i < n; ++ i) {
//		scanf("%d", &k);
//		if(k == 0) { //是零售商 
//			scanf("%d", &tmp);
//			staticTree[i].amount = tmp;
//		} else {
//			while(k--) {
//				scanf("%d", &tmp);
//				staticTree[tmp].father = i;
//			}
//		}
//	}
////	int root = findRoot(staticTree);
//	double totalSales = getTotal(staticTree, 0, p, r*0.01);
//	printf("%.1f", totalSales);
//	return 0;
//}
