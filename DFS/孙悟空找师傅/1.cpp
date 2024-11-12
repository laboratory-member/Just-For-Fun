#include <iostream>
#include <vector>

using namespace std;

// �����ĸ������ϡ��¡�����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dfs(vector<vector<int>>& maze, int x, int y, int m, int n) {
    // �������ʦ����λ�ã����� true
    if (maze[x][y] == 3) {
        return true;
    }

    // ��ǵ�ǰ��Ϊ���ʹ��������ظ�����
    maze[x][y] = -1;

    // �����ĸ�����
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // ���߽��������Ƿ���Է���
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

    // ��ȡ�Թ����ҵ���յĳ�ʼλ��
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 2) {
                startX = i;
                startY = j;
            }
        }
    }

    // ���� DFS ����յ�λ�ÿ�ʼ����
    if (dfs(maze, startX, startY, m, n)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

