class Solution {
public:

    bool f(int n, int tar, vector<int>& nums){
        vector<bool> curr(tar+1,false) , prev(tar+1,false);
        curr[0] = true;
        prev[0] = true;
        if(nums[0]<=tar){
        prev[nums[0]] = true;
        }
        for(int i=1;i<n;i++){
            
            for(int k=1;k<=tar;k++){
                bool nottake = prev[k];
                bool take = false;
                if(k>=nums[i]){
                    take = prev[k-nums[i]];
                }

                curr[k] = nottake|take;
            }
            prev = curr;
        }

        return prev[tar];

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i:nums){
            sum+= i;
        }
        if(sum%2) return false;
        return f(n,sum/2, nums);
    }
};