class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>>P(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                P[i][j]=mat[i-1][j-1]+P[i-1][j]+P[i][j-1]-P[i-1][j-1];
            }
        }

        int low=1;
        int high=min(m,n);
        int best_length=0;


        while(low<=high){
            int mid=low+(high-low)/2;


        if(isValid(mid,P,threshold,m,n)){
            best_length=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }     
    }


return best_length;
    }

private:

    bool isValid(int k, const vector<vector<int>>&P,int threshold,int m,int n){
        for(int i=k;i<=m;++i){
            for(int j=k;j<=n;++j){
                int current_sum=P[i][j] - P[i - k][j] - P[i][j - k] + P[i - k][j - k];

                if(current_sum<=threshold){
                    return true;
                }
            }
        }

        return false;
    }
};