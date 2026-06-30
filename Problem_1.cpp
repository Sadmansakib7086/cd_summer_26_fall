#include<iostream>
#include<string>
using namespace std;

bool isNumericCons(char ch)
{
    int ascii = ch;

    if(ascii >= 48 && ascii <= 57){
        return true;
    }

    return false;
}

int main()
{
    string input;

    cout << "Enter a value: ";
    cin >> input;

    bool isNumeric = true;

    for(int i = 0; i < input.length(); i++)
    {
        if(!isNumericCons(input[i]))
        {
            isNumeric = false;
            break;
        }
    }

    if(isNumeric)
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric" << endl;

    return 0;
}






