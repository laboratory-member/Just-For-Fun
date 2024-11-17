#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

// C++³õÊ¼Ä£°å³ÌÐò

int main() {
	string str;
	stack<double> vals;
	vector<string> strs;
	
	while (cin >> str)
	{
	    strs.push_back(str);
	}
	
	int count = strs.size();
	for (int i=0;i<count;i++)
	{
	    if (strs.back()=="+")
	    {
	        double a = vals.top();
	        vals.pop();
	        double b = vals.top();
	        vals.pop();
	        vals.push(a+b);
	    }
	    else if (strs.back()=="-")
	    {
	        double a = vals.top();
	        vals.pop();
	        double b = vals.top();
	        vals.pop();
	        vals.push(a-b);
	    }
	    else if (strs.back()=="*")
	    {
	        double a = vals.top();
	        vals.pop();
	        double b = vals.top();
	        vals.pop();
	        vals.push(a*b);
	    }
	    else if (strs.back()=="/")
	    {
	        double a = vals.top();
	        vals.pop();
	        double b = vals.top();
	        vals.pop();
	        vals.push(a/b);
	    }
	    else
	    {
	        double a = stod(strs.back());
	        vals.push(a);
	    }
	    strs.pop_back();
	}
	printf("%f",vals.top());
	return 0;
}

