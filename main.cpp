#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

// Function to check if a number is within the valid range (1 to 100000)
bool is_a_valid_number(int number)
{
    return number >= 1 && number <= 100000;
}

int main()
{
    int N;
    cin >> N; // Read the input value

    // Check if the input number is valid
    if (!is_a_valid_number(N))
    {
        cerr << "This number should be between 1 and 100000" << endl;
        return 1; // Exit if the number is invalid
    }

    // Define sets of available coins and notes
    unordered_set<int> coins = {1, 2, 5};
    unordered_set<int> notes = {10, 20, 50, 100, 200};

    // Map to store the count of notes and coins needed
    map<string, int> total_back = {{"notes", 0}, {"coins", 0}};

    // Calculate the number of notes needed
    for (const auto &note : notes)
    {
        if (N >= note)
        {
            total_back["notes"] += N / note; // Add the number of notes of this denomination
            N %= note; // Update N to the remaining amount
        }
    }

    // Calculate the number of coins needed
    for (const auto &coin : coins)
    {
        if (N >= coin)
        {
            total_back["coins"] += N / coin; // Add the number of coins of this denomination
            N %= coin; // Update N to the remaining amount
        }
    }

    // Output the total number of notes and coins
    cout << total_back["notes"] << " notas\n" << total_back["coins"] << " moedas" << endl;

    return 0;
}
