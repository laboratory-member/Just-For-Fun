#include <iostream>
using namespace std;

// C++³õÊ¼Ä£°å³ÌÐò

int main() {
	int n;
	cin >> n;
	
	int max=0;
	int num[n] = {0};
	
	double people[n];
	for (int i=0;i<n;i++)
	{
	    cin >> people[i];
	    for (int j=0;j<i;j++)
	    {
	        if (people[i]<=people[j])
	        {
	            num[i] = num[i]>num[j]+1?num[i]:num[j]+1;
	        }
	    }
	    max = max>num[i]?max:num[i];
	}
	cout << max+1 <<endl;
	return 0;
}

