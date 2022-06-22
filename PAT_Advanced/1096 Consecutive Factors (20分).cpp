/*
1096 Consecutive Factors (20分)
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;
void output(const vector<int>& vi, int n) {
    int len = (int)vi.size();
    if(len == 0) { //莫名其妙后两个测试点是等于0的情况，可能是质数
        printf("1\n%d\n", n);
        return;
    }
    printf("%d\n", len);
    for(int i = 0; i < len-1; ++ i) {
        printf("%d*", vi[i]);
    }
    printf("%d\n", vi[len-1]);
}
int main() {
    vector<int> ansVi, tmpVi;
    int n;
    scanf("%d", &n);
    int limit = (int)sqrt(n) + 1;
    for(int start = 2; start <= limit; ++ start) { //1 is not inclued
        int t = n;
        for(int i = start; i <= limit; ++ i) {
            if(t % i == 0) {
                t /= i;
                tmpVi.emplace_back(i);
            } else {
                if(tmpVi.size() > ansVi.size()) {
                    ansVi = tmpVi;
                }
                tmpVi.clear();
                break;
            }
        }
    }
    output(ansVi, n);
    return 0;
}
