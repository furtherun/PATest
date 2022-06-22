/*
��Ŀ��1090 Highest Price in Supply Chain (25��) 
��һ��ʹ�õ����Զ����� - 1079 Total Sales of Supply Chain (25��) 
�ڶ��Σ����Σ�ʹ�õ����Ե����� - 1090 Highest Price in Supply Chain (25��) 
�Զ�������Ҫbfs�����»���ʹ��dfsһ��һ������
�Ե����ϸ���ʱ��Ҫע��ʹ�ü��仯��������·;�еĽ�㣨����ʱ�� 
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
