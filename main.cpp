#include <iostream>
using namespace std;

bool isNumber(string s)
{
    bool dot = false;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='.')
        {
            if(dot)
                return false;

            dot = true;
        }
        else if(!(s[i]>='0' && s[i]<='9'))
        {
            return false;
        }
    }

    return true;
}

bool isIdentifier(string s)
{
    if(!((s[0]>='a' && s[0]<='z') ||(s[0]>='A' && s[0]<='Z') || s[0]=='_'))
        return false;

    for(int i=1;i<s.length();i++)
    {
        if(!((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z') ||(s[i]>='0' && s[i]<='9') || s[i]=='_'))
            return false;
    }

    return true;
}

void Compiler(string input)
{

    string keywords[]={"cout","int","float","char","string","return"};

    string operators[]={"+","*","%", "=","<<",">>"};

    string punctuations[]={";","(",")","{","}","[","]" };

    int keywordCount=9;
    int operatorCount=10;
    int punctuationCount=7;

    char *p1=&input[0];
    char *p2=&input[0];

    while(*p2!='\0')
    {
        while(*p2==' ')
        {
            p2++;
            p1=p2;
        }

        if(*p2=='\0')
            break;

        while(*p2!=' ' && *p2!='\0')
        {
            p2++;
        }

        string token(p1,p2);

        bool found=false;

        for(int i=0;i<keywordCount;i++)
        {
            if(token==keywords[i])
            {
                cout<<token<<" -> Keyword"<<endl;
                found=true;
                break;
            }
        }

        if(!found)
        {
            for(int i=0;i<operatorCount;i++)
            {
                if(token==operators[i])
                {
                    cout<<token<<" -> Operator"<<endl;
                    found=true;
                    break;
                }
            }
        }

        if(!found)
        {
            for(int i=0;i<punctuationCount;i++)
            {
                if(token==punctuations[i])
                {
                    cout<<token<<" -> Punctuation"<<endl;
                    found=true;
                    break;
                }
            }
        }

        if(!found && isNumber(token))
        {
            cout<<token<<" -> Constant"<<endl;
            found=true;
        }

        if(!found && isIdentifier(token))
        {
            cout<<token<<" -> Identifier"<<endl;
            found=true;
        }

        if(!found)
        {
            cout<<token<<" -> Invalid Token"<<endl;
        }

        p1=p2;
    }
}

int main()
{
    string input="cout << a + b % 60 * 2.75 ;";

    Compiler(input);

    return 0;
}
