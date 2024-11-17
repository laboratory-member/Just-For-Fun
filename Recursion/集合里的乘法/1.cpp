#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// C++³õÊ¼Ä£°å³ÌÐò
void f(int n,vector<int> &s,vector<int> &result,int product)
{
    if (n==0) 
    {
        result.push_back(product);
        return;
    }
    f (n-1,s,result,product*s[n-1]);
    f (n-1,s,result,product);
    
}


int main() {
	int t,n;
	cin >>t >>n;
	vector<int> s(n);
	for (int i=0;i<n;i++)
	{
	    cin >> s[i];
	}
	vector<int> result;
	f(n,s,result,1);
	if (find(result.begin(),result.end(),t)!=result.end()) cout << "YES" <<endl;
	else cout << "NO" <<endl;
	return 0;
}

