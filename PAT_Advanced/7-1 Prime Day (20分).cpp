/*
7-1 Prime Day (20分)
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int x) {
    if(x <= 1) return false;
    else if(x == 2) return true;
    else if(x % 2 == 0) return false;
    int limit = sqrt(x) + 1;
    for(int i = 3; i < limit;  i += 2) {
        if(x % i == 0) return false;
    }
    return true;
}
int main() {
    string str, sub;
    bool flag;
    bool isAllYes = true;
    cin >> str;
    for(int i = 0; i < 8; ++ i) {
        sub = string(str, i);
        cout << sub << " ";
        flag = isPrime(stoi(sub));
        puts(flag? "Yes": "No");
        if(flag == false) isAllYes = false;
    }
    if(isAllYes) puts("All Prime!");
    return 0;
}
