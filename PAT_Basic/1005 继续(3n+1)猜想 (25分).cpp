#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1205; // test n = 99
int cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, tmp;
	int arr[MAXN];
	bool visited[MAXN];
	fill(visited, visited + MAXN, false);
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i) {
		scanf("%d", &arr[i]);
		tmp = arr[i];
		while(tmp != 1) {
			if(tmp % 2 == 0) {
				tmp /= 2;
			} else {
				tmp = (3*tmp+1)/2;
			}
			if(visited[tmp] == true) {
				break;
			} else {
				visited[tmp] = true;
			}
		}
	}
	vector <int> vi;
	for(int i = 0; i < n; ++ i) { 
		if(visited[arr[i]] == false) {
			vi.push_back(arr[i]);
		}
	}
	sort(vi.begin(), vi.end(), cmp);
	for(int i = 0; i < vi.size(); ++ i) {
		printf("%d", vi[i]);
		printf(i==vi.size()-1?"\n": " ");
	}
	return 0;
}
