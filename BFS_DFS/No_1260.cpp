#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>

#define endl '\n'
using namespace std;

struct Node {
    Node(int num)       // ��� ���� �Ҵ�� ���ڰ� �־���Ѵ�.
        :mNum(num)
        , mVisited(false)   // �湮 ������ false�� �ʱ�ȭ
    {}

    vector<Node*> mAdjacent;    // ���� ��忡 ���� ����
    int mNum;                   // ��忡 �Ҵ�� ����
    bool mVisited;              // �湮 ����
};

void DFS(Node* begin)
{
    begin->mVisited = true;
    cout << begin->mNum << " ";
    for (auto adj : begin->mAdjacent)
    {
        if (adj->mVisited == false)
        {
            DFS(adj);
        }
    }
}
void BFS(Node* begin)
{
    queue<Node*> q;
    q.push(begin);
    begin->mVisited = true;

    do {
        Node* cur = q.front();
        q.pop();
        cout << cur->mNum << " ";

        for (auto adj : cur->mAdjacent)
        {
            if (adj->mVisited == false)
            {
                q.push(adj);
                adj->mVisited = true;
            }
        }
    } while (!q.empty());
}
int main() {
    // ����� ���� ����� ���� ����
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // N: ������ ����(1 ~ 1,000)
    // M: ������ ����(1 ~ 10,000)
    // V: ������ ������ ��ȣ
    int N, M, V;

    unordered_map<int, Node*> nodes;

    cin >> N >> M >> V;

    // (1 ~ N ������ ������ ����)
    while (N--)
    {
        nodes[N + 1] = new Node(N + 1);
    }

    // �� ������ ������ ������ �Է�. ������ ��������� ����
    while (M--)
    {
        int A, B;
        cin >> A >> B;

        nodes[A]->mAdjacent.emplace_back(nodes[B]);
        nodes[B]->mAdjacent.emplace_back(nodes[A]);
    }

    // ���� �� ���� ����ϱ� ���ؼ� ������� �迭�� ������������ ����
    for (auto node : nodes)
    {
        sort(node.second->mAdjacent.begin(), node.second->mAdjacent.end(),
            [](Node* left, Node* right) -> bool
            {
                return left->mNum < right->mNum;
            });
    }

    // DFS�� ���� ��带 ����
    DFS(nodes[V]);

    cout << endl;

    // �湮 ����� ��� �ʱ�ȭ
    for (auto node : nodes)
        node.second->mVisited = false;

    // BFS�� ���� ��带 ����
    BFS(nodes[V]);

    // �����Ҵ� ��� ��� ����
    for (auto node : nodes)
    {
        delete node.second;
    }

    return 0;
}
