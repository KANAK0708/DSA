class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mn=nums[0];
        int mx=nums[nums.size()-1];
        
        int gcd=1;

        for(int i=1; i<=mn && i<=mx; i++){
            if(mn % i == 0 && mx%i==0){
                gcd=i;
            }
        }
        return gcd;


    }
};