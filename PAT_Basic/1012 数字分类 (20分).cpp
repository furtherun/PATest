#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 5;
int main() {
	int n, tmp;
	scanf("%d", &n);
	bool isVisited[5];
	int A[5];
	fill(isVisited, isVisited+MAXN, false);
	fill(A, A+MAXN, 0);
	int mask = 1; //for A[1]
	int cnt = 0; //for A[3]
	while(n--) {
		scanf("%d", &tmp);
		switch(tmp%5) {
			case 0:
				if(tmp%2==0) {
					A[0] += tmp;
					isVisited[0] = true;
				}
				break;
			case 1:
				A[1] += (mask * tmp);
				mask *= -1;
				isVisited[1] = true;
				break;
			case 2:
				A[2] ++; //count the num of tmp % 5 == 2
				isVisited[2] = true;
				break;
			case 3:
				A[3] += tmp; //caculate the average of A[3]
				cnt ++;
				isVisited[3] = true;
				break;
			case 4:
				A[4] = max(A[4], tmp);
				isVisited[4] = true;
				break;
		}
	}
	for(int i = 0; i < MAXN; ++ i) {
		if(isVisited[i]) {
			if(i==3) {
				printf("%.1f", A[3]*1.0/cnt);
			} else {
				printf("%d", A[i]);
			}
		} else {
			printf("N");
		}
		printf(i != MAXN-1? " ":"\n");
	}
	return 0;
}
