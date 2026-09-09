class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long limit=1000;
        while(limit<=n){
            ans += n-limit+1;
            limit*=1000;
        }
        return ans;
    }
};