#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;
    stack<char>st;
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i] != 'a' && s[i]!='e'&& s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
        {
          st.push(s[i]);  
        }
 
    }
  while(!st.empty())
   {
       cout<<st.top();
       st.pop();
   }    
}
