#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 辅助函数：计算操作符的结果
int operate(int a, int b, char op) {
    return (op == '+') ? (a + b) : (a * b);
}

int main() {
    int n;
    cin >> n;  // 顶点数

    // 输入顶点值和运算符
    vector<int> values(n);
    vector<char> ops(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i] >> ops[i];
    }

    // 扩展数组两倍，方便处理环
    for (int i = 0; i < n; ++i) {
        values.push_back(values[i]);
        ops.push_back(ops[i]);
    }

    // 动态规划数组 dp[i][j]，初始化为 0
    vector<vector<int>> dp(2 * n, vector<int>(2 * n, 0));

    // 单个顶点的值
    for (int i = 0; i < 2 * n; ++i) {
        dp[i][i] = values[i];
    }

    // 枚举区间长度，从 2 到 n
    for (int len = 1; len < n; ++len) {
        for (int i = 0; i + len < 2 * n; ++i) {
            int j = i + len;  // 区间右端点
            for (int k = i; k < j; ++k) {
                // 区间划分为 [i, k] 和 [k+1, j]
                dp[i][j] = max(dp[i][j], operate(dp[i][k], dp[k + 1][j], ops[k % n]));
            }
        }
    }

    // 枚举环的起点，找出最大值
    int maxScore = 0;
    for (int i = 0; i < n; ++i) {
        maxScore = max(maxScore, dp[i][i + n - 1]);
    }

    // 输出结果
    cout << maxScore << endl;
    return 0;
}

