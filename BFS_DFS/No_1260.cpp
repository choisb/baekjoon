#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>

#define endl '\n'
using namespace std;

struct Node {
    Node(int num)       // 모든 노드는 할당된 숫자가 있어야한다.
        :mNum(num)
        , mVisited(false)   // 방문 정보를 false로 초기화
    {}

    vector<Node*> mAdjacent;    // 인접 노드에 대한 정보
    int mNum;                   // 노드에 할당된 숫자
    bool mVisited;              // 방문 정보
};

void DFS(Node* begin)
{
    begin->mVisited = true;
    cout << begin->mNum << " ";
    for (auto adj : begin->mAdjacent)
    {
        if (adj->mVisited == false)
        {
            DFS(adj);
        }
    }
}
void BFS(Node* begin)
{
    queue<Node*> q;
    q.push(begin);
    begin->mVisited = true;

    do {
        Node* cur = q.front();
        q.pop();
        cout << cur->mNum << " ";

        for (auto adj : cur->mAdjacent)
        {
            if (adj->mVisited == false)
            {
                q.push(adj);
                adj->mVisited = true;
            }
        }
    } while (!q.empty());
}
int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    // N: 정점의 개수(1 ~ 1,000)
    // M: 간선의 개수(1 ~ 10,000)
    // V: 시작할 정점의 번호
    int N, M, V;

    unordered_map<int, Node*> nodes;

    cin >> N >> M >> V;

    // (1 ~ N 까지의 정점을 생성)
    while (N--)
    {
        nodes[N + 1] = new Node(N + 1);
    }

    // 각 정점에 간선의 정보를 입력. 간선은 양방향으로 연결
    while (M--)
    {
        int A, B;
        cin >> A >> B;

        nodes[A]->mAdjacent.emplace_back(nodes[B]);
        nodes[B]->mAdjacent.emplace_back(nodes[A]);
    }

    // 작은 수 부터 출력하기 위해서 인접노드 배열을 오름차순으로 정렬
    for (auto node : nodes)
    {
        sort(node.second->mAdjacent.begin(), node.second->mAdjacent.end(),
            [](Node* left, Node* right) -> bool
            {
                return left->mNum < right->mNum;
            });
    }

    // DFS에 시작 노드를 전달
    DFS(nodes[V]);

    cout << endl;

    // 방문 기록을 모두 초기화
    for (auto node : nodes)
        node.second->mVisited = false;

    // BFS에 시작 노드를 전달
    BFS(nodes[V]);

    // 동적할당 노드 모두 삭제
    for (auto node : nodes)
    {
        delete node.second;
    }

    return 0;
}
