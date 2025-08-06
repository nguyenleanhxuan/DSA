#include <iostream>
using namespace std;

int consonant_count(const string &str)
{
    int count = 0;
    for (char c : str)
    {
        char lower_c = tolower(c);
        if (lower_c >= 'a' && lower_c <= 'z' && lower_c != 'a' && lower_c != 'e' && lower_c != 'i' && lower_c != 'o' && lower_c != 'u')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string input;
    cout << "Please enter a string to count its consonants: ";
    getline(cin, input);
    int result = consonant_count(input);
    cout << "The number of consonants is: " << result << endl;
    return 0;
}