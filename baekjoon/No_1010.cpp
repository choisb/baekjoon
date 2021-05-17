#include <iostream>

#define endl '\n'
using namespace std;

int dp[31][31] = { 0, };

int Solution(int N, int M)
{
    if (N == 1)
        return M;

    if (N == M)
        return 1;

    if (dp[N][M] != 0)
        return dp[N][M];

    int result = 0;
    for (int i = N - 1; M - 1 >= i; i++)
    {
        result += Solution(N - 1, i);
    }
    dp[N][M] = result;

    return dp[N][M];
}

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    // T: 테스트 케이스
    // N: 서쪽에 있는 사이트 개수 (0 ~ 30)
    // M: 동쪽에 있는 사이트 개수 (N ~ 30)
    int T, N, M;

    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        cout << Solution(N, M) << endl;
    }
    return 0;
}
