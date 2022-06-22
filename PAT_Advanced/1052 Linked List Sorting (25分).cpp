/*
1052 Linked List Sorting (25分)
没想到链表题早就出现过了
链表题应该算是比较模板化的题目了，这次才没想到几天没写
结果找bug还花了10min，也有可能是因为半夜状态不太好。姑且这样安慰自己吧。
看样子，不管是链表，树，还是图或者是筛素数、GCD和进制转换都是应该保持熟练。
这个题姑且作为链表的模板吧。
2020-08-07
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 100001;
struct Node{
    int val, next;
    //这个初始化顺序需要和定义的顺序保持一致否则报错
    Node(): val(0), next(-1) { };
};
vector<Node> nodeTable(MAXN, Node());
int cmp(int a, int b) {
//    if(nodeTable[a].val < nodeTable[b].val) {
//        return nodeTable[a].val < nodeTable[b].val;
//    }
    return nodeTable[a].val < nodeTable[b].val;
}
void output(const vector<int>& vi) {
    int len =(int)vi.size();
    printf("%d", len);
    if(len == 0) {
        printf(" -1\n");
        return;
    } else {
        printf(" %05d\n", vi[0]);
    }
    for(int i = 0; i < len-1; ++ i) {
        printf("%05d %d %05d\n", vi[i], nodeTable[vi[i]].val, vi[i+1]);
    }
    printf("%05d %d -1\n", vi[len-1], nodeTable[vi[len-1]].val);
}
int main() {
    int n, head, tmpAddr, tmpVal, tmpNext;
    scanf("%d %d",&n, &head);
    for(int i = 0; i < n; ++ i) {
        scanf("%d %d %d", &tmpAddr, &tmpVal, &tmpNext);
        nodeTable[tmpAddr].val = tmpVal;
        nodeTable[tmpAddr].next = tmpNext;
    }
    vector<int> arr;//初始化链表
    int p = head;
    while(p != -1) {
        arr.emplace_back(p);
        p = nodeTable[p].next;
    }
//    output(arr);
    sort(arr.begin(), arr.end(), cmp); //一开始一直忘了使用cmp
    output(arr);
    return 0;
}
