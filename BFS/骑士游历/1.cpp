#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// C++³õÊ¼Ä£°å³ÌÐò
pair<int,int> convert(string str)
{
    int a = str[0]-'a';
    int b = str[1]-'1';
    return {a,b};
}

int bfs(pair<int,int>point1,pair<int,int>point2)
{
    bool visited[8][8] = {0};
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    queue<pair<int,int>> q;
    q.push(point1);
    visited[point1.first][point1.second] = 1;
    int step = 0;
    if (point1==point2) return step;
    while (!q.empty()) {
        int size = q.size(); 
        for (int i = 0; i < size; i++) {
            pair<int, int> current = q.front();
            q.pop();

            for (int j = 0; j < 8; j++) {
                int x1 = current.first + dx[j];
                int y1 = current.second + dy[j];

                if (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8 && !visited[x1][y1]) {
                    visited[x1][y1] = 1;
                    q.push({x1, y1});
                    
                    if (x1 == point2.first && y1 == point2.second) {
                        return step + 1;
                    }
                }
            }
        }
        step++;
    }
    return -1;
}

int main() {
	string s1,s2;
	while (cin >> s1 >> s2)
	{
	    pair<int,int> point1 = convert(s1);
	    pair<int,int> point2 = convert(s2);
	    cout <<"To get from "<<s1<<" to "<<s2<<" takes "<< bfs(point1,point2) <<" knight moves."<< endl;
	}
	return 0;
}

