## 1107 Social Clusters (30分)

When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A **social cluster** is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

### Input Specification:

Each input file contains one test case. For each test case, the first line contains a positive integer *N* (≤1000), the total number of people in a social network. Hence the people are numbered from 1 to *N*. Then *N* lines follow, each gives the hobby list of a person in the format:

$K_i$: $h_i[1]$, $h_i[2]$, $\cdots$, $h_i[K_i]$

where $K_i$ (>0) is the number of hobbies, and $h_i[j]$ is the index of the *j*-th hobby, which is an integer in [1, 1000].

### Output Specification:

For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

### Sample Input:

```in
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4 
```

### Sample Output:

```out
3
4 3 1
```



### My Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 1005;
int hobby[MAXN];
int father[MAXN]; //root node less than 0, repersent the number it linked 
int FindRoot(int x) {
	if(father[x] < 0) {
		return x;
	} else {
		return father[x] = FindRoot(father[x]);
	}
}
void Union(int a, int b) {
	int aRoot = FindRoot(a);
	int bRoot = FindRoot(b);
	if(aRoot != bRoot) {
		if(father[aRoot] < father[bRoot]) {
			father[aRoot] += father[bRoot];
			father[bRoot] = aRoot;
		} else {
			father[bRoot] += father[aRoot];
			father[aRoot] = bRoot;
		}
	}
}
int cmp(int a, int b) {
	return a > b;
}
int Init() {
	fill(father, father + MAXN, -1);
	fill(hobby, hobby + MAXN, 0);
	int n, k, tmp;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d:", &k);
		while(k --) {
			scanf("%d", &tmp);
			if(hobby[tmp] == 0) { //set the first hobby one as hobby root
				hobby[tmp] = i;
			}
			Union(i, FindRoot(hobby[tmp])); //key code
		}
	}
	return n;
}
int main() {
	int n = Init();
	vector <int> vi;
	for(int i = 1; i <= n; ++ i) {
		if(father[i] < 0) {
			vi.push_back(-1 * father[i]);
		}
	}
	printf("%d\n", vi.size());
	sort(vi.begin(), vi.end(), cmp);
	for(int i = 0; i < vi.size(); ++ i) {
		printf("%d", vi[i]);
		printf((i == vi.size() - 1)?"\n": " ");
	}
	return 0;
} 
```



### 总结

本题考察**并查集**的基本操作，问题不是直接合并，而是根据节点的属性进行合并，这一点使题目稍微复杂化。但是也是几乎模板化的解决方案。我的习惯是使用`father`数组既表示父子关系，又能表示集合的大小，也就是让根节点为负数，同时根节点的绝对值是该集合的总结点树。合并的策略是让每一个人`i`与其所有的爱好的根节点（第一个表明喜欢该爱好的人）合并，最后输出`father`小于零的节点数，并按照从大到小的顺序数据它的绝对值。

