#include <iostream>
using namespace std;
int main() {
	int n, tmp;
	int tmpSum = 0, maxSum = 0;
	scanf("%d", &n);
	while(n --) {
		scanf("%d", &tmp);
		tmpSum += tmp;
		if(tmpSum > maxSum) {
			maxSum = tmpSum;
		} else if(tmpSum < 0) {
			tmpSum = 0;
		}
	}
	cout << maxSum << endl;
	return 0;
}
