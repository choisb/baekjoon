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

	// N: ��ǰ�� �� (1<= N <= 100)
	// K: ��ƿ �� �ִ� �ִ� ���� (1<= K <= 100000)
	int N, K;
	//w: ���� ����
	//k: ���� ��ġ
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