#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#define endl '\n'
using namespace std;

struct Node {
    Node(int num)   // 모든 노드는 노드에 할당된 숫자가 있어야한다.
        :mNum(num)
        , mVisited(false)    // 방문 정보를 false로 초기화
    {}

    vector<Node*> mAdjacent;    // 인접 노드에 대한 정보
    int mNum;                   // 노드에 할당된 숫자
    bool mVisited;              // 방문 정보
};

using NodeMap = unordered_map<int, Node*>;

int BFS(Node* begin)
{
    int visitCnt = 0;

    queue<Node*> q;

    // 큐에 초기 노드 입력
    q.push(begin);
    begin->mVisited = true;

    do {
        // 큐의 첫번째 노드를 꺼내어 연결된 노드들 추가
        Node* cur = q.front();
        q.pop();

        for (auto adj : cur->mAdjacent)
        {
            // 인접 노드가 아직 방문하지 않은 노드라면 큐에 추가하고 방문 체크함.
            if (adj->mVisited == false)
            {
                q.push(adj);
                adj->mVisited = true;
                visitCnt++;
            }
        }
        // 큐가 빌때 까지 반복
    } while (!q.empty());

    return visitCnt;
}

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // N: 컴퓨터의 수 (1 ~ 100)
    // M: 두 컴퓨터의 연결 쌍(네트워크)의 수 
    int N, M;

    NodeMap nodes; // 노드들의 정보를 담을 해시맵

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

    // BFS(nodes[1]) 함수는 1번 노드에서 탐색을 시작하여 탐색한 총 노드의 수
    // 즉, 1번 컴퓨터로 인해서 감염된 컴퓨터의 수 를 반환
    cout << BFS(nodes[1]) << endl;

    return 0;
}