#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

#define endl '\n'
using namespace std;

struct Node {
    Node(int num)   // ��� ���� ��忡 �Ҵ�� ��ȣ(0 or 1)�� �־�� �Ѵ�.
        : mNum(num)
        , mVisited(false)    // �湮 ������ false�� �ʱ�ȭ
    {}

    vector<Node*> mAdjacent;    // ���� ��忡 ���� ����
    int mNum;                   // ���� ��ȣ (0: ���� ����, 1�̻�: ���� ����)
    bool mVisited;              // �湮 ����
};

// ���� ���κ��� ��������� ������ ��ȯ BFS
// �� ���� Ž������ ���� ���� ���� �ִ� ���� �� ���� ��ȯ.
// ���� ��带 Ž���� ���� �ְų�, ���� ��忡 ���� ���� ��� 0 �� ��ȯ�Ѵ�. 
int BFS(Node* begin)
{
    // �湮�� ���� �ְų�, ���� ���� ����� ��� 0�� ��ȯ
    if (begin->mVisited == true || begin->mNum == 0)
        return 0;

    int cnt = 0;

    queue<Node*> q;
    q.push(begin);
    begin->mVisited = true;
    cnt++;  // �� �� ī����

    // ť�� ���� ����(Ž������� ������ ����) Ž��
    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        for (auto neighbor : cur->mAdjacent)
        {
            // �湮������ ����, ���� �����ϴ� ���(mNum�� 1�� ���)
            if (neighbor->mVisited == false && neighbor->mNum == 1)
            {
                q.push(neighbor);
                neighbor->mVisited = true;
                cnt++; // �� �� ī����
            }
        }
    }

    return cnt;
}
int main() {
    // ����� ���� ����� ���� ����
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // N: ���簢�� ������ ����(=����) ũ�� (5~25)
    int N;

    // ���� ����� ���� ����
    vector<int> answer;

    // ���� ������ ���� 2���� ����
    vector<vector<Node*>> map;

    cin >> N;

    // map�� ���� ������ �Է�
    map.resize(N);
    for (int i = 0; i < N; ++i)
    {
        map[i].resize(N);
        string input;
        cin >> input;
        for (int j = 0; j < N; ++j) 
        {
            map[i][j] = new Node(input[j] - '0');
        }
    }

    // �� ����� ������ ��带 �����Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i > 0)
            {
                map[i][j]->mAdjacent.push_back(map[i - 1][j]);
            }
            if (i < N - 1)
            {
                map[i][j]->mAdjacent.push_back(map[i + 1][j]);
            }
            if (j > 0)
            {
                map[i][j]->mAdjacent.push_back(map[i][j - 1]);
            }
            if (j < N - 1)
            {
                map[i][j]->mAdjacent.push_back(map[i][j + 1]);
            }
        }
    }

    // ��� ���(��)�� �������� BFS Ž���� �����Ѵ�.
    // BFS�Լ��� �� ���̶� Ž���� �� �� �ְų�, ���� ���ٸ� 0�� ��ȯ�ϰ�
    // ���� �ִ� ��� ����Ǿ� �ִ� ��� ���� ���� ��ȯ�Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int result = BFS(map[i][j]);
            if (result > 0)
                answer.push_back(result);
        }
    }

    // ������ ���� �� �� �䱸���׿� �°� ���
    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;

    for (int a : answer)
    {
        cout << a << endl;
    }

    // ���� �Ҵ�� ���� ����
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            delete map[i][j];
        }
        cout << endl;
    }
    return 0;
}