/*
7-4 Replacement Selection (30分)
说实话题目描述的置换选择排序过程，如果一开始自己并没有了解过，还是会容易想错。
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
void output(const vector<int>& vi) {
    int len = (int)vi.size();
    for(int i = 0; i < len; ++ i) {
        printf("%d", vi[i]);
        printf(i==len-1? "\n": " ");
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    priority_queue<int, vector<int>, greater<int>> curr, post;
    int tmp;
    for(int i = 0; i < m; ++ i) {
        scanf("%d", &tmp);
        curr.push(tmp);
    }
    vector<int> arr;
    for(int j = m; j < n; ++ j) {
        scanf("%d", &tmp);
        int out =curr.top();
        curr.pop();
//        cout << "test minHeap " << curr.top() << endl;
        arr.emplace_back(out);
        if(tmp >= out) curr.push(tmp);
        else post.push(tmp);
        if((int)post.size() == m) { //卡住的元素占满了内存，则构成新的run
            while(!curr.empty()) {
                arr.emplace_back(curr.top());
                curr.pop();
            }
            output(arr);
            arr.clear();
            curr = post;
            while(!post.empty()) post.pop(); //清空post
        }
    }
    for(int i = 0; i < 2; ++ i) { //清空curr，输出最后一个run(post)
         while(!curr.empty()) {
            arr.emplace_back(curr.top());
            curr.pop();
        }
        output(arr);
        arr.clear();
        curr = post;
    }
    return 0;
}
/*
7 3
81 94 11 96 12 99 35
*/
