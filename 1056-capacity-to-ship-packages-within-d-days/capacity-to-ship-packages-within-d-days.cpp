class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0; 
        int right = 0;

        for(int w:weights){
            left=max(left,w);
            right+=w;
        }


        while (left < right) {
            int mid = left + (right - left) / 2;
            int daysNeeded = 1;
            int currentLoad = 0;



            for (int w : weights) {
                if (currentLoad + w > mid) {
                    daysNeeded++;      // Need a new day
                    currentLoad = 0;   // Reset load for the new day
                }
                currentLoad += w;
            }


            if (daysNeeded > days) {
                left = mid + 1;
            } 
            // If it takes less or equal days, try to find a smaller capacity
            else {
                right = mid;
            }
        }
        
        return left;


    }
};