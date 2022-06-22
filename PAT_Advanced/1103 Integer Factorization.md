## 1103 Integer Factorization (30分)

The *K*−*P* factorization of a positive integer *N* is to write *N* as the sum of the *P*-th power of *K* positive integers. You are supposed to write a program to find the *K*−*P* factorization of *N* for any positive integers *N*, *K* and *P*.

### Input Specification:

Each input file contains one test case which gives in a line the three positive integers *N* (≤400), *K*(≤*N*) and *P* (1<*P*≤7). The numbers in a line are separated by a space.

### Output Specification:

For each case, if the solution exists, output in the format:

```
N = n[1]^P + ... n[K]^P
```

where `n[i]` (`i` = 1, ..., `K`) is the `i`-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as $12^2$+$4^2$+$2^2$+$2^2$+$1^2$, or $11^2$+$6^2$+$2^2$+$2^2$+$2^2$, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { $a_1$,$a_2$, $\cdots$, $a_K$ } is said to be **larger** than { $b_1$,$b_2$, $\cdots$, $b_K$  } if there exists 1≤ *L* ≤ *K* such that $a_i = b_i$ for *i* <*L* and $a_L > b_L$.

If there is no solution, simple output `Impossible`.

### Sample Input 1:

```in
169 5 2
```

### Sample Output 1:

```out
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
```

### Sample Input 2:

```in
169 167 3 
```

### Sample Output 2:

```out
Impossible
```



### My Code

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const int MAXN = 405;
int n, k, p, len;
int arr[MAXN];
vector <int> ansVi, tmpVi;
int maxSum = -1; //max sum of all indexes

int Init(int n, int k, int p) {
	int len = 0;
	while(true) {
		int tmp = pow(len, p);
		arr[len ++] = tmp;
		if(tmp > n) {
			break;
		}
	}
	return len;
}
//total:the sum of arr[index]^p
//index:now id in arr, from right to left
//cnt:the num of indexes has been chosen(must less equal k)
//tmpSum:the sum of indexes(we should get the biggest one)
void dfs(int total, int index, int cnt, int tmpSum) {
	if(total > n || cnt > k) {
		return;
	}
	if(total == n && cnt == k) {
		if(tmpSum > maxSum) { //great not great equal
			ansVi = tmpVi;
			maxSum = tmpSum;
		}
		return;
	}
	if(index >= 1) {
		tmpVi.push_back(index);
		dfs(total + arr[index], index, cnt + 1, tmpSum + index);
		tmpVi.pop_back();
		dfs(total, index - 1, cnt, tmpSum);
	}
}
void Output() {
	if(maxSum == -1) {
		printf("Impossible\n");
	} else {
		printf("%d = ", n);
		for(auto i = 0; i < ansVi.size(); ++ i) {
			if(i > 0) {
				printf(" + ");
			}
			printf("%d^%d", ansVi[i], p);
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &k, &p);
	len = Init(n, k, p);
	dfs(0, len - 1, 0, 0);
	Output();
	return 0;
}
```



### 总结

一开始没有联想到是**DFS**处理，其实如果有这个意识，其实就可以注意到，要求是定总数量，定p次幂之和，求最大总和，这样的问题也就可以化为01背包问题，DFS是最简单、最暴力的一种求解方式，最可能考察的就是如何**剪枝**。看了别人的思路，但是还是在边界问题上出了些差错，前后修改几次，最后终于AC了，这类题目的抽象值得注意。