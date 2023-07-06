//Printing the order in which char should be added to make the string palindrome 

#include <iostream>
 using namespace std;
#include<vector>
#include<stack>
int main()
{
    string s;
    cin>> s; 
    int j=s.length()-1;
    int flag =0; string str =""; stack<char>st;
    for(int i=0;i<s.length();i++)
    { 
        if(s[i]!=s[j])       //if char not same then push into stack
        {   
            //flag =1;
            //str += s[i];
            st.push(s[i]);
        }
        else
        j--;  //else just forward the pointer
    }
   // if (flag==1)
   // cout<<"No";
   // else
    //cout<<str<<endl;
    //cout<<str.length();
    cout<<st.size()<<endl;   //size of the stack will be the required no of char 
    while (!st.empty())
    { 
        cout<<st.top();
        st.pop();
    }
    cout<<endl; 
    return 0;
}
