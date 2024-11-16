#include <iostream>
#include <vector>
using namespace std;

// C++³õÊ¼Ä£°å³ÌÐò
void dfs(int m,int n,vector<vector<int>>& mat,int x,int y)
{
    mat[x][y] = 0;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    for (int i=0;i<4;i++)
    {
        int x1 = x+dx[i];
        int y1 = y+dy[i];
        if (x1>=0&&x1<m&&y1>=0&&y1<n&&mat[x1][y1]==1) dfs(m,n,mat,x1,y1);
    }
}

int main() {
	int m,n;
	cin >> m >> n;
	vector<vector<int>> mat(m, vector<int>(n));
	for (int i=0;i<m;i++)
	{
	    for (int j=0;j<n;j++)
	    {
	        cin >> mat[i][j];
	    }
	}
	int count = 0;
	for (int i=0;i<m;i++)
	{
	    for (int j=0;j<n;j++)
	    {
	        if (mat[i][j]==1)
	        {
	            dfs(m,n,mat,i,j);
	            count++;
	        }
	    }
	}
	
	cout << count <<endl;
	
}

