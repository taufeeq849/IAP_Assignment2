#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <initializer_list>
#include <algorithm>
#include <random>

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
string outputScore(const vector<string> &hand)
{
    string ret;
    vector<pair<int, bool>> pairs;
    int sum = 0;
    int aceCount = 0;
    for (string singlecard : hand)
    {
        pairs.push_back(getValue(singlecard[0]));
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
        return "Blackjack!";
    }

    else if (aceCount >= 1 && (sum + 10) < 21)
    {

        return to_string(sum) + " or " + to_string((sum + 10));   
    }

    else if (sum <= 21)
    {
        return to_string(sum);
        
    }

    else
    {
        return "Bust!";
    }
}

pair<int, bool> getPlayerScore(const vector<string> hand)
{
    string ret;
    vector<pair<int, bool>> pairs;
    int sum = 0;
    int aceCount = 0;
    for (string input : hand)
    {
        pairs.push_back(getValue(input[0]));
    }
    for (pair<int, bool> pair : pairs)
    {

        sum += pair.first;
        if (pair.second)
        {
            aceCount++;
        }
    }
    pair<int, bool> retpair;
    if (aceCount > 0)
    {
        retpair.second = false;
    }
    if ((sum + 10) == 21 || sum == 21 && pairs.size() == 2)
    {
        retpair.first = 21;
    }

    else if (aceCount >= 1 && (sum + 10) < 21)
    {
        retpair.first = sum + 10;
    }

    else if (sum <= 21)
    {
        retpair.first = sum;
    }

    else
    {
        retpair.first = sum + 10;
    }
   
    return retpair;
}
int main (){
string x; 
vector<string> cards; 
cin >> x; 
while (x != "end") {

    cards.push_back(x); 
    
    cin >> x; 
}
cout << outputScore(cards); 
    return 0; 
}
