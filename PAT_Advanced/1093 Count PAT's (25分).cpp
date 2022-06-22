/*
1093 Count PAT's (25分)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <unordered_set>
using namespace std;
const int MOD = 1000000007;
int main() {
    string str;
    cin >> str;
    int len = (int)str.size();
    vector<int> P(len, 0), A(len, 0), T(len, 0);
    if(str[0] == 'P') P[0] = 1;
    for(int i = 1; i < len; ++ i) {
        P[i] = P[i-1];
        A[i] = A[i-1];
        T[i] = T[i-1];
        if(str[i] == 'P') {
            P[i] = (P[i-1] + 1) % MOD;
        } else if(str[i] == 'A') {
            A[i] = (A[i-1] + P[i]) % MOD;
        } else {
            T[i] = (T[i-1] + A[i]) % MOD;
        }
    }
    printf("%d", T[len-1] % MOD);
    return 0;
}
