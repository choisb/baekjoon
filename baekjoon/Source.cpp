#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<ctime>

using namespace std;

int d[101][100001];
int w[101];
int v[101];

int main() {

	//freopen("Text.txt", "r", stdin);

	time_t start, end;

	start = clock();
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			d[i][j] = d[i - 1][j];
			if (j - w[i] >= 0) {
				d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << d[n][k] << endl;
	end = clock();

	cout << end - start << endl;
}
