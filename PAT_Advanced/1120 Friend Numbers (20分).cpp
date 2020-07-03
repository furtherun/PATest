/*
1120 Friend Numbers (20分)
*/
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int sumAllDight(string& str) {
    int ans = 0;
    for(const char& s: str) {
        ans += (s - '0');
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    set<int> hashTbl;
    string tmp;
//    vector<int> ans;
    while(n--) {
        cin >> tmp;
        int x = sumAllDight(tmp);
        hashTbl.insert(x);
    }
    printf("%d\n", (int)hashTbl.size());
    for(auto it = hashTbl.begin(); it != hashTbl.end();  ++ it) {
        if(it != hashTbl.begin()) {
            printf(" ");
        }
        printf("%d", *it);
    }
    return 0;
}
