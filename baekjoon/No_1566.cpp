#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#define endl '\n'
#define N_MAX 18
#define M_MAX 18
using namespace std;

void sumRow(int *a, int **arr, int *b)
{

}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N,M;
	int arr[M_MAX][N_MAX];
	int a[N_MAX], b[M_MAX];
	fill_n(a, N_MAX, -1);
	fill_n(b, M_MAX, 1);

	cin >> N >> M;

	for (int y = 0; y < N ; y++)
	{
		for (int x = 0; x < M; x++)
			cin >> arr[x][y];
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
			cout << a[y] * b[x] * arr[x][y] << " ";
		cout << endl;
	}

	return 0;
}