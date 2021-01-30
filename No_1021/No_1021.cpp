#include <deque>
#include <iostream>
using namespace std;

void Print(const deque<int>& deque)
{
    for (auto dq : deque)
        cout << dq << ' ';

    cout << endl;
}
void left(deque<int>& deque, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        deque.push_back(deque.front());
        deque.pop_front();
    }
}

void right(deque<int>& deque, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        deque.push_front(deque.back());
        deque.pop_back();
    }
}


int main()
{
    int N, M ,target, interval, shift, result = 0;
    
    cin >> N >> M;

    deque<int> Numbers;
    
    for (int i = 0; i < N; i++)
        Numbers.push_back(i + 1);
    
    Print(Numbers);

    for (int i = 0; i < M; i++)
    {
        interval = 0;
        cin >> target;
        auto iter = Numbers.begin();

        for (; iter != Numbers.end(); iter++)
        {
            if (*iter == target)
            {
                break;
            }
            interval++;
        }

        if (interval > static_cast<int>(Numbers.size() / 2)) 
        {
            shift = Numbers.size() - interval;
            right(Numbers, shift);
            result += shift;
        }
        else
        {
            shift = interval;
            left(Numbers, shift);
            result += shift;
        }
        Numbers.pop_front();

    }

    cout << result;



    return 0;
}