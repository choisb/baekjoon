#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& _t1, const pair<int, int>& _t2)
{
    if (_t1.second == _t2.second)   // ����ð��� �����ϴٸ� 
        return _t1.first < _t2.first;   // ���� �ð��� �� (��������)

    return _t1.second < _t2.second; // ����ð� �� (��������)
}

int main()
{
    int N = 0;
    unsigned int startTime = 0, endTime = 0;
    unsigned int count = 0;

    vector<pair<int, int>> time;

    cin >> N;
    time.reserve(N);    // ����� ������ ũ�⸸ŭ �̸� �޸� �Ҵ�.

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