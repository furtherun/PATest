/*
1116 Come on! Let's C (20分)
*/
#include<iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <vector>

using namespace std;
bool isPrime(int x) {
    if(x == 1) return false;
    else if(x == 2) return true;
    else if(x % 2 == 0) return false;
    int limit = (int)sqrt(x) + 1;
    for(int i = 3; i < limit; i += 2) {
        if(x % i == 0) return false;
    }
    return true;
}
int main() {
    int n, m, id;
    unordered_map<int, int> mp;
    unordered_set<int> box;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i) {
        scanf("%d", &id);
        mp[id] = i;
    }
    scanf("%d", &m);
    while(m --) {
        scanf("%d", &id);
        printf("%04d: ", id);
        if(mp.find(id) == mp.end()) {
            printf("Are you kidding?\n");
        } else if(box.find(id) != box.end()) {
            printf("Checked\n");
        } else if(mp[id] == 1) {
            printf("Mystery Award\n");
        } else if(isPrime(mp[id])) {
            printf("Minion\n");
        } else {
            printf("Chocolate\n");
        }
        box.insert(id);
    }
    return 0;
}

