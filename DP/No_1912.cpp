#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
    // 입출력 성능 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int N;
    int dp[100'000] = { 0, };

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> dp[i];
    }

    int ans = dp[0];

    for (int i = 1; i < N; ++i)
    {
        dp[i] = max(dp[i], dp[i - 1] + dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
    
    return 0;
}
