#include <iostream>
#include <list>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N; // Read the input value

    // Check if the input number is valid
    if (!(N >= 1 && N <= 100000))
    {
        // Check if a number is within the valid range (1 to 100000)
        cerr << "This number should be between 1 and 100000" << endl;
        return 1; // Exit if the number is invalid
    }

    // Define sets of available coins and notes
    const list<int> coins_and_notes{200, 100, 50, 20, 10, 5, 2, 1};

    // Map to store the count of notes and coins needed
    map<string, int> total_back = {{"notes", 0}, {"coins", 0}};

    // Calculate the number of notes and coins needed
    for (const auto& c_n : coins_and_notes)
    {
        if (N >= c_n)
        {
            total_back[c_n >= 10 ? "notes" : "coins"] += N / c_n; // Add the number of notes and coins of this denomination
            // cout << (c_n >= 10 ? "note" : "coin") << ": " << c_n << " * " << N / c_n << endl; // Uncoment this to know what's the value of the money
            N %= c_n; // Update N to the remaining amount
        }
    }

    // Output the total number of notes and coins
    cout << total_back["notes"] << " notas\n" << total_back["coins"] << " moedas" << endl;

    return 0;
}
