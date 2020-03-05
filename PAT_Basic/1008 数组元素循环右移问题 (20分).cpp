#include <iostream>
#include <queue>
using namespace std;
int main() {
	int n, m, tmp;
	scanf("%d %d", &n, &m);
	m %= n;
	queue <int> q;
	
	for(int i = 0; i < n; ++ i) {
		scanf("%d", &tmp);
		q.push(tmp);
	}
	for(int i = 0; i < n-m; ++ i) {
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	while(q.size()>1) {
		printf("%d ", q.front());
		q.pop();
	}
	printf("%d", q.front());
	return 0;
}
