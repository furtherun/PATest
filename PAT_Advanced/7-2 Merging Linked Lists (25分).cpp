/*
7-2 Merging Linked Lists (25分)
这题比较无语，该插地址的结果忘了，这题按道理来说，应该再来装载一个L3
但是我受了惯性思维（我当年自己考的，那个时候还手推每个结点在L1和L2中的位置）
这次一开始也是想推，但是后来发现为何不使用两个指针呢？（本来也是打算使用vector的insert，
但是一方面平时从来没用过，第二就怕插一次时间复杂度O(n)吃不消）就是没有想起来可以再用空间换时间。
双指针的问题直接输出，但是忘了了短的有可能先结束（倒数第二个测试点3分），
最后在调整短链输出的过程又耽误了10min。就是容易犯一些低级错误，索性还剩3min的时候发现了。
这样就导致我的输出很麻烦。
更佳的做法，按照题目意思双指针构造L3（保存的是原来的地址），按顺序输出（注意尾结点）。
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 1E5+5;
struct Node{
    int data, address, next;
    Node( ) { };
    void getInfo(int a, int d, int n) {
        address = a;
        data = d;
        next = n;
    };
};
vector<Node> table(MAXN, Node());
int main() {
    int n, head1, head2;
    scanf("%d %d %d", &head1, &head2, &n);
    int tmpAdd, tmpData, tmpNext;
    for(int i = 0; i < n; ++ i) {
        scanf("%d %d %d", &tmpAdd, &tmpData, &tmpNext);
        table[tmpAdd].getInfo(tmpAdd, tmpData, tmpNext);
    }
    vector<int> L1, L2;
    int t = head1;
    while(t != -1) {
        L1.emplace_back(t);
        t = table[t].next;
    }
    t = head2;
    while(t != -1) {
        L2.emplace_back(t);
        t = table[t].next;
    }
    if(L2.size() < L1.size()) { //L1短, L2可能大于2倍的L1
        swap(L1, L2);
    }
    reverse(L1.begin(), L1.end());
    n = L1.size() + L2.size(); //新链表结点数
    int p = 0;
    int q = 0; //L1
    bool flag = false;

    for(int i = 0; i < n-1; ++ i) {
        if(i%3 == 0) {
            printf("%05d %d %05d\n", L2[p], table[L2[p]].data, L2[p+1]);
            p ++;
        } else if(i%3 == 1) {
            if(q == (int)L1.size()) {
//                cout << "L1 size  = " << L1.size() << endl;
                flag = true;
                break;
            }
            printf("%05d %d %05d\n", L2[p], table[L2[p]].data, L1[q]);
            p ++;
        } else {
            printf("%05d %d %05d\n", L1[q], table[L1[q]].data, L2[p]);
            q ++;
        }
    }
    if(flag) {
//        cout << "get here" << endl;
        while(p < (int)L2.size() - 1) {
            printf("%05d %d %05d\n", L2[p], table[L2[p]].data, L2[p+1]); //最后捞了3分p+1没注意到
            p ++;
        }
        printf("%05d %d -1\n", L2[p], table[L2[p]].data);
    } else {
        if((n-1)%3 < 2) {
            printf("%05d %d -1\n", L2[p], table[L2[p]].data);
        } else {
            printf("%05d %d -1\n", L1[q], table[L1[q]].data);
        }
    }
    return 0;
}
