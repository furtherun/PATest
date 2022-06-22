#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
//    List L1, L2, L;
//    L1 = Read();
//    L2 = Read();
//    L = Merge(L1, L2);
//    Print(L);
//    Print(L1);
//    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ) {
	List L = (PtrToNode)malloc(sizeof(PtrToNode));
	PtrToNode p = L1->Next, q = L2->Next, last = L;
	while(p && q) {
		if(p->Data < q->Data) {
			last->Next = p;
			last = last->Next;
			p = p->Next;
		} else if(q->Data < p->Data) {
			last->Next = q;
			last = last->Next;
			q = q->Next;
		} else { // p->Data == q->Data
			last->Next = p;
			last = last->Next;
			p = p->Next;
			last->Next = q;
			last = last->Next;
			q = q->Next;
		}
	}
	while(p) {
		last->Next = p;
		last = last->Next;
		p = p->Next;
	}
	while(q) {
		last->Next = q;
		last = last->Next;
		q = q->Next;
	}
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}
