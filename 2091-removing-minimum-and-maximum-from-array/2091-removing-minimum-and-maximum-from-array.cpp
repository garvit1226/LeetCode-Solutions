class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[mini]>nums[i]){
                mini=i;
            }
            if(nums[maxi]<nums[i]){
                maxi=i;
            }
        }

        int left = min(mini, maxi);
        int right = max(maxi,mini);

        return min(right+1, min(n-left, left+1 +n-right));
    }
};