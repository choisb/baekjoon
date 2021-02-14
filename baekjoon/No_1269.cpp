#include <iostream>
#include <set>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int A, B, newNum;
	set<int> numbers;

	cin >> A >> B;

	while (A--)
	{
		cin >> newNum;
		numbers.insert(newNum);
	}

	while (B--)
	{
		cin >> newNum;

		auto iter = numbers.find(newNum);

		if (iter != numbers.end())
			numbers.erase(newNum);
		else
			numbers.insert(newNum);
	}

	cout << numbers.size();

	return 0;
}
