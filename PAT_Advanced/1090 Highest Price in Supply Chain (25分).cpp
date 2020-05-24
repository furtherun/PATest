/*
题目：1090 Highest Price in Supply Chain (25分) 
第一次使用的是自顶向下 - 1079 Total Sales of Supply Chain (25分) 
第二次（本次）使用的是自底向上 - 1090 Highest Price in Supply Chain (25分) 
自顶向下需要bfs逐层更新或者使用dfs一条一条更新
自底向上更新时需要注意使用记忆化处理，更新路途中的结点（否则超时） 
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution{
public:
	int n, root;
//	static constexpr int MAXN = 0x7fffffff;
	double price, rate;
	vector<int> father;
	vector<int> depth;
	void input() {
		int tmp;
		scanf("%d %lf %lf", &n, &price, &rate);
		depth.resize(n, -1);
		for(int i = 0; i < n; ++ i) {
			scanf("%d", &tmp);
			father.emplace_back(tmp);
			if(tmp == -1) {
				depth[i] = 0;
				root = i;
			}
		}
	};
	int backtrack(int idx) {
		if(depth[idx] == -1) {
			return depth[idx] = backtrack(father[idx]) + 1;
		}
		return depth[idx];
	}
	int findMaxDepth(int root) {
		int tmpDepth = 0;
		int ansDepth = 0;
		for(int i = 0; i < n; ++ i) {
			tmpDepth = backtrack(i);
			ansDepth = max(ansDepth, tmpDepth);
		}
		return ansDepth;
	}
	int getDepthNodeNum(int d) {
		int cnt = 0;
		for(const int& it: depth) {
			if(it == d) {
				cnt ++;
			}
		}
		return cnt;
	}
	void output() {
		int ansDepth = findMaxDepth(root);
		int number = getDepthNodeNum(ansDepth);
		printf("%.2f %d\n", price*pow((1+0.01*rate), ansDepth), number);
	}
	void run() {
		input();
		output();
	};
};
int main() {
	Solution* s = new Solution();
	s->run();
	return 0;
}
