#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#define endl '\n'
#define weight first
#define value second

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	// N: 물품의 수 (1<= N <= 100)
	// K: 버틸 수 있는 최대 무게 (1<= K <= 100000)
	int N, K;
	//w: 짐의 무게
	//k: 짐의 가치
	int w, v;
	


	vector<pair<int, int>> items;

	cin >> N >> K;

	while (N--)
	{
		cin >> w >> v;
		items.emplace_back(w, v);
	}

	//for (auto i : items)
	//	cout << i.weight << ", " << i.value << endl;

	for (int i = 0; i < K; i++)
	{
	}
	
	return 0;
}