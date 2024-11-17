#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ��������������������Ľ��
int operate(int a, int b, char op) {
    return (op == '+') ? (a + b) : (a * b);
}

int main() {
    int n;
    cin >> n;  // ������

    // ���붥��ֵ�������
    vector<int> values(n);
    vector<char> ops(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i] >> ops[i];
    }

    // ��չ�������������㴦��
    for (int i = 0; i < n; ++i) {
        values.push_back(values[i]);
        ops.push_back(ops[i]);
    }

    // ��̬�滮���� dp[i][j]����ʼ��Ϊ 0
    vector<vector<int>> dp(2 * n, vector<int>(2 * n, 0));

    // ���������ֵ
    for (int i = 0; i < 2 * n; ++i) {
        dp[i][i] = values[i];
    }

    // ö�����䳤�ȣ��� 2 �� n
    for (int len = 1; len < n; ++len) {
        for (int i = 0; i + len < 2 * n; ++i) {
            int j = i + len;  // �����Ҷ˵�
            for (int k = i; k < j; ++k) {
                // ���仮��Ϊ [i, k] �� [k+1, j]
                dp[i][j] = max(dp[i][j], operate(dp[i][k], dp[k + 1][j], ops[k % n]));
            }
        }
    }

    // ö�ٻ�����㣬�ҳ����ֵ
    int maxScore = 0;
    for (int i = 0; i < n; ++i) {
        maxScore = max(maxScore, dp[i][i + n - 1]);
    }

    // ������
    cout << maxScore << endl;
    return 0;
}

