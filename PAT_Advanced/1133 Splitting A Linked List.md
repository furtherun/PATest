## 1133 Splitting A Linked List (25分)

Given a singly linked list, you are supposed to rearrange its elements so that all the negative values appear before all of the non-negatives, and all the values in [0, K] appear before all those greater than K. The order of the elements inside each class must not be changed. For example, given the list being 18→7→-4→0→5→-6→10→11→-2 and K being 10, you must output -4→-6→-2→7→0→5→10→18→11.

### Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤$10^5$) which is the total number of nodes, and a positive K (≤$10^3$). The address of a node is a 5-digit nonnegative integer, and NULL is represented by −1.

Then N lines follow, each describes a node in the format:

```
Address Data Next
```

where `Address` is the position of the node, `Data` is an integer in [−$10^5$,$10^5$], and `Next` is the position of the next node. It is guaranteed that the list is not empty.

### Output Specification:

For each case, output in order (from beginning to the end of the list) the resulting linked list. Each node occupies a line, and is printed in the same format as in the input.

### Sample Input:

```in
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
```

### Sample Output:

```out
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
```



### My Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
const int MAXN = 100000;
struct Node {
	int num;
	int next;
};
Node linkedTable[MAXN];
using namespace std;
int main() {
	int firstAdd, n, K;
	scanf("%d %d %d", &firstAdd, &n, &K);
	int tmpAdd, tmpNum, nextAdd;
	for (int i = 0; i < n; ++ i) {
		scanf("%d", &tmpAdd);
		scanf("%d %d", &linkedTable[tmpAdd].num, &linkedTable[tmpAdd].next);
	}
//	printf("...test...\n");
	int p = firstAdd;
//	while (p!=-1) {
//		printf("%d %d %d\n", p, linkedTable[p].num, linkedTable[p].next);
//		p = linkedTable[p].next;
//	}
    vector<int> vi; //keep the path of motified linkedTable
	while (p!=-1) {
		if(linkedTable[p].num < 0) {
//			printf("%d %d ", p, linkedTable[p].num);
			vi.push_back(p);
		}
//		printf("%d %d %d\n", p, linkedTable[p].num, linkedTable[p].next);
		p = linkedTable[p].next;
	}
	p = firstAdd;
	while (p!=-1) {
		if(linkedTable[p].num >=0 && linkedTable[p].num <=K) {
			vi.push_back(p);
		}
		p = linkedTable[p].next;
	}
	p = firstAdd;
	while (p!=-1) {
		if(linkedTable[p].num > K) {
			vi.push_back(p);
		}
		p = linkedTable[p].next;
	}
	for (auto i = 0; i < vi.size() - 1; i ++) {
		printf("%05d %d %05d\n", vi[i], linkedTable[vi[i]].num, vi[i + 1]);	
	}
    //take care of that not all nodes stay at the result linked array
    //the vi.size() maybe less than n, as the test node 4, I fail at first time
	printf("%05d %d -1\n", vi[vi.size() - 1], linkedTable[vi[vi.size() - 1]].num);
	return 0;
}
```



### 总结

链表的处理也是一道常规的题目，本题目也算比较简单，很快考虑到的思路，但是忘记了常规的测试点，也就是**有些点可能不在最后的输出链表**上，所以花费了一些时间才想起来这个易错点。

