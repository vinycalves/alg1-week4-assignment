#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

bool is_a_valid_number(int number)
{
    return number >= 1 && number <= 100000;
}

int main()
{
    int N;
    cin >> N;

    if (!is_a_valid_number(N))
    {
        cerr << "This number should be between 1 and 100000" << endl;
        return 1;
    }

    unordered_set<int> coins = {1, 2, 5};
    unordered_set<int> notes = {10, 20, 50, 100, 200};

    map<string, int> total_back = {{"notes", 0}, {"coins", 0}};

    for (const auto &note : notes)
    {
        if (N >= note)
        {
            total_back["notes"] += N / note;
            N %= note;
        }
    }

    for (const auto &coin : coins)
    {
        if (N >= coin)
        {
            total_back["coins"] += N / coin;
            N %= coin;
        }
    }

    cout << total_back["notes"] << " notas\n" << total_back["coins"] << " moedas" << endl;

    return 0;
}
