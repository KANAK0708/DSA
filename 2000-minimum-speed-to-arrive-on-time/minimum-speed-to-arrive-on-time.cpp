class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        // If hours are less than n - 1, it's mathematically impossible 
        // because each of the first n-1 trains takes at least 1 hour.
        if (hour <= n - 1) return -1;
        
        int left = 1, right = 1e7;
        int minSpeed = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            double totalHours = 0;
            
            for (int i = 0; i < n - 1; ++i) {
                totalHours += ceil((double)dist[i] / mid);
            }
            // The last train does not require waiting for the next hour
            totalHours += (double)dist[n - 1] / mid;
            
            if (totalHours <= hour) {
                minSpeed = mid;
                right = mid - 1; // Try to find a smaller valid speed
            } else {
                left = mid + 1;  // Need a higher speed
            }
        }
        
        return minSpeed;
    }
};