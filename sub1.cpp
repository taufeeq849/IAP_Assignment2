#include <iostream>
#include <string>
using namespace std;
int main()
{

    string input;

    cin >> input;

    string card = input.substr(0, 1);
    if (isdigit(card[0]) && card != "1")
    {
       
            cout << card[0] << endl;
        
    }
    else if (card == "A")
    {
        cout << "1 or 11" << endl;
    }

    else
    {
        cout << 10 << endl;
    }

    return 0;
}
