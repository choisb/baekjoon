#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#define endl '\n'
using namespace std;
int solve()
{
	// N: 개미의 수 (3 ≤ N ≤ 100,000)
	// L: 막대의 길이 (10 ≤ L ≤ 5,000,000)
	// K: 주어진 문제. (K번째에 떨어진 개미를 구하라) (1 ≤ k ≤ N)
	int N, L, K;

	// p: 개미의 초기 위치 (1 <= p <= L-1)
	// a: 개미의 ID
	int p, a;

	// 개미가 떨어지기 까지 필요한 시간
	int cost;

	multimap<int, int> ants;
	vector<int> antsID;

	cin >> N >> L >> K;

	while (N--)
	{
		cin >> p >> a;
		if (a < 0)
			cost = p;
		else
			cost = L - p;

		ants.insert({ cost, a });
		antsID.push_back(a);
	}
	cout << "ants: ";
	for (auto a : ants)
	{
		cout << "(" << a.first << "," << a.second << ") ";
	}
	cout << endl;

	cout << "antsID: ";
	for (auto a : antsID)
	{
		cout << "(" << a << ") ";
	}
	cout << endl;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int T;

	cin >> T;

	while (T--)
	{
		cout << solve();
	}
	return 0;
}
