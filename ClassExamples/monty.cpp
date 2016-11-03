#include <iostream>
#include<string>
#include <stdlib.h>
using namespace std;

int main()
{
    string name, quest;
    int v, av;

    cout << "What is your name?" << endl;
    cin >> name;
    cout << "What is your quest?" << endl;
    cin >> quest;
    cout << "What is the average air velocity of an unladen swallow?" << endl;
    cin >> v;
    while(v!= 0)
    {
        cout << "TEST";
        if (v < 50)
        {
            cout << "INCORRECT!";
            break;
        }
        else if(v > 50)
        {
            cout << "African or European?\n";
            cin >> av;
            if(av == 69)
            {
                cout << "CORRECT!";
                break;
            }
        }
    }
}