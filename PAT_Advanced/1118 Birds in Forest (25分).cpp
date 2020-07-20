/*
1118 Birds in Forest (25分)
这题着实，卧槽 
It is guaranteed that the birds in all the pictures are numbered continuously 
from 1 to some number that is no more than 10^4
然而，题目中的鸟有可能是不连续的。。。
本身并查集是比较简单的，但是谁要是考场上闹这一出，不得疯了；
所有数据都是不连续的，除了给的案例，这让人误会多大啊。
​​ .
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;
const int MAXN = 1E4 + 5;
vector<int> father(MAXN, -1);
int findSet(int x) {
    if(father[x] < 0) {
        return x;
    }
    return father[x] = findSet(father[x]);
}
void unionSet(int x, int y) {
    int xRoot = findSet(x);
    int yRoot = findSet(y);
    if(xRoot == yRoot) return;
    else if(father[xRoot] < father[yRoot]) {
        father[xRoot] += father[yRoot];
        father[yRoot] = xRoot;
    } else {
        father[yRoot] += father[xRoot];
        father[xRoot] = yRoot;
    }
}
int main()
{
    int n, q, k, a, b;
    int maxTree = 0;
    unordered_set<int> birds;
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i) {
        scanf("%d %d", &k, &a);
        birds.insert(a);
        while(-- k) {
            scanf("%d", &b);
            unionSet(a, b);
            birds.insert(b);
        }
    }
    for(const int& item: birds) {
        if(father[item] < 0) maxTree ++;
    }
    scanf("%d", &q);
    printf("%d %d\n", maxTree, (int)birds.size());
    while(q --) {
        scanf("%d %d", &a, &b);
        puts(findSet(a) == findSet(b)? "Yes": "No");
    }
    return 0;
}
