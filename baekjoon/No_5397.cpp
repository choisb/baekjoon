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
                    iter = List.erase(iter);    // �߿�! erase �� �ݺ��ڴ� �ʱ�ȭ�ȴ�. ��� ����ϱ� ���ؼ��� erase()�� ��ȯ���� �޾ƿ;��Ѵ�. 
                                                // erase�� ��ȯ�Ǵ� ���� ������ ���� ���� ���̴�.
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