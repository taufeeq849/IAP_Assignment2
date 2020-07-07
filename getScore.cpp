#include <iostream>
#include <string>
#include <algorithm>
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


int main()
{
    string input;
    cin >> input;
    int sum = 0;
    int aceCount = 0;
    vector<pair<int, bool>> pairs;
    
    while (input != "end")
    {
        pairs.push_back(getValue(input[0]));

        cin >> input;
    }
    for (pair<int, bool> pair : pairs)
    {

        sum += pair.first;
        if (pair.second)
        {
            aceCount++;
        }
    }
    if ((sum + 10) == 21 || sum == 21 && pairs.size() == 2)
    {
        cout << "21" << endl;
    }

    else if (aceCount >= 1 && (sum + 10) < 21) 
    {
        cout  << sum + 10;
    }

    else if (sum <= 21) 
    {

        cout << sum;
    }
   
    else
    {

        cout << (sum + 10) << endl;
    }
    return 0;
}