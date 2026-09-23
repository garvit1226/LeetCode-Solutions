class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total =0;
        for(int i:nums){
            total+= i;
        }

        if(total==x){
            return nums.size();
        }

        int target = total-x;

        int left =0;
        int right =0;
        int sum=0;
        int maxlen=-1;

        while(right< nums.size()){
            sum+= nums[right];

            while(left<=right && sum>target){
                sum-= nums[left];
                left++;
            }

            if(sum==target){
                maxlen = max(maxlen, right-left+1);
            }

            right++;
        }
        if(maxlen==-1) return -1;
        return nums.size() - maxlen;
    }
};