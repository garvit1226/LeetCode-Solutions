class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int temp = 0;
        bool pos = false;
        for(int i:nums){
            pos|= i>0;
            temp^=i;
        }
        if(temp!=0) return nums.size();
        if(pos) return nums.size()-1;
        return 0;
    }
};