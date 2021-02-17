// 정렬 후 인접한 원소를 검사한는 방식으로 전화번호부가 유효한지 확인함.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

bool check(const string& left, const string& right) 
{
	int len;
	len = min(left.length(), right.length());
	//cout << "left: " << left << " | right: " << right << " |len: " << len <<" | result: "<< left.compare(0, len, right) << endl;
	if (left.compare(0, len, right, 0, len) == 0)
		return true;
	else
		return false;
}

bool solve() 
{
	int n;
	cin >> n;
	vector<string>numbers;

	while (n--)
	{
		string newNum;
		cin >> newNum;
		numbers.push_back(newNum);
	}

	// 입력받은 전화번호들을 정렬함.
	sort(numbers.begin(), numbers.end());

	// 인접한 전화번호를 비교하여서 유효성 검사. 
	// ckeck 조건자는 전화번호가 유효할 경우 false, 유효하지 않을 경우 true 반환
	auto iter = adjacent_find(numbers.begin(), numbers.end(), check);

	// 모든 전화번호가 유효하다면 모든 검사를 무사히 통과하게 된다.
	// 모든 검사를 무사히 통과할 경우 true를 반환해서 "YES" 출력
	if (iter == numbers.end())
		return true;
	// 만약 유효하지 않은 전화번호를 발견한 경우 false를 반환해서 "NO" 출력
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int t, n, len;

	cin >> t;

	while (t--)
	{
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}