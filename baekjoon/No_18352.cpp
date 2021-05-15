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
        ,mDistance(-1) // 방문하지 않은 노드의 거리는 -1로 초기화.
    {}

    vector<Node*> mAdjacents;   // 인접한 노드의 집합
    int mNum;                   // 이 Node의 도시 번호
    int mDistance;              // 출발지에서 부터 거리
};

// BFS 함수 (시작 도시, 목표 거리, 노드들의 정보, 정답을 담을 벡터)
void BFS(int begin, int target, unordered_map<int, Node*>& nodes, vector<int>& answer)
{
    Node* cur;
    queue<Node*> q;
    // q에 초깃값으로 시작 노드를 삽입. 시작 노드의 거리를 0으로 초기화
    q.emplace(nodes[begin]);
    nodes[begin]->mDistance = 0;

    do
    {
        cur = q.front();
        q.pop();

        // q에서 꺼낸 노드의 인접 노드 중 q에 삽입된적 없는 모든 노드를 q에 삽입
        for (auto adjacent : cur->mAdjacents)
        {
            if (adjacent->mDistance == -1)
            {
                // 다음 노드의 거리 = 현재노드까지의 거리 + 1
                adjacent->mDistance = cur->mDistance + 1;
                q.emplace(adjacent);
            }
        }

        // 목표 거리와 동일한 거리는 모두 추가한다.
        if (cur->mDistance == target)
            answer.emplace_back(cur->mNum);

        // 목표 거리를 넘어섰다면 탐색을 종료한다.
        else if (cur->mDistance > target)
            break;

        // 큐가 비었다면 더이상 탐색을 진행할 수 없고, 탐색에 실패했음을 뜻한다.
    } while (!q.empty());

    // answer이 비었다면, 탐색에 실패했다는 뜻이기 때문에 answer에 -1을 삽입.
    if (answer.empty())
        answer.emplace_back(-1);
}


int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // N: 도시의 개수 (2 ~ 300,000)
    // M: 도로의 개수 (1 ~ 1,000,000)
    // K: 거리 정보 (1 ~ 300,000)
    // X: 출발 도시의 번호 (1 ~ N)
    int N, M, K, X;

    vector<int> answer;             // 정답을 저장할 벡터
    unordered_map<int, Node*> nodes;// 도시 번호로 Node* 를 참조할 수 있는 해시맵

    cin >> N >> M >> K >> X;

    while (M--)
    {
        // 모든 경로를 입력 받음
        int A, B;

        cin >> A >> B;
        if (nodes[A] == nullptr)
            nodes[A] = new Node(A);

        if (nodes[B] == nullptr)
            nodes[B] = new Node(B);

        nodes[A]->mAdjacents.emplace_back(nodes[B]);
    }

    // BFS 실행
    // (시작 도시, 목표 거리, 노드들의 정보, 정답을 담을 벡터)
    BFS(X, K, nodes, answer);

    // 정답을 오름차순으로 정렬
    sort(answer.begin(), answer.end());

    for (auto node : nodes)
        delete node.second;

    // 정답을 모두 출력한다.
    for (auto a : answer)
        cout << a << endl;

    return 0;
}
