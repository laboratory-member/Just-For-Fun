#include <iostream>
#include <vector>
using namespace std;

// �жϵ�ǰ��mֵ�Ƿ���������
bool isValid(int k, int m) {
    int total = 2 * k;
    int pos = 0;

    for (int i = 0; i < k; i++) {
        pos = (pos + m - 1) % (total - i);  // ����ÿ���߳�λ��

        // ����߳�������ں��˵ķ�Χ�ڣ�0��k-1������ m ����������
        if (pos < k) return false;
    }
    return true; // ���ǰk���߳���ȫ�ǻ��ˣ��� m ��������
}

int findMinimumM(int k) {
    int m = k + 1;  // ��k+1��ʼ���ԣ���ΪС��k+1�ز�����
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

