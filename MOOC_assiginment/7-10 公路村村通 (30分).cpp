/*
2020-9-4
7-10 公路村村通 (30分)
最小生成树-Prim算法
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 1005;
const int INF = 0x7fffffff;
struct Edge{
    int a, b, cost;
    Edge(int x, int y, int c) : a(x), b(y), cost(c) { };
};
int cmp(const Edge& e1, const Edge& e2) {
    if(e1.cost != e2.cost) {
        return e1.cost < e2.cost;
    } else if(e1.a != e2.a) {
        return e1.a < e2.a;
    } else {
        return e1.b < e2.b;
    }
}

int main() {
    int n, m, a, b, cost;
    vector<Edge> edgeList;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++ i) {
        scanf("%d %d %d", &a, &b, &cost);
        edgeList.emplace_back(Edge(min(a, b), max(b, a), cost));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    unordered_set<int> hasExit;
    hasExit.insert(1);
    int ans = 0;
    for(int i = 1; i < n; ++ i) {
        bool isExitOneEdge = false;
        for(Edge& e : edgeList) {
            if(hasExit.find(e.a) != hasExit.end() && hasExit.find(e.b) == hasExit.end()) {
                hasExit.insert(e.b);
                ans += e.cost;
                isExitOneEdge = true;
                break;
            } else if(hasExit.find(e.b) != hasExit.end() && hasExit.find(e.a) == hasExit.end()) {
                hasExit.insert(e.a);
                ans += e.cost;
                isExitOneEdge = true;
                break;
            }
        }
        if(isExitOneEdge == false) {
            ans = -1;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}

/*
ode version
*/
#include <iostream>
#include <array>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1005;
int n, m;
class Eage
{
public:
    int id, weight;
    int v1, v2;
    Eage() = default;
    friend bool operator < (Eage e1, Eage e2) //友元函数这里是重点，重载运算符
    {
        return e1.weight > e2.weight; //这里的 > 是 weight 小的优先
    }
};

array <Eage, MAXN * 3> eSet;
array <int, MAXN> parent;
priority_queue <Eage> minHeap; //注意初始化写法，直接在友元函数中重载了排序方法，不需要用greater了 

void Init( );
bool CheakCycle(int v1, int v2);
int FindParent(int v);
int GetEage( );
void Kruskal();
void Union(int v1, int v2);

int main()
{
    Init();
    Kruskal();
    return 0;
}

void Union(int v1, int v2)
{
    int r1 = FindParent(v1), r2 = FindParent(v2);
    if (parent[r1] < parent[r2]) {
        parent[r1] += parent[r2];
        parent[r2] = r1;
    }
    else {
        parent[r2] += parent[r1];
        parent[r1] = r2;
    }
}

int GetEage( ) //得到最小权重边的代号
{
    int tmp = -1;
    if (!minHeap.empty()) {
        tmp = minHeap.top().id;
        minHeap.pop();
    }
    return tmp;
}

int FindParent(int v)
{
    int root = v, tmp;
    while (parent[root] > -1) {
        root = parent[root];
    }
    while (parent[v] > -1) { //压缩路径
        tmp = v;
        v = parent[v];
        parent[tmp] = root;
    }
    return root;
}

bool CheakCycle(int v1, int v2)
{
    int root1, root2;
    root1 = FindParent(v1);
    root2 = FindParent(v2);
    if (root1 == root2) return false; //这里是并查集的知识
    else {
        Union(root1, root2);
        return true;
    }
}

void Kruskal( )
{
    int totalWeight {}, ant{}, nextEage;
    fill(parent.begin(), parent.end(), -1); //初始化parent数组

    while (ant < n - 1) {
       nextEage = GetEage( );
        if (nextEage < 0) break;   //没有边则结束
        else if (CheakCycle(eSet[nextEage].v1, eSet[nextEage].v2) ) { //检测边的合法性
            totalWeight += eSet[nextEage].weight;
            ant ++;
        }
    }
    if (ant < n -1) {
        printf("-1\n");
    }
    else {
        printf("%d\n", totalWeight);
    }
}

void Init( )
{
    cin >> n >> m;
    for (int i = 0; i < m; ++ i) {
        cin >> eSet[i].v1 >> eSet[i].v2 >> eSet[i].weight;
        eSet[i].id = i;
        minHeap.push(eSet[i]);
    }
}
