#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m,k;
    scanf("%d,%d,%d",&n,&m,&k);
    vector<int> people;
    for (int i=1;i<=n;i++)
    {
        people.push_back(i);
    }
    
    int pos = 0;
    for (int i=0;i<k;i++)
    {
        pos = (pos + m - 1) % (n - i);
        if (i==k-1) cout << people[pos] << endl;
        people.erase(people.begin()+pos);
    }

    return 0;
}

