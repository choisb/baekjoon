#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& _t1, const pair<int, int>& _t2)
{
    if (_t1.second == _t2.second)   // 종료시간이 동일하다면 
        return _t1.first < _t2.first;   // 시작 시간을 비교 (오름차순)

    return _t1.second < _t2.second; // 종료시간 비교 (오름차순)
}

int main()
{
    int N = 0;
    unsigned int startTime = 0, endTime = 0;
    unsigned int count = 0;

    vector<pair<int, int>> time;

    cin >> N;
    time.reserve(N);    // 사용할 벡터의 크기만큼 미리 메모리 할당.

    for (int i = 0; i < N; i++)
    {
        cin >> startTime >> endTime;
        time.push_back(make_pair(startTime, endTime));
    }

    sort(time.begin(), time.end(), compare);

    vector<pair<int, int>>::iterator iter = time.begin();

    endTime = 0;

    for (; iter != time.end(); iter++)
    {
        if (endTime <= (*iter).first)
        {
            count++;
            endTime = (*iter).second;
        }
    }

    cout << count << endl;
    return 0;
}