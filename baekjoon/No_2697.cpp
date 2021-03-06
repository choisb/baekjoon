#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	vector<string> numbers;
	string number;

	int N;

	cin >> N;

	while (N--)
	{
		cin >> number;
		numbers.push_back(number);
	}

	for (auto n : numbers) {
		if (next_permutation(n.begin(), n.end()))
			cout << n << endl;
		else
			cout << "BIGGEST" << endl;
	}
	return 0;
}