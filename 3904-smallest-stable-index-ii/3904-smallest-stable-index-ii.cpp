class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxp(n);
        maxp[0]= nums[0];
        for(int i=1;i<n;i++){
            maxp[i] = max(maxp[i-1],nums[i]);
        }

        vector<int> minp(n);
        minp[n-1]= nums[n-1];
        for(int i=n-2;i>=0;i--){
            minp[i] = min(minp[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            if(maxp[i]-minp[i]<=k){
                return i;
            }
        }
        return -1;
    }
};