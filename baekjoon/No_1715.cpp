#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	// N: 입력될 카드 묶음의 개수
	// card: 입력될 카드 묶음의 크기
	int N, card;

	// 최종 결괏값
	int ans = 0;
	int left, right, temp;

	priority_queue<int, vector<int>,greater<int>> cards;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> card;
		cards.push(card);
	}

	if (N == 1)
		ans = 0;

	while (cards.size() != 1)
	{
		left = cards.top();
		cards.pop();
		right = cards.top();
		cards.pop();
		temp = left + right;
		cards.push(temp);

		ans += temp;
	}

	cout << ans << endl;
	return 0;
}
