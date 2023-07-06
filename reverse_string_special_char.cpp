// approach : simple two pointer approach used to solve this question

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int j=s.length()-1;
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i]!='$'&& s[i]!='#'&& s[i]!='@'&& s[i]!='!' && s[i]!='%' && s[i]!='^' && s[i]!='&' && s[i]!='*')
        {
            swap(s[i],s[j]);
            j--;
        }
        else
        {
            j--;
        }
    }
    cout<<s;
    return 0;
}
