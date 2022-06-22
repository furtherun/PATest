#include <iostream>
using namespace std;
class Node{
public:
	int coef, expo;
	Node* next;
};
Node* NewNode(int c, int e) {
	Node* tmp = new Node;
	tmp->coef = c;
	tmp->expo = e;
	tmp->next = nullptr;
	return tmp;
}
Node* CreateList(int n) {
	int tmpC, tmpE;
	Node* L = NewNode(0, 0);
	Node* last = L;
	for(int i = 0; i < n; ++ i) {
		scanf("%d %d", &tmpC, &tmpE);
		Node* tmpNode = NewNode(tmpC, tmpE);
		last->next = tmpNode;
		last = last->next;
	}
	return L;
}
void PrintList(Node* L) {
	Node* now = L->next;
	if(now) {
		printf("%d %d", now->coef, now->expo);
		now = now->next;
	} else {
		printf("0 0");
	}
	while(now) {
		printf(" %d %d", now->coef, now->expo);
		now = now->next;
	}
	printf("\n");
}
Node* ListAdd(Node* L1, Node* L2) {
	Node* L = NewNode(0, 0);
	Node* p = L1->next, *q = L2->next, *last = L;
	while(p && q) {
		if(p->expo > q->expo) {
			Node* tmpNode = NewNode(p->coef, p->expo);
			last->next = tmpNode;
			last = last->next;
			p = p->next;
		} else if(q->expo > p->expo) {
			Node* tmpNode = NewNode(q->coef, q->expo);
			last->next = tmpNode;
			last = last->next;
			q = q->next;
		} else {
			if(p->coef + q->coef != 0) {
				Node* tmpNode = NewNode(p->coef+q->coef, p->expo);
				last->next = tmpNode;
				last = last->next;
			}
			p = p->next;
			q = q->next;
		}
	}
	while(p) {
		Node* tmpNode = NewNode(p->coef, p->expo);
		last->next = tmpNode;
		last = last->next;
		p = p->next;
	}
	while(q) {
		Node* tmpNode = NewNode(q->coef, q->expo);
		last->next = tmpNode;
		last = last->next;
		q = q->next;
	}
	return L;
}
Node* ListMuti(Node* L1, Node* L2) {
	Node* L = NewNode(0, 0);
	Node* p = L1->next, *q = L2->next;
	Node* pre = L, *now = L->next;
	if(p && q) {
		while(p) {
			pre = L, now = L->next, q = L2->next;
			while(q) {
				int coefMuti = p->coef*q->coef, expoSum = p->expo+q->expo;
//				cout << " c = " << coefMuti << " e = " << expoSum << endl;
				bool isInserted = false;
				while(now) {
					if(now->expo == expoSum) {
						now->coef += coefMuti;
						isInserted = true;
					} else if(now->expo < expoSum) {
						break;
					}
					pre = pre->next;
					now = now->next;
				}
				if(isInserted == false) {
					Node* tmpNode = NewNode(coefMuti, expoSum);
					pre->next = tmpNode;
					tmpNode->next = now;
					pre = pre->next;
				}
				q = q->next;
			}
			p = p->next;
		}
	}
	pre = L, now = L->next;
	while(now) {
		if(now->coef == 0) {
			pre->next = now->next;
		} else {
			pre = pre->next;	
		}
		now = now->next;
	}
	return L;
}
int main() {
	int n;
	scanf("%d", &n);
	Node* L1 = CreateList(n);
	scanf("%d", &n);
	Node* L2 = CreateList(n);
//	cout << "test PrintList :" << endl;
//	PrintList(L1);
//	PrintList(L2);
//	cout << "PrintList L1 & L2 correct !" << endl;
//	cout << "Muti test :" << endl;
	Node* L1MutiL2 = ListMuti(L1, L2);
	PrintList(L1MutiL2);
//	cout << "Muti corrcet! " << endl;
//	cout << "Add test : " << endl;
	Node* L1AddL2 = ListAdd(L1, L2);
	PrintList(L1AddL2);
//	cout << "Add correct! " << endl;

	return 0;
}
