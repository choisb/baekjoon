#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
#define COST first
#define ID	 second	

using namespace std;
bool compare(const pair<int, int>& _left, const pair<int, int> _right)
{
	if (_left.COST == _right.COST)
		return _left.ID < _right.ID;
	return _left.COST < _right.COST;
}
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

	cin >> N >> L >> K;
	vector<int> l_cost;
	vector<int> r_cost;
	vector<pair<int, int>> ants(N);
	for(int i = 0; i< N; i++)
	{
		cin >> p >> a;
		if (a < 0) {
			cost = p;
			l_cost.push_back(cost);
		}
		else {
			cost = L - p;
			r_cost.push_back(cost);
		}
		ants[i].ID = a;
	}
	//cout << "cost:";
	//for (auto c : l_cost)
	//{
	//	cout <<" "<< c;
	//}
	//cout << "|";
	//for (auto c : r_cost)
	//{
	//	cout << c << " ";
	//}
	//cout << endl;
	for (int i = 0; i < l_cost.size(); i++)
	{
		ants[i].COST = l_cost[i];
	}

	for (int i = 0; i < r_cost.size(); i++)
	{
		ants[i + l_cost.size()].COST = r_cost[i];
	}
	//for (auto a : ants)
	//{
	//	cout << "(" << a.first << "," << a.second << ") ";
	//}
	//cout << endl;

	sort(ants.begin(), ants.end(), compare);

	//for (auto a : ants)
	//{
	//	cout << "(" << a.first << "," << a.second << ") ";
	//}
	//cout << endl;

	return ants.at(K-1).ID;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	vector<int> ans;
	int T;

	cin >> T;

	while (T--)
	{
		cout << solve() << endl;
	}

	return 0;
}
