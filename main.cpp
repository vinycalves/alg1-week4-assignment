#include <cmath>
#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

bool is_a_valid_number(const double number)
{
    if (number < 1 || number > 100000)
        return false;
    return true;
}

int main()
{
    int N;
    cin >> N;

    if (!is_a_valid_number(N))
    {
        cerr << "This number should be between 1 and 100.000" << endl;
        return 1;
    }

    unordered_set<int> coins = {1, 2, 5};
    unordered_set<int> notes = {10, 20, 50, 100, 200};

    map<string, int> total_back;

    for (const auto note : notes)
    {
        double value_divided = fdiv(N, note);
        if (value_divided >= 1)
        {
            total_back["notes"] += fabs(value_divided);
            N = fmod(N, note);
        }
    }

    for (const auto coin : coins)
    {
        double value_divided = fdiv(N, coin);
        if (value_divided >= 1)
        {
            total_back["coins"] += fabs(value_divided);
            N = fmod(N, coin);
        }
    }

    cout << total_back["notes"] << " notas\n" << total_back["coins"] << " moedas" << endl;

    return 0;
}
