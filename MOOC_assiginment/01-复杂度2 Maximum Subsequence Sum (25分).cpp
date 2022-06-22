#include <iostream>
#include <algorithm>
using namespace  std;
const int MAXN = 10005;
class Node{
public: 
	int start;
	int total;
};
// note: this question exclude the back 0, but front 0.
int main() {
	int arr[MAXN];
	Node dp[MAXN];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i) {
		scanf("%d", &arr[i]);
	}
	dp[0].total = arr[0];
	dp[0].start = 0;
	int maxSum = arr[0];
	for(int i = 1; i < n; ++ i) {
		if(dp[i-1].total + arr[i] >= arr[i]) {
			dp[i].total = arr[i] + dp[i-1].total;
			dp[i].start = dp[i-1].start;
		} else {
			dp[i].start = i;
			dp[i].total = arr[i];
		}
		maxSum = max(maxSum, dp[i].total); //online mark the max
	}
	if(maxSum >= 0) {
		int last;
		for(int i = 0; i < n; ++ i) {
			if(dp[i].total == maxSum) {
				last = i;
				break;
			}
		}
		while(maxSum > 0 && arr[last]==0) {
			last --;
		}
		printf("%d %d %d\n", dp[last].total, arr[dp[last].start], arr[last]);
//		cout << "max = " << maxSum << endl;
//		for(int i = 0; i < n; ++ i) {
//			printf("%d %d %d\n", arr[i], dp[i].start, dp[i].total);
//		}
	} else {
		printf("0 %d %d\n", arr[0], arr[n-1]);
	}
	return 0;
}
