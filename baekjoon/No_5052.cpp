// ���� �� ������ ���Ҹ� �˻��Ѵ� ������� ��ȭ��ȣ�ΰ� ��ȿ���� Ȯ����.

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

	// �Է¹��� ��ȭ��ȣ���� ������.
	sort(numbers.begin(), numbers.end());

	// ������ ��ȭ��ȣ�� ���Ͽ��� ��ȿ�� �˻�. 
	// ckeck �����ڴ� ��ȭ��ȣ�� ��ȿ�� ��� false, ��ȿ���� ���� ��� true ��ȯ
	auto iter = adjacent_find(numbers.begin(), numbers.end(), check);

	// ��� ��ȭ��ȣ�� ��ȿ�ϴٸ� ��� �˻縦 ������ ����ϰ� �ȴ�.
	// ��� �˻縦 ������ ����� ��� true�� ��ȯ�ؼ� "YES" ���
	if (iter == numbers.end())
		return true;
	// ���� ��ȿ���� ���� ��ȭ��ȣ�� �߰��� ��� false�� ��ȯ�ؼ� "NO" ���
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