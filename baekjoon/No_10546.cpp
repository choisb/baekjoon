#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, cnt;
    string name;
    multiset<string> runner;

    cin >> N;
    cnt = N;

    while(cnt--)
    {
        cin >> name;
        runner.insert(name);

    }

    cnt = N - 1;
    while (cnt--)
    {
        cin >> name;
        // runner.erase(name);
        // erase()는 해당 원소 모두 삭제해버림.
        auto iter = runner.find(name);
        runner.erase(iter);
    }

    cout << *runner.begin() << '\n';

    return 0;
}