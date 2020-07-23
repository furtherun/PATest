/*
7-2 Block Reversing (25分)
思路最好的题目，数据结构复习的时候有那个如何O(1)空间循环k位数组
感觉很像，稍微模拟一下，发现思路一致，很快就AC
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int MAXN = 100005;
struct Node{
    int value, next;
    Node() { };
    Node(int v, int n): value(v), next(n) { };
};
vector<Node> nodeTable(MAXN);
int main() {
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);
    int currAddr, currVal, nextAddr;
    for(int i = 0; i < n; ++ i) {
        scanf("%d %d %d", &currAddr, &currVal, &nextAddr);
        nodeTable[currAddr] = Node(currVal, nextAddr);
    }
    vector<int> linkedList;
    int p = head;
    while(p != -1) {
        linkedList.emplace_back(p);
        p = nodeTable[p].next;
    }
    int len = (int)linkedList.size();
    for(int i = 0; i < len; i += k) {
        reverse(linkedList.begin() + i, linkedList.begin()+min(i+k, len));
    }
    reverse(linkedList.begin(), linkedList.end());

    for(int i = 0; i < len-1; ++ i) {
        printf("%05d %d %05d\n", linkedList[i], nodeTable[linkedList[i]].value, linkedList[i+1]);
    }
    printf("%05d %d -1\n", linkedList[len-1], nodeTable[linkedList[len-1]].value);
    return 0;
}
