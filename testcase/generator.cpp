#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>

#define MAX_W	100000
#define MAX_V	1000

using namespace std;

int main()
{
	//ifstream in("test.txt");
	ofstream out("test.txt");

	srand(static_cast<unsigned int>( time(0)));
	int N, K, w, v;

	N = 100;
	K = 100 * 1000;

	out << to_string(N) << " " << to_string(K) << "\n";

	for (int i = 0; i < N; i++)
	{
		w = rand() % MAX_W + 1;
		v = rand() % MAX_V + 1;

		out << to_string(w) << " " << to_string(v) << "\n";
	}

	return 0;
}