class Solution {
public:
int canPlace(vector<int>& position,int m ,int force){
        int n=position.size();
        int count=1;
        int lastplaced=position[0];

        for(int i=1;i<n;++i){
            if(position[i]-lastplaced>=force){
                count++;
                lastplaced=position[i];
                if(count==m){
                    return true;

        
                }
            }
        }
        return false;
       

        
}
public:
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());
        int n=position.size();
        int low=1;
        int high=position[n-1]-position[0];
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(canPlace(position,m,mid)){
                ans=mid;
                low=mid+1;
            } else{
                high=mid-1;
            }
        }

        return ans;
        
        
    }
};