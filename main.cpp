#include <iostream>
#include <map>
#include <unordered_set>

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
    const unordered_set<int> coins_and_notes{1, 2, 5, 10, 20, 50, 100, 200};

    // Map to store the count of notes and coins needed
    map<string, int> total_back = {{"notes", 0}, {"coins", 0}};

    // Calculate the number of notes and coins needed
    for (const auto& c_n : coins_and_notes)
    {
        if (N >= c_n)
        {
            total_back[c_n >= 10 ? "notes" : "coins"] += N / c_n; // Add the number of notes and coins of this denomination
            N %= c_n; // Update N to the remaining amount
        }
    }

    // Output the total number of notes and coins
    cout << total_back["notes"] << " notas\n" << total_back["coins"] << " moedas" << endl;

    return 0;
}
