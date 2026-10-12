#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

bool isPerfectNumber(uint64_t n) {
    if (n == 1) {
        return false; // 1 has no proper divisors
    }
    
    uint64_t sum = 1; // 1 is always a proper divisor for n > 1
    
    for (uint64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            uint64_t complement = n / i;
            if (complement != i && complement != n) {
                sum += complement;
            }
        }
    }
    
    return sum == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m;
    cin >> m;
    
    vector<uint64_t> numbers(m);
    for (int i = 0; i < m; ++i) {
        cin >> numbers[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cout << (isPerfectNumber(numbers[i]) ? 1 : 0);
        if (i < m - 1) {
            cout << "\n";
        }
    }
    
    return 0;
}