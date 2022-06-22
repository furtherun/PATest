/*
05-树7 堆中的路径 (25分)
堆的插入，变插入便调整
堆排序是，直接给了一个无序数组
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
void insertIntoHeap(vector<int>& heap, int x) {
    /*
    the index start from 1
    */
    heap.emplace_back(x);
    int i = (int)heap.size()-1; //positon of x in heap
    while(i > 1) {
        if(heap[i/2] > x) {
            swap(heap[i], heap[i/2]);
        } else {
            break;
        }
        i /= 2;
    }
}
void printPath(vector<int>& heap, int pos) {
    while(pos >= 1) {
        printf("%d", heap[pos]);
        printf(pos == 1?"\n": " ");
        pos /= 2;
    }
}
int main() {
    int n, tmp, m;
    scanf("%d %d", &n, &m);
    vector<int> heap {0};
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        insertIntoHeap(heap, tmp);
    }
//    cout << "Hello" << endl;
    for(int i = 0; i < m; ++ i) {
        scanf("%d", &tmp);
        printPath(heap, tmp);
    }
    return 0;
}
