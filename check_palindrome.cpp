#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>> s; 
    int j=s.length()-1;
    int flag =0;
    for(int i=0;i<s.length()/2;i++)
    { 
        if(s[i]!=s[j])
        {   
            flag =1;
            break;
        }
        else
        j--;
    }
    if (flag==1)
    cout<<"No";
    else
    cout<<"Yes";
    return 0;
}
