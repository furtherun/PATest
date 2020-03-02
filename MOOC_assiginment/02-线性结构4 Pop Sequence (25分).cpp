#include <iostream>
#include <stack>
using namespace std;
int main() {
	stack <int> st;
	int m, n, k, tmp;
	scanf("%d %d %d", &m, &n, &k);
	while(k--) {
		int now = 1;
		bool isPopSeq = true;
		while(!st.empty()) {
			st.pop();
		}
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &tmp);
			while(now <= tmp) {
				st.push(now);
				now++;
			}
			if(st.top() != tmp || st.size() > m) {
				isPopSeq = false;
			} else {
				st.pop();
			}
		}
		puts(isPopSeq?"YES": "NO");
	}
	return 0;
}
