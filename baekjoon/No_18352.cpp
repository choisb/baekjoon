#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define endl '\n'
using namespace std;

struct Node {
    Node(int num)
        :mNum(num)
        ,mDistance(-1) // �湮���� ���� ����� �Ÿ��� -1�� �ʱ�ȭ.
    {}

    vector<Node*> mAdjacents;   // ������ ����� ����
    int mNum;                   // �� Node�� ���� ��ȣ
    int mDistance;              // ��������� ���� �Ÿ�
};

// BFS �Լ� (���� ����, ��ǥ �Ÿ�, ������ ����, ������ ���� ����)
void BFS(int begin, int target, unordered_map<int, Node*>& nodes, vector<int>& answer)
{
    Node* cur;
    queue<Node*> q;
    // q�� �ʱ갪���� ���� ��带 ����. ���� ����� �Ÿ��� 0���� �ʱ�ȭ
    q.emplace(nodes[begin]);
    nodes[begin]->mDistance = 0;

    do
    {
        cur = q.front();
        q.pop();

        // q���� ���� ����� ���� ��� �� q�� ���Ե��� ���� ��� ��带 q�� ����
        for (auto adjacent : cur->mAdjacents)
        {
            if (adjacent->mDistance == -1)
            {
                // ���� ����� �Ÿ� = ����������� �Ÿ� + 1
                adjacent->mDistance = cur->mDistance + 1;
                q.emplace(adjacent);
            }
        }

        // ��ǥ �Ÿ��� ������ �Ÿ��� ��� �߰��Ѵ�.
        if (cur->mDistance == target)
            answer.emplace_back(cur->mNum);

        // ��ǥ �Ÿ��� �Ѿ�ٸ� Ž���� �����Ѵ�.
        else if (cur->mDistance > target)
            break;

        // ť�� ����ٸ� ���̻� Ž���� ������ �� ����, Ž���� ���������� ���Ѵ�.
    } while (!q.empty());

    // answer�� ����ٸ�, Ž���� �����ߴٴ� ���̱� ������ answer�� -1�� ����.
    if (answer.empty())
        answer.emplace_back(-1);
}


int main() {
    // ����� ���� ����� ���� ����
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // N: ������ ���� (2 ~ 300,000)
    // M: ������ ���� (1 ~ 1,000,000)
    // K: �Ÿ� ���� (1 ~ 300,000)
    // X: ��� ������ ��ȣ (1 ~ N)
    int N, M, K, X;

    vector<int> answer;             // ������ ������ ����
    unordered_map<int, Node*> nodes;// ���� ��ȣ�� Node* �� ������ �� �ִ� �ؽø�

    cin >> N >> M >> K >> X;

    while (M--)
    {
        // ��� ��θ� �Է� ����
        int A, B;

        cin >> A >> B;
        if (nodes[A] == nullptr)
            nodes[A] = new Node(A);

        if (nodes[B] == nullptr)
            nodes[B] = new Node(B);

        nodes[A]->mAdjacents.emplace_back(nodes[B]);
    }

    // BFS ����
    // (���� ����, ��ǥ �Ÿ�, ������ ����, ������ ���� ����)
    BFS(X, K, nodes, answer);

    // ������ ������������ ����
    sort(answer.begin(), answer.end());

    for (auto node : nodes)
        delete node.second;

    // ������ ��� ����Ѵ�.
    for (auto a : answer)
        cout << a << endl;

    return 0;
}
