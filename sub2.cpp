#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<int, bool> getValue(char symbol)
{
    pair<int, bool> pair;
    if (symbol == 'A')
    {
        pair.first = 1;
        pair.second = true;
    }
    else if (isdigit(symbol) && symbol != '1')
    {

        pair.first = symbol - '0';
        pair.second = false;
    }
    else
    {

        pair.first = 10;
        pair.second = false;
    }
    return pair;
}

int getSum(int x1, int x2)
{

    return x1 + x2;
}

int main()
{
    string card1, card2;
    cin >> card1 >> card2;

    pair<int, bool> pair1 = getValue(card1[0]);
    pair<int, bool> pair2 = getValue(card2[0]);
    bool hasAce = pair1.second || pair2.second;

    pair<int, int> sum;
    if (hasAce)
    {
        if (pair1.second == true && pair2.second == false)
        {
            sum.first = getSum(pair1.first, pair2.first);
            sum.second = getSum(11, pair2.first);
        }
        else if (pair1.second == false && pair2.second == true)
        {
            sum.first = getSum(pair1.first, pair2.first);
            sum.second = getSum(pair1.first, 11);
        }
        else
        {
            sum.first = getSum(pair1.first, pair2.first);
            sum.second = getSum(11, pair2.first);
        }
        if (sum.first == 21 || sum.second == 21)
        {
            cout << "Blackjack!" << endl;
        }
        else
        {
            cout << sum.first << " or " << sum.second << endl;
        }
    }
    else
    {
        if (getSum(pair1.first, pair2.first) == 21)
        {
            cout << "Blackjack!" << endl;
        }
        else
        {
            cout << getSum(pair1.first, pair2.first);
        }
    }

    return 0;
}
