#include <iostream>
using namespace std;

int main()
{
    int N, cnt = 0, big = 0, small = 0;
    int sum;

    cin >> N;
    sum = N;
    while (sum >= 3)
    {
        if (sum % 5 == 0)
            break;
        sum -= 3;
        small++;
    }
    if (sum == 2 || sum == 1)
        cout << -1;
    else {
        big = sum / 5;
        cout << big + small;
    }
    

    return 0;
}