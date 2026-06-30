#include<iostream>
#include<string>
using namespace std;

bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' ||
       ch == '/' || ch == '%' || ch == '=')
    {
        return true;
    }
    return false;
}

int main()
{
    string str;

    cout << "Enter an expression: ";
    cin >> str;

    int count = 1;
    bool found = false;

    for(int i = 0; i < str.length(); i++)
    {
        if(isOperator(str[i]))
        {
            cout << "Operator" << count << ": " << str[i] << endl;
            count++;
            found = true;
        }
    }

    if(!found)
    {
        cout << "No Operator Found" << endl;
    }

    return 0;
}
