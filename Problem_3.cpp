#include<iostream>
#include<string>
using namespace std;

string checkComment(string str)
{
    if (str.length() >= 2 && str[0] == '/' && str[1] == '/')
    {
       return "Single Line Comment";
    }
    else if (str.length() >= 4 && str[0] == '/' && str[1] == '*' && str[str.length() - 2] == '*' && str[str.length() - 1] == '/')
    {
        return "Multi Line Comment";
    }
    else
    {
        return "Not a Comment";
    }
}

int main()
{
    string str;

    cout << "Enter a comment: ";
    getline(cin,str);

    cout << checkComment(str) << endl;

    return 0;
}
