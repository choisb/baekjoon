#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cstring>
#define endl '\n'

using namespace std;

int dp[101][100001];
int w[101];
int v[101];

int Knapsack(int _index, int _weight)
{
	// 저장된 값이 있다면 저장된 값 반환
	if (dp[_index][_weight] != -1)
		return dp[_index][_weight];

	int left = 0, right = 0;

	// index가 0인 경우는 항상 0
	if (_index == 0) {
		dp[_index][_weight] = 0;
		return 0;
	}

	// left
	left = Knapsack(_index - 1, _weight);

	// right는 _weight >= w[_index] 일때만 호출
	if (_weight >= w[_index])
		right = Knapsack(_index - 1, _weight - w[_index]) + v[_index];

	// left, right 비교 후 큰 값을 dp에 저장
	dp[_index][_weight] = max( left, right);

	return dp[_index][_weight];
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	// N: 물품의 수 (1<= N <= 100)
	// K: 버틸 수 있는 최대 무게 (1<= K <= 100*1000)
	int N, K;
	//w: 짐의 무게 ( 1 <= w <= 100*1000)
	//v: 짐의 가치 ( 0 <= v <= 1000)
	int W, V;

	time_t start, end;

	cin >> N >> K;

	start = clock();

	for (int i = 1; i <= N; i++)
	{
		cin >> W >> V;
		w[i] = W;
		v[i] = V;
	}
	cout << Knapsack(N, K) << endl;

	end = clock();

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++)
		{
			if (dp[i][j] == -1)
				cout << setw(3) << '-' << " ";
			else
				cout << setw(3) << dp[i][j] << " ";
		}
		cout << endl;
	}


	cout << "시간: " << end - start << endl;
	return 0;
}