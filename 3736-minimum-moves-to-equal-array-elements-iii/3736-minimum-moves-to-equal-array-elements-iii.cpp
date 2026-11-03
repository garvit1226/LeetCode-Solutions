class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans =0;
        int m = *max_element(nums.begin(), nums.end());
        for(int i:nums){
            ans+= m-i;
        }
        return ans;
    }
};