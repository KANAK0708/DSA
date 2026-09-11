class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();


        //taking row wise cumulative sum
        for(int row=0; row<rows;row++){
            for(int col=1;col<cols;col++){
                matrix[row][col]+=matrix[row][col-1];
            }
        }

        // now find no of subarrays with sum==target in downwards direction

        int result=0;

        for(int startcol=0;startcol<cols;startcol++){
            for(int j=startcol;j<cols;j++){
                unordered_map<int,int>mp;
                mp.insert({0,1});
                int cumsum=0;

                for(int row=0;row<rows;row++){
                    cumsum+=matrix[row][j]-(startcol>0?matrix[row][startcol-1]:0);

                    if(mp.find(cumsum-target)!=mp.end()){
                        result+=mp[cumsum-target];
                    }
                    mp[cumsum]++;
                }
            }
        }
        return result;
    }
};