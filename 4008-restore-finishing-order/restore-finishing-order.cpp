class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int>friendset(friends.begin(),friends.end());

        vector<int>result;

        for(int p:order){
            if(find(friends.begin(),friends.end(),p)!=friends.end()){
                 result.push_back(p);

            }
        }

        return result;
    }
};