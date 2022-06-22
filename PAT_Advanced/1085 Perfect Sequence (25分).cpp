/*
* 滑动窗口 
*/ 
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> 
using namespace std;
class Solution {
public:
	vector<int> nums;
	int n;
	int tmp;
	long long p;
	void input() {
		scanf("%d %lld", &n, &p);
		for(int i = 0; i < n; ++ i) {
			scanf("%d", &tmp);
			nums.emplace_back(tmp);
		}
		sort(nums.begin(), nums.end());
	}
	int maxWin() {
		int ans = 0;
		int left = 0;
		int right = 0;
//		nums.emplace_back(INT_MAX); //保证最后一个节点参与运算 
		int len = (int)nums.size();
//		cout << nums[left] * p << endl << LLONG_MAX << endl;
		while(right < len) {
			if(p*nums[left] < nums[right]) {
				ans = max(ans, right-left);
				++ left;
				continue;
			}
			++ right;
		}
		if(p*nums[left] >= nums[len-1]) {
			ans = max(ans, len-left);
		}
		return ans;
	}
	void output(int ans) {
		printf("%d\n", ans);
	}
	void run() {
		input();
		output(maxWin());
	}
};
int main() {
	Solution* s = new Solution();
	s->run();
	return 0;
}
