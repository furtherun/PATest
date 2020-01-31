## 1113 Integer Set Partition (25分)



Given a set of *N* (>1) positive integers, you are supposed to partition them into two disjoint sets *A*1 and *A*2 of *n*1 and *n*2 numbers, respectively. Let *S*1 and *S*2 denote the sums of all the numbers in *A*1 and *A*2, respectively. You are supposed to make the partition so that ∣*n*1−*n*2∣ is minimized first, and then ∣*S*1−*S*2∣ is maximized.

### Input Specification:

Each input file contains one test case. For each case, the first line gives an integer *N* (2≤*N*≤105), and then *N* positive integers follow in the next line, separated by spaces. It is guaranteed that all the integers and their sum are less than 231.

### Output Specification:

For each case, print in a line two numbers: ∣*n*1−*n*2∣ and ∣*S*1−*S*2∣, separated by exactly one space.

### Sample Input 1:

```in
10
23 8 10 99 46 2333 46 1 666 555
```

### Sample Output 1:

```out
0 3611    
```

### Sample Input 2:

```in
13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
```

### Sample Output 2:

```out
1 9359
```



### My Code

```cpp
#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, tmp, total = 0, sum = 0;
	priority_queue <int> q;
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i) {
		scanf("%d", &tmp);
		q.push(tmp);
		total += tmp;
		if(i >= n/2) {
			sum += q.top();
//			cout << "test " << q.top() << endl;
			q.pop();
		}
	}
//	cout << "total = " << total << " sum = " << sum << endl;
	printf("%d %d\n", n%2 == 0? 0:1, 2*sum-total);
	return 0;
}
```



### 总结

这一题主要是理解题意如何处理两个极值，第二部分中从一个序列中求最大序列和最小序列甚至可以直接将整个序列排序，然后分别从前后取最大和最小。

而本次作为复习也是为了熟悉优先队列stl的使用，特意复杂化了一些，想要在读取数据的过程中进行筛选与求和。

需要强调的是`priority_queue <int> q`的写法与`priority_queue <int, vector<int>, less<int> > q`是一致的，都是**大元素优先高**，而如果想要小元素优先，则需要使用`greater<int>`来代替第三个参数，另外不太熟练的单词拼写要写对了，考试时的编辑器是没有提示的。