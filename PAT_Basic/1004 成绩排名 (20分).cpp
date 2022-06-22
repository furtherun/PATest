#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int maxScore = -1, minScore = 101;
	int tmpScore;
	string name, id, maxName, minName, maxId, minId;
	for(int i = 0; i < n; ++ i) {
		cin >> name >> id >> tmpScore;
		if(tmpScore > maxScore) {
			maxScore = tmpScore;
			maxName = name;
			maxId = id;
		}
		if(tmpScore < minScore) {
			minScore = tmpScore;
			minName = name;
			minId = id;
		}
	}
	cout << maxName << " " << maxId << endl;
	cout << minName << " " << minId << endl;
	return 0;
}
