#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 100005;
class Node {
public:
	int address, data, next;
};
int main() {
	Node NList[MAXN];
	int headAdd, nodeNum, k;
	scanf("%d %d %d", &headAdd, &nodeNum, &k);
	int tmpAdd, tmpData, nextAdd;
	for(int i = 0; i < nodeNum; ++ i) {
		scanf("%d %d %d", &tmpAdd, &tmpData, &nextAdd);
		NList[tmpAdd].address = tmpAdd;
		NList[tmpAdd].data = tmpData;
		NList[tmpAdd].next = nextAdd;
	}
	tmpAdd = headAdd;
	vector <int> linkList;
	while(tmpAdd != -1) {
		linkList.push_back(tmpAdd);
		tmpAdd = NList[tmpAdd].next;
	}
	for(int i = 0; i + k <= linkList.size(); i += k) {
		reverse(linkList.begin()+i, linkList.begin()+i+k);
	}
	int len = linkList.size();
	for(int i = 0; i < len-1; ++ i) {
		printf("%05d %d %05d\n", NList[linkList[i]].address,
		       NList[linkList[i]].data, NList[linkList[i+1]].address);
	}
	printf("%05d %d -1\n", NList[linkList[len-1]].address,\
	       NList[linkList[len-1]].data);
	return 0;
}
