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
	// N: ������ �� (3 �� N �� 100,000)
	// L: ������ ���� (10 �� L �� 5,000,000)
	// K: �־��� ����. (K��°�� ������ ���̸� ���϶�) (1 �� k �� N)
	int N, L, K;

	// p: ������ �ʱ� ��ġ (1 <= p <= L-1)
	// a: ������ ID
	int p, a;

	// ���̰� �������� ���� �ʿ��� �ð�
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
