class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int i=0,j=0;
        int ans = 0;
        while(i<nums.size()){
            mpp[nums[i]]++;
            while(mpp[nums[i]]>k){
                mpp[nums[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};