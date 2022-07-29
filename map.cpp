// Including the required headers
#include <iostream>
#include <string>
#include <unordered_map> //contains hash map
#include <cctype>        // contains tolower function
using namespace std;

// Function to count charecters in a string
void countChar(string s)
{
    unordered_map<char, int> countS;
    int maxCount = 0;
    char maxChar;
    // Counting the frequency of each charecter in a given word
    for (int i = 0; i < s.size(); i++)
    {
        countS[tolower(s[i])]++;
    }
    for (int j = 0; j < s.size(); j++)
    {
        if (countS[s[j]] > maxCount)
        {
            maxChar = s[j];
            maxCount = countS[s[j]];
        }
    }
    if (maxCount == 1)
    {
        cout << "All the charecters occur only once! " << endl;
    }
    else
    {
        cout << "The most frequent charecter in your word is: " << maxChar << endl;
    }
}

// Using a hash map to find the most frequent charecter in a word
int main()
{
    string s;
    unordered_map<char, int> countS;
    int maxCount = 0;
    char maxChar;
    cout << "Enter a word: \n";
    cin >> s;
    countChar(s);

    return 0;
}