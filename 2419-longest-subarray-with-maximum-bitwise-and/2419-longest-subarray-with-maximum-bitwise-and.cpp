class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());

        int ans =0;
        int count =0;
        for(int i:nums){
            if(i==mx){
                count++;
                ans = max(ans,count);
            }
            else{
                count=0;
            }
        }
        return ans;
    }
};