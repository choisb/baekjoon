#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

struct Node {
    Node(int mNum)
        : mNum(mNum)   // ��� ���� ��忡 �Ҵ�� ��ȣ�� 0���� �ʱ�ȭ.
    {
        mAdjacent.reserve(6);   // �������� �ִ� 6������ �Է°����ϱ� ������ 6�� ������� �̸� �Ҵ�
    }

    vector<Node*> mAdjacent;    // ���� ��忡 ���� ����
    int mNum;                   // �丶�� ���� ���� (1 �̻�: ���� �丶��, 0: ���� ���� �丶��, -1: �丶�� ����)
};
// 3���� �ڽ��� ǥ���ϱ� ���� ��
using NodeMap = vector<vector<vector<Node*>>>;

int BFS(NodeMap& map)
{
    int answer = 0;

    queue<Node*> q;

    // ���� �丶��� ��� ť�� �ʱ� Ž�� ���� push
    for (auto box : map)
    {
        for (auto row : box)
        {
            for (auto node : row)
            {
                if (node->mNum == 1)
                {
                    q.push(node);
                }
            }
        }
    }

    // ť�� �������� Ž�� ����
    while (!q.empty())
    {
        Node* cur;
        cur = q.front();
        q.pop();

        for (auto neighbor : cur->mAdjacent)
        {
            if (neighbor->mNum == 0)
            {
                neighbor->mNum = cur->mNum + 1;
                q.push(neighbor);

                
                answer = neighbor->mNum - 1;
            }
        }

    }

    return answer;
}


int main() {
    // ����� ���� ����� ���� ����
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    // M: ���� (2 ~ 100)
    // N: ���� (2 ~ 100)
    // H: ���� (1 ~ 100)
    int M, N, H;

    NodeMap map;

    cin >> M >> N >> H;

    // ��� ���� �Ҵ�
    map.resize(H);
    for (int h = 0; h < H; ++h)
    {
        map[h].resize(N);
        for (int n = 0; n < N; ++n)
        {
            map[h][n].resize(M);
            for (int m = 0; m < M; ++m)
            {
                int num;
                cin >> num;
                map[h][n][m] = new Node(num);
            }
        }
    }

    // ������� ����
    for (int h = 0; h < H; ++h)
    {
        for (int n = 0; n < N; ++n)
        {
            for (int m = 0; m < M; ++m)
            {
                if (h > 0)
                {
                    map[h][n][m]->mAdjacent.push_back(map[h - 1][n][m]);
                }
                if (h < H - 1)
                {
                    map[h][n][m]->mAdjacent.push_back(map[h + 1][n][m]);
                }

                if (n > 0)
                {
                    map[h][n][m]->mAdjacent.push_back(map[h][n - 1][m]);
                }
                if (n < N - 1)
                {
                    map[h][n][m]->mAdjacent.push_back(map[h][n + 1][m]);
                }

                if (m > 0)
                {
                    map[h][n][m]->mAdjacent.push_back(map[h][n][m - 1]);
                }
                if (m < M - 1)
                {
                    map[h][n][m]->mAdjacent.push_back(map[h][n][m + 1]);
                }
            }
        }
    }


    int answer;
    answer = BFS(map);

    for (auto box : map)
    {
        for (auto row : box)
        {
            for (auto node : row)
            {
                // Ž�� �����Ŀ��� ���� �丶�䰡 �ִٸ� -1 ��ȯ
                if (node->mNum == 0)
                    answer = -1;

                // �����Ҵ��� ��� ����
                delete node;

            }
        }
    }

    cout << answer;

    return 0;
}
