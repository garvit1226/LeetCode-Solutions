class Solution {
public:
    int reverseDegree(string s) {
        int ans =0;
        for(int i=0;i<s.size();i++){
            int j = s[i] - 'a';
            ans += ((26-j)*(i+1));
        }
        return ans;
    }
};