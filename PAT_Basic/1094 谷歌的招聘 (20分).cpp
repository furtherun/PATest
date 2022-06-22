#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isPrime(int x) {
	if(x == 2) {
		return true;
	}
	if(x%2 == 0 || x == 1) {
		return false;
	}
	int limit = sqrt(x);
	for(int i = 3; i <= limit; i ++) {
		if(x%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	//cout << stoi("0023") << endl; it'll output 23
	int len, k;
//	while(cin >> k) { //test isPrime
//		cout << "k = " << isPrime(k) << endl;
//	}
	scanf("%d %d", &len, &k);
	string s, substr;
	cin >> s;
	bool isPrinted = false;
	for(int i = 0; i+k <= len; ++ i) {
		substr = s.substr(i, k);
//		cout << substr << endl;
		if(isPrime(stoi(substr))) {
			isPrinted = true;
			break;
		}
	}
	printf(isPrinted == false? "404": substr.c_str());

	return 0;
}
