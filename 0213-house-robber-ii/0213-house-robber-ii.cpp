class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(f(temp1), f(temp2));
    }
    int f(vector<int> nums){
        int n= nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+= prev2;
            int nottake = prev;

            int curr = max(take, nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};