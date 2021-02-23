#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int w[10001];
int d[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	// N: 포도주 잔의 개수
	int N;

	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		cin >> w[i];
	}

	d[1] = w[1];
	d[2] = w[1] + w[2];

	for (int i = 3; i <= N; i++)
	{
		d[i] = max(d[i - 1],
			   max(d[i - 2] + w[i],
				   d[i - 3] + w[i - 1] + w[i]));	
	}

	cout << d[N] << endl;

	return 0;
}