class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> last(m,-1);
        for(int i=n-1, j=m-1;i>=0 && j>=0;i--){
            if(word1[i]==word2[j]){
                last[j] = i;
                j--;
            }
        }
        int j=0;
        vector<int> ans(m);
        bool change = true;
        for(int i=0;i<n;i++){
            if(word1[i] == word2[j]){
                ans[j++] = i;

            }
            else if(change && (j==m-1 || i<last[j+1])){
                ans[j++] = i;
                change = false;
            }
            if(j==m){
                return ans;
            }
        }
            return {};
    }
};