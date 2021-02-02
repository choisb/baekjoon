#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    int N;

    cin >> N;

    while(N--)
    {
        list <char> List;
        string str;
        cin >> str;
        auto iter = List.begin();

        for(int i = 0; i < str.size(); i++)
        {
            switch (str.at(i))
            {
            case '<':
                if (iter != List.begin())
                    iter--;
                break;

            case '>':
                if (iter != List.end())
                    iter++;
                break;

            case '-':
                if (iter != List.begin())
                {
                    iter--;
                    iter = List.erase(iter);    // 중요! erase 후 반복자는 초기화된다. 계속 사용하기 위해서는 erase()의 반환값을 받아와야한다. 
                                                // erase에 반환되는 값은 삭제된 원소 다음 값이다.
                }
                break;

            default:
                List.insert(iter, str.at(i));
                break;
            }
        }

        for (auto ls : List)
        {
            cout << ls;
        }
        cout << endl;
    }
    return 0;
}