/*
1098 Insertion or Heap Sort (25分)
花里胡哨的stl写法
*/
#include<iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <cmath>
#include <vector>

using namespace std;
const int MAXN = 505;
void output(const vector<int>& vi) {
    int len = (int)vi.size();
    for(int i = 0; i < len; ++ i) {
        printf("%d", vi[i]);
        printf(i == len-1?"\n": " ");
    }
}
int main() {
    int n, tmp;
    scanf("%d", &n);
    vector<int> arr, ans;
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        arr.emplace_back(tmp);
    }
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        ans.emplace_back(tmp);
    }
    make_heap(arr.begin(), arr.end());
    for(int i = 0; i < n; ++ i) {
        pop_heap(arr.begin(), arr.end()-i);
//        output(arr);
        if(arr == ans) {
            pop_heap(ans.begin(), ans.end()-1-i);
            puts("Heap Sort");
            output(ans);
            goto out;
        }
    }
//    output(ans);
    for(int i = 1; i < n; ++ i) {
        if(ans[i] < ans[i-1]) {
            sort(ans.begin(), ans.begin()+i+1);
            puts("Insertion Sort");
            output(ans);
            goto out;
        }
    }
    out:
    return 0;
}
