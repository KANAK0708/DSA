class Solution {
public:
    int kthFactor(int n, int k) {
        
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                --k;
                if (k == 0) {
                    return i;
                }
            }
        }

        // 2. Check larger paired factors (n / i) in ascending order
        // Start from largest i where i * i < n so we don't duplicate sqrt(n)
        int i = 1;
        while ((i + 1) * (i + 1) < n) {
            ++i;
        }
        if (i * i >= n) {
            --i;
        }

        for (; i >= 1; --i) {
            if (n % i == 0) {
                --k;
                if (k == 0) {
                    return n / i;
                }
            }
        }

        return -1;
    }
};