#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL); 
    cin.tie(NULL);

    int N;

    string name;
    string log;

    cin >> N;
    set<string> company;   

    while (N--)
    {
        cin >> name;
        cin >> log;
        
        if (log == "enter")
            company.insert(name);

        else
            company.erase(name);
    }

    auto iter = company.end();

    while (1)
    {
        iter--;
        cout << *iter << '\n';
        if (iter == company.begin())
            break;
    }
    return 0;
}