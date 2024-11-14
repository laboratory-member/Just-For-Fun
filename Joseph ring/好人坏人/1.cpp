#include <iostream>
#include <vector>
using namespace std;

// 判断当前的m值是否满足条件
bool isValid(int k, int m) {
    int total = 2 * k;
    int pos = 0;

    for (int i = 0; i < k; i++) {
        pos = (pos + m - 1) % (total - i);  // 计算每次踢出位置

        // 如果踢出的序号在好人的范围内（0到k-1），则 m 不满足条件
        if (pos < k) return false;
    }
    return true; // 如果前k次踢出的全是坏人，则 m 满足条件
}

int findMinimumM(int k) {
    int m = k + 1;  // 从k+1开始尝试，因为小于k+1必不满足
    while (true) {
        if (isValid(k, m)) return m;
        m++;
    }
}

int main() {
    int k;
    while (cin >> k && k != 0) {
        cout << findMinimumM(k) << endl;
    }
    return 0;
}

