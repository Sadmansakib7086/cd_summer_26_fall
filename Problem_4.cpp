#include <iostream>
#include <string>
using namespace std;

// Function to check if the input is a valid identifier
bool isIdentifier(string str)
{
    // Rule (a): first character check
    if (!((str[0] >= 'A' && str[0] <= 'Z') ||
          (str[0] >= 'a' && str[0] <= 'z') ||
          (str[0] == '_')))
    {
        return false;
    }

    // Rule (b): remaining characters check
    for (int i = 1; i < str.length(); i++)
    {
        if (!((str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= '0' && str[i] <= '9') ||
              (str[i] == '_')))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string input;

    cout << "Enter input: ";
    cin >> input;

    if (isIdentifier(input))
        cout << "It is a valid identifier." << endl;
    else
        cout << "It is NOT a valid identifier." << endl;

    return 0;
}
