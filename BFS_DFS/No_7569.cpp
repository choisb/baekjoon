#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

struct Node {
    Node(int mNum)
        : mNum(mNum)   // 모든 노드는 노드에 할당된 번호를 0으로 초기화.
    {
        mAdjacent.reserve(6);   // 인접노드는 최대 6개까지 입력가능하기 때문에 6개 인접노드 미리 할당
    }

    vector<Node*> mAdjacent;    // 인접 노드에 대한 정보
    int mNum;                   // 토마토 깊이 정보 (1 이상: 익은 토마토, 0: 익지 않은 토마토, -1: 토마토 없음)
};
// 3차원 박스를 표현하기 위한 맵
using NodeMap = vector<vector<vector<Node*>>>;

int BFS(NodeMap& map)
{
    int answer = 0;

    queue<Node*> q;

    // 익은 토마토는 모두 큐의 초기 탐색 노드로 push
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

    // 큐가 빌때까지 탐색 시작
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
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    // M: 가로 (2 ~ 100)
    // N: 세로 (2 ~ 100)
    // H: 높이 (1 ~ 100)
    int M, N, H;

    NodeMap map;

    cin >> M >> N >> H;

    // 노드 동적 할당
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

    // 인접노드 설정
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
                // 탐색 종료후에도 남은 토마토가 있다면 -1 반환
                if (node->mNum == 0)
                    answer = -1;

                // 동적할당한 노드 삭제
                delete node;

            }
        }
    }

    cout << answer;

    return 0;
}
