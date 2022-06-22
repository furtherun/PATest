## 1134 Vertex Cover (25分)



A **vertex cover** of a graph is a set of vertexes such that each edge of the graph is incident to at least one vertex of the set. Now given a graph with several vertex sets, you are supposed to tell if each of them is a vertex cover or not.

### Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers *N* and *M* (both no more than $10^4$), being the total numbers of vertexes and the edges, respectively. Then *M* lines follow, each describes an edge by giving the indexes (from 0 to *N*−1) of the two ends of the edge.

After the graph, a positive integer *K* (≤ 100) is given, which is the number of queries. Then *K* lines of queries follow, each in the format:

$N_v$ v[1] *v*[2] ⋯ v[$N_v$]

where $N_v$ is the number of vertexes in the set, and *v*[*i*]'s are the indexes of the vertexes.

### Output Specification:

For each query, print in a line `Yes` if the set is a vertex cover, or `No` if not.

### Sample Input:

```in
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2   
```

### Sample Output:

```out
No
Yes
Yes
No
No
```



### My Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 10000;
vector <int> graph[MAXN];
bool visited[MAXN];
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++ i) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int testNum, vertexSize;
	scanf("%d", &testNum);
	while (testNum --) {
		scanf("%d", &vertexSize);
		fill(visited, visited + n, 0);
		int edgeNum = 0;
		while (vertexSize --) {
			scanf("%d", &a);
			visited[a] = true;
			for (auto i: graph[a]) {
				if(visited[i] == false) {
					edgeNum ++;
				}
			}
		}
		bool flag = true;
		puts((edgeNum == m)? "Yes": "No");
	}
	return 0;
}
```



### 总结

本题考察的是处理图的边，以往更多的是处理点，对我来说有些新鲜感。自我感觉这一题应该用邻接表而不是邻接矩阵，因为规定了边数的范围，感觉使用邻接矩阵会超出内存。也没有使用固定的模板或是算法，同时也是比较直观的处理边的问题，虽然难度不大，但仍旧值得注意。

