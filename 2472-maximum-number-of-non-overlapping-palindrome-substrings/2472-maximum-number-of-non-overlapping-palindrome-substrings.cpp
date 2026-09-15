class Solution {
public:
    bool check(string s, int r, int l){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int ans=0;
        int start=0;
        int n = s.size();
        for(int r=k-1;r<n;r++){
            for(int len = k ;len<= r-start+1;len++){
                int l = r-len+1;
                if(check(s,r,l)){
                    ans++;
                    start = r+1;
                    break;
                }
            }
        }
        return ans;
    }
};