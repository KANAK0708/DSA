class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> distinctPrimes;

        for (int x : nums) {
            int temp = x;

            for (int d = 2; d * d <= temp; ++d) {
                if (temp % d == 0) {
                    distinctPrimes.insert(d);
                    while (temp % d == 0) {
                        temp /= d;
                    }
                }
            }

            // If a prime factor larger than sqrt(initial x) remains
            if (temp > 1) {
                distinctPrimes.insert(temp);
            }
        }

        return static_cast<int>(distinctPrimes.size());
    }
};