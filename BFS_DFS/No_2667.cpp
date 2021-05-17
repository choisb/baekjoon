#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

#define endl '\n'
using namespace std;

struct Node {
    Node(int num)   // 모든 노드는 노드에 할당된 번호(0 or 1)이 있어야 한다.
        : mNum(num)
        , mVisited(false)    // 방문 정보를 false로 초기화
    {}

    vector<Node*> mAdjacent;    // 인접 노드에 대한 정보
    int mNum;                   // 단지 번호 (0: 집이 없음, 1이상: 단지 정보)
    bool mVisited;              // 방문 정보
};

// 시작 노드로부터 인접노드의 개수를 반환 BFS
// 한 번도 탐색되지 않은 단지 내에 있는 집의 총 수를 반환.
// 시작 노드를 탐색한 적이 있거나, 시작 노드에 집이 없을 경우 0 을 반환한다. 
int BFS(Node* begin)
{
    // 방문한 적이 있거나, 집이 없는 노드일 경우 0을 반환
    if (begin->mVisited == true || begin->mNum == 0)
        return 0;

    int cnt = 0;

    queue<Node*> q;
    q.push(begin);
    begin->mVisited = true;
    cnt++;  // 집 수 카운팅

    // 큐가 빌때 까지(탐색대상이 없을때 까지) 탐색
    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        for (auto neighbor : cur->mAdjacent)
        {
            // 방문한적이 없고, 집이 존재하는 경우(mNum이 1인 경우)
            if (neighbor->mVisited == false && neighbor->mNum == 1)
            {
                q.push(neighbor);
                neighbor->mVisited = true;
                cnt++; // 집 수 카운팅
            }
        }
    }

    return cnt;
}
int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // N: 정사각형 지도의 가로(=세로) 크기 (5~25)
    int N;

    // 정답 출력을 위한 벡터
    vector<int> answer;

    // 단지 정보를 담을 2차원 벡터
    vector<vector<Node*>> map;

    cin >> N;

    // map에 단지 정보를 입력
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

    // 각 노드의 인접한 노드를 설정한다.
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

    // 모든 노드(집)을 기준으로 BFS 탐색을 진행한다.
    // BFS함수는 한 번이라도 탐색을 한 적 있거나, 집이 없다면 0을 반환하고
    // 집이 있는 경우 연결되어 있는 모든 집의 수를 반환한다.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int result = BFS(map[i][j]);
            if (result > 0)
                answer.push_back(result);
        }
    }

    // 정답을 정렬 한 후 요구사항에 맞게 출력
    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;

    for (int a : answer)
    {
        cout << a << endl;
    }

    // 동적 할당된 노드들 삭제
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