class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp == 0) return 1.0;

        if (exp < 0) {
            exp = -exp;
            long double base = 1.0L / static_cast<long double>(x);
            long double ans = 1.0L;
            while (exp > 0) {
                if (exp & 1) ans *= base;
                base *= base;
                exp >>= 1;
            }
            return static_cast<double>(ans);
        }

        long double base = static_cast<long double>(x);
        long double ans = 1.0L;
        while (exp > 0) {
            if (exp & 1) ans *= base;
            base *= base;
            exp >>= 1;
        }
        return static_cast<double>(ans);
    }
};