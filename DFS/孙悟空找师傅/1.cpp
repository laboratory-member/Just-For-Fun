#include <iostream>
#include <vector>

using namespace std;

// 定义四个方向：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dfs(vector<vector<int>>& maze, int x, int y, int m, int n) {
    // 如果到达师傅的位置，返回 true
    if (maze[x][y] == 3) {
        return true;
    }

    // 标记当前点为访问过，避免重复访问
    maze[x][y] = -1;

    // 遍历四个方向
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 检查边界条件和是否可以访问
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && (maze[nx][ny] == 0 || maze[nx][ny] == 3)) {
            if (dfs(maze, nx, ny, m, n)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> maze(m, vector<int>(n));
    int startX, startY;

    // 读取迷宫并找到悟空的初始位置
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    // 调用 DFS 从悟空的位置开始搜索
    if (dfs(maze, startX, startY, m, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

