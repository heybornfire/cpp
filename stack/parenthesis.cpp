#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
bool parenthesis(string &st)
{
	stack<char>s;
	int i=0;
	char x;
	while(st[i]!='\0')
	{
		if(st[i]=='('||st[i]=='{'||st[i]=='[')
			s.push(st[i]);
		else if(st[i]==')'||st[i]=='}'||st[i]==']')
		{
			if(s.empty())
				return false;
		switch (st[i]) 
        { 
        case ')': 
  
            // Store the top element in a 
            x = s.top(); 
            s.pop(); 
            //cout<<x;
            if (x=='{' || x=='[') 
                return false; 
            break; 
  
        case '}': 
  
            // Store the top element in b 
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[') 
                return false; 
            break; 
  
        case ']': 
  
            // Store the top element in c 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{') 
                return false; 
            break; 
        } 

		}
		i++;
	}
	if(s.empty())
		return true;
	else
		return false;
	
}
int main(int argc, char const *argv[])
{
	string st;
	cin>>st;
	if(parenthesis(st))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}