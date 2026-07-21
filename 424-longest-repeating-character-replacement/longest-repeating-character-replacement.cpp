class Solution {
public:
    int characterReplacement(string s, int k) {
         int n=s.length();
         vector<int>count(26,0);
         int l=0;
         int maxlen=0;
         int maxf=0;

         for(int r=0;r<n;r++){
            count[s[r] - 'A']++;


            maxf=max(maxf,count[s[r]-'A']);

            if((r-l+1)-maxf>k){
                count[s[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
         }
         return maxlen;
    }
};