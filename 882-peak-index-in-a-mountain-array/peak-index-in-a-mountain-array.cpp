class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] < arr[mid + 1]) {
                // We are in the increasing part of the mountain, peak is to the right
                left = mid + 1;
            } else {
                // We are in the decreasing part or at the peak, peak is at mid or to the left
                right = mid;
            }
        }
        
        return left;
    }
};