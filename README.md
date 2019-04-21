#include <iostream>
#include <queue>
#include <array>
#include <string>

using namespace std;
const int MAXN = 65;
class Node
{
public:
    char c;
    int f;
    friend bool operator < (Node n1, Node n2)
    {
        return n1.f < n2.f;
    }
};

int n;
array <Node, MAXN> charFrenquence;
priority_queue <Node, vector <Node>, less<Node> > minHeap;
priority_queue <Node, vector <Node> greater<Node> > maxHeap;

void GetFrenquence();
int BuildHuffmanTree();
int GetWPL();
void Judge();

int main()
{
    GetFrenquence();
    Judge();
    return 0;
}

void GetFrenquence( )
{
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> charFrenquence[i].c >> charFrenquence[i].f;
        minHeap.push(charFrenquence[i]);
    }
}
int BulidHuffmanTree( )
{
    while (minHeap.size() > 1) {
        Node left = minHeap.top();
        minHeap.pop();
        Node right = minHeap.top();
        minHeap.pop();
        minHeap.push(left + right);
        maxHeap.push(left);
        maxHeap.push(right);
    }
    Node tmp = minHeap.top();
    minHeap.pop();
    maxHeap.push(tmp);
    return tmp.f;
}
int GetWPL()
{
    char c;
    string s;
    int wpl {};
    for (int i = 0; i < n; ++ i) {
        cin >> c >> s;
        wpl += charFrenquence[i].f * s.size();
    }
    return wpl;
}
void Judge()
{
    int m;
    cin >> m;
    while (m --) {
        puts(GetWPL() == BuildHuffmanTree() : "YES", "NO");
    }
}
