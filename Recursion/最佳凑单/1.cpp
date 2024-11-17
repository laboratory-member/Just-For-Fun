#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void f(int n, vector<int> &price,int t,vector<int> &sum,int index,int s)
{
    if (index == n) 
    {
        if (s>=t) sum.push_back(s);
        return;
    }
    f(n,price,t,sum,index+1,s);
    f(n,price,t,sum,index+1,s+price[index]);
}

int main(void) { 
	int n,t;
	cin >> n >> t;
	vector<int> price(n);
	for (int i=0;i<n;i++)
	{
	    cin >> price[i];
	}
    vector<int> sum;
    f(n,price,t,sum,0,0);
	if (!sum.empty()) cout << *min_element(sum.begin(),sum.end()) << endl;
	else cout << 0 << endl;
	return 0;
}

