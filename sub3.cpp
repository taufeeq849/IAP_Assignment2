#include <iostream>
#include <string>
#include <algorithm>
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
bool isAceUsable(bool x1, bool x2)
{
    if ((x1 && x2) || (!x1 && !x2))
    {

        return false;
    }
    return true;
}
int getSum(int x1, int x2)
{

    return x1 + x2;
}
int getFinalSum(pair<int, bool> pair1, pair<int, bool> pair2, bool hasAce)
{
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
    }
    else
    {
        sum.first = getSum(pair1.first, pair2.first);
        sum.second = 0;
    }
    return std::max(sum.first, sum.second);
}

int main()
{

    string dealercard, card1, card2;
    cin >> dealercard >> card1 >> card2;

    pair<int, bool> dealerpair = getValue(dealercard[0]);
    if (dealerpair.second == true)
    {
        dealerpair.first == 11;
    }
    string ret;

    pair<int, bool> pair1 = getValue(card1[0]);
    pair<int, bool> pair2 = getValue(card2[0]);
    bool hasAce = pair1.second || pair2.second;
    bool twoAces = pair1.second && pair2.second;

    int playervalue = getFinalSum(pair1, pair2, hasAce);
    if (isAceUsable(pair1.second, pair2.second) || twoAces)
    {

        if (playervalue < 18)
        {
            ret = "Hit";
        }
        else if (playervalue == 18 && (dealerpair.first >= 9 || dealerpair.second))
        {
            ret = "Hit";
        }
        else
        {
            ret = "Stand";
        }
    }

    else
    {

        if (playervalue > 17 || (playervalue <= 17 && playervalue > 12 && dealerpair.first < 7))
        {
            ret = "Stand";
        }
        else if (playervalue == 12 && dealerpair.first >= 4 && dealerpair.first <= 6)
        {
            ret = "Stand";
        }
        else
        {
            ret = "Hit";
        }
    }
    cout << ret;
    return 0;
}
