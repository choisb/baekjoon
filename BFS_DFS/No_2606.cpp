#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#define endl '\n'
using namespace std;

struct Node {
    Node(int num)   // ��� ���� ��忡 �Ҵ�� ���ڰ� �־���Ѵ�.
        :mNum(num)
        , mVisited(false)    // �湮 ������ false�� �ʱ�ȭ
    {}

    vector<Node*> mAdjacent;    // ���� ��忡 ���� ����
    int mNum;                   // ��忡 �Ҵ�� ����
    bool mVisited;              // �湮 ����
};

using NodeMap = unordered_map<int, Node*>;

int BFS(Node* begin)
{
    int visitCnt = 0;

    queue<Node*> q;

    // ť�� �ʱ� ��� �Է�
    q.push(begin);
    begin->mVisited = true;

    do {
        // ť�� ù��° ��带 ������ ����� ���� �߰�
        Node* cur = q.front();
        q.pop();

        for (auto adj : cur->mAdjacent)
        {
            // ���� ��尡 ���� �湮���� ���� ����� ť�� �߰��ϰ� �湮 üũ��.
            if (adj->mVisited == false)
            {
                q.push(adj);
                adj->mVisited = true;
                visitCnt++;
            }
        }
        // ť�� ���� ���� �ݺ�
    } while (!q.empty());

    return visitCnt;
}

int main() {
    // ����� ���� ����� ���� ����
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // N: ��ǻ���� �� (1 ~ 100)
    // M: �� ��ǻ���� ���� ��(��Ʈ��ũ)�� �� 
    int N, M;

    NodeMap nodes; // ������ ������ ���� �ؽø�

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < M; ++i)
    {
        int A, B;

        cin >> A >> B;

        nodes[A]->mAdjacent.push_back(nodes[B]);
        nodes[B]->mAdjacent.push_back(nodes[A]);
    }

    // BFS(nodes[1]) �Լ��� 1�� ��忡�� Ž���� �����Ͽ� Ž���� �� ����� ��
    // ��, 1�� ��ǻ�ͷ� ���ؼ� ������ ��ǻ���� �� �� ��ȯ
    cout << BFS(nodes[1]) << endl;

    return 0;
}