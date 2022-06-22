/*
7-2 Anniversary (25分)
前两题其实之前写过中文题，但都没满分，之前使用set排序，但是莫名许多答案不能过
之后看了别人的 代码，也是注意到只需要找到最值，没有必要进行排序，直接比较就可。
但是也是比较遗憾，之前想用重载<来进行排序，但是不能AC。
另外说明：寻找年龄最大的，就是出生日期最小的
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    unordered_set<string> alumnusId;
    int n, m;
    scanf("%d", &n);
    string tmpId;
    for(int i = 0; i < n; ++ i) {
        cin >> tmpId;
        alumnusId.insert(tmpId);
    }
    int isOneAlumnus = 0;
    string ansAlunus = "372928999999998710";
    string ansGuest =   "372928999999998710";
    scanf("%d", &m);
    for(int i = 0; i < m; ++ i) {
        cin >> tmpId;
        if(alumnusId.find(tmpId) != alumnusId.end()) {
            isOneAlumnus ++;
            if(tmpId.substr(6, 8) < ansAlunus.substr(6, 8)) {
                ansAlunus = tmpId;
            }
        } else if(tmpId.substr(6, 8) < ansGuest.substr(6, 8)){
            ansGuest = tmpId;
        }
    }
    printf("%d\n", isOneAlumnus);
    if(isOneAlumnus) {
        cout << ansAlunus << endl;
    } else {
        cout << ansGuest << endl;
    }
    return 0;
}
