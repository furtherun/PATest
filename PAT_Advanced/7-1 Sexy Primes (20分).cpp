/*
7-1 Sexy Primes (20分)
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
bool isPrime(int x) {
    if(x <= 1) {
        return false;
    } else if(x == 2) {
        return true;
    } else {
        if(x % 2 == 0) {
            return false;
        }
        int limit = (int)sqrt(x) + 1;
        for(int i = 3; i <= limit; i+=2) {
            if(x%i == 0) {
                return false;
            }
        }
        return true;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    if(isPrime(n) && isPrime(n-6)) {
        printf("Yes\n%d\n", n-6);
    } else if(isPrime(n) && isPrime(n+6)) {
        printf("Yes\n%d\n", n);
    } else {
        while(++ n) {
            if(isPrime(n) && (isPrime(n-6) || isPrime(n+6))) { 
                /*
                一开始这里写成 isPrime(n) && isPrime(n-6)考虑不全面，手动测试了一个2，3之类的才发现了问题
                */
                printf("No\n%d\n", n);
                break;
            }
        }
    }
    return 0;
}

