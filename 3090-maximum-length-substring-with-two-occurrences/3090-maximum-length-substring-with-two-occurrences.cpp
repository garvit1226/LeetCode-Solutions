class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int r=0,l=0;
        int ans = 0;
        while(r<s.size()){
            freq[s[r]]++;
            while(freq[s[r]]>2){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};