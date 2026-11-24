class Solution {
public:
    bool isThree(int n) {
        int root = static_cast<int>(std::sqrt(n));
        if (root * root != n || root < 2) {
            return false;
        }
        for (int d = 2; d * d <= root; ++d) {
            if (root % d == 0) {
                return false;
            }
        }
        return true;
    }
};