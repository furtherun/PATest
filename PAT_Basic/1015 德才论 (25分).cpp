#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Person{
public:
	int id, moral, capa, total, flag;
};
int cmp(Person* a, Person* b) {
	if(a->flag != b->flag) {
		return a->flag < b->flag;
	} else if(a->total != b->total) {
		return a->total > b->total;
	} else if(a->moral != b->moral) {
		return a->moral > b->moral;
	} else {
		return a->id < b->id;
	}
}
int main() {
	vector <Person*> examinees;
	int n, L, H;
	scanf("%d %d %d", &n, &L, &H);
	int tmpMoral, tmpCapa, tmpId;
	for(int i = 0; i < n; ++ i) {
		scanf("%d %d %d", &tmpId, &tmpMoral, &tmpCapa);
		if(tmpMoral < L || tmpCapa < L) {
			continue;
		}
		Person* p = new Person;
		p->id = tmpId;
		p->moral = tmpMoral;
		p->capa = tmpCapa;
		p->total = tmpMoral + tmpCapa;
		if(tmpMoral>= H && tmpCapa >= H) {
			p->flag = 1;
		} else if(tmpMoral >= H && tmpCapa < H) {
			p->flag = 2;
		} else if(tmpMoral >= tmpCapa) {
			p->flag = 3;
		} else {
			p->flag = 4;
		}
		examinees.push_back(p);
	}
	sort(examinees.begin(), examinees.end(), cmp);
	printf("%d\n", examinees.size());
	for(auto it: examinees) {
		printf("%08d %d %d\n", it->id, it->moral, it->capa);
	}
	return 0;
}
