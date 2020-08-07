/*
1056 Mice and Rice (25分)
我感觉我原来做这道题就是一开始没法读懂题意
第三行给的序列是代表，某号先出场，比如
11 3
25 18 0  46 37 3 19 22 57 56 10
6   0   8  7  10 5  9  1   4   2    3
就是6号(19g)，0号(25g)和8号(57g)先做第一组比较
*/
#include <iostream>
#include <queue>
using namespace std;
//const int MAXN = 1005;
struct Mice{
    int weight, ranking;
    Mice(int w) : weight(w), ranking(1) { };
    Mice() { };
};
int main() {
    int n, groupSize, groupNum, tmp;
    scanf("%d %d", &n, &groupSize);
    vector<Mice> mices;
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        mices.emplace_back(Mice(tmp));
    }
    queue<int> seq;
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        seq.push(tmp);
    }
    while(!seq.empty()) { //等于1时得出所有排名
        int len = (int)seq.size();
        groupNum = len / groupSize;
        if(len == 1) {
            mices[seq.front()].ranking = 1;
            break;
        }
        if(len % groupSize != 0) groupNum ++; //最后一组不够数，要额外开一组
        for(int j = 0; j < groupNum; ++ j) {
            int winnerId = seq.front();
            for(int i = 0; i < groupSize && i + j*groupSize < len; ++ i) {
                int tmpId = seq.front(); seq.pop();
                mices[tmpId].ranking = groupNum + 1;
                if(mices[tmpId].weight > mices[winnerId].weight) {
                    winnerId = tmpId;
                }
            }
            seq.push(winnerId);
        }
    }
    for(int i = 0; i < n; ++ i) {
        printf("%d", mices[i].ranking);
        printf(i == n-1?"\n": " ");
    }
    return 0;
}
