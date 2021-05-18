#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
using namespace std;

struct Node {
    Node()
        : mNum(0)   // ��� ���� ��忡 �Ҵ�� ��ȣ�� 0���� �ʱ�ȭ.
        , mVisited(false)    // �湮 ������ false�� �ʱ�ȭ
    {}

    vector<Node*> mAdjacent;    // ���� ��忡 ���� ����
    int mNum;                   // ���� ��ȣ (0: ���� ����, 1: ���� ����)
    bool mVisited;              // �湮 ����
};

bool DFS(Node* begin)
{
    // ���߰� ���ų�, Ž������ �ִٸ� false ��ȯ �� ����
    if (begin->mNum == 0 || begin->mVisited == true)
        return false;

    // �湮 üũ
    begin->mVisited = true;

    // ���� ���߿����� Ž�� ����
    for (auto neighbor : begin->mAdjacent)
    {
        DFS(neighbor);
    }

    // ���� ���� Ž���� �����ߴٸ� true ��ȯ
    return true;
}
void Solution(int M, int N, int K)
{
    // ���߹� ����
    vector<vector<Node*>> map;

    // ���߹� ����
    map.resize(N);
    for (int i = 0; i < N; i++)
    {
        map[i].resize(M);
        for (int j = 0; j < M; j++)
        {
            map[i][j] = new Node();
        }
    }

    // �� ���ߵ��� ���� ���� ���� ����
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j > 0)
            {
                map[i][j]->mAdjacent.push_back(map[i][j - 1]);
            }
            if (j < M - 1)
            {
                map[i][j]->mAdjacent.push_back(map[i][j + 1]);
            }
            if (i > 0)
            {
                map[i][j]->mAdjacent.push_back(map[i - 1][j]);
            }
            if (i < N - 1)
            {
                map[i][j]->mAdjacent.push_back(map[i + 1][j]);
            }
        }
    }

    // ���� ���� �Է¹���
    for (int i = 0; i < K; i++)
    {
        int X, Y;
        cin >> X >> Y;
        map[Y][X]->mNum = 1;
    }

    // �����ؼ� ������ �̷� ���ߵ��� ������ ī��Ʈ�Ͽ� ���
    int answer = 0;

    // ��ü ��忡 ���ؼ� DFS Ž��
    for (auto row : map)
    {
        for (auto node : row)
        {
            // Ž������ ����, ���߰� �����ϴ� ������ �߰��ϸ� true�� ��ȯ�ϴ� DFS �Լ�
            // map[i][j] ���߿������� Ž���� �����Ѵ�.
            if (DFS(node))
                answer++;
        }
    }

    // ���� ���
    cout << answer << endl;

    // �����Ҵ��� ������ ��� �������ش�.
    for (auto row : map)
    {
        for (auto node : row)
        {
            delete node;
        }
    }
}

int main()
{
    // ����� ���� ����� ���� ����
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // T: �׽�Ʈ ���̽�
    // M: ���߸� ���� ���� ���� ( 1 ~ 50 )
    // N: ���߸� ���� ���� ���� ( 1 ~ 50 )
    // K: ���߰� �ɾ��� �ִ� ��ġ�� ���� ( 1 ~ 2500 )
    int T, M, N, K;

    cin >> T;

    while (T--)
    {
        cin >> M >> N >> K;

        Solution(M, N, K);
    }

    return 0;
}