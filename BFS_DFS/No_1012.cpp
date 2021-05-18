#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
using namespace std;

struct Node {
    Node()
        : mNum(0)   // 모든 노드는 노드에 할당된 번호를 0으로 초기화.
        , mVisited(false)    // 방문 정보를 false로 초기화
    {}

    vector<Node*> mAdjacent;    // 인접 노드에 대한 정보
    int mNum;                   // 단지 번호 (0: 배추 없음, 1: 배추 있음)
    bool mVisited;              // 방문 정보
};

bool DFS(Node* begin)
{
    // 배추가 없거나, 탐색된적 있다면 false 반환 후 종료
    if (begin->mNum == 0 || begin->mVisited == true)
        return false;

    // 방문 체크
    begin->mVisited = true;

    // 인접 배추에대한 탐색 시행
    for (auto neighbor : begin->mAdjacent)
    {
        DFS(neighbor);
    }

    // 배추 무리 탐색에 성공했다면 true 반환
    return true;
}
void Solution(int M, int N, int K)
{
    // 배추밭 선언
    vector<vector<Node*>> map;

    // 배추밭 생성
    map.resize(N);
    for (int i = 0; i < N; i++)
    {
        map[i].resize(M);
        for (int j = 0; j < M; j++)
        {
            map[i][j] = new Node();
        }
    }

    // 각 배추들의 인접 배추 정보 설정
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

    // 배추 정보 입력받음
    for (int i = 0; i < K; i++)
    {
        int X, Y;
        cin >> X >> Y;
        map[Y][X]->mNum = 1;
    }

    // 인접해서 무리를 이룬 배추들의 무리를 카운트하여 출력
    int answer = 0;

    // 전체 노드에 대해서 DFS 탐색
    for (auto row : map)
    {
        for (auto node : row)
        {
            // 탐색된적 없고, 배추가 존재하는 무리를 발견하면 true를 반환하는 DFS 함수
            // map[i][j] 배추에서부터 탐색을 시작한다.
            if (DFS(node))
                answer++;
        }
    }

    // 정답 출력
    cout << answer << endl;

    // 동적할당한 노드들을 모두 삭제해준다.
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
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // T: 테스트 케이스
    // M: 배추를 심을 가로 길이 ( 1 ~ 50 )
    // N: 배추를 심을 세로 길이 ( 1 ~ 50 )
    // K: 배추가 심어져 있는 위치의 개수 ( 1 ~ 2500 )
    int T, M, N, K;

    cin >> T;

    while (T--)
    {
        cin >> M >> N >> K;

        Solution(M, N, K);
    }

    return 0;
}