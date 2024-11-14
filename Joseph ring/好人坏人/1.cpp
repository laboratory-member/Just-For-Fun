#include <iostream>
#include <vector>
using namespace std;

bool isValid(int k, int m) {
    int total = 2 * k;
    int pos = 0;

    for (int i = 0; i < k; i++) {
        pos = (pos + m - 1) % (total - i);

        if (pos < k) return false;
    }
    return true;
}

int main() {
    int k;
    while (cin >> k && k != 0) {
        int m = k + 1; 
        while (true) {
            if (isValid(k, m))
            {
                cout << m <<endl;
                break;
            }
            m++;
        }
    }
    return 0;
}
