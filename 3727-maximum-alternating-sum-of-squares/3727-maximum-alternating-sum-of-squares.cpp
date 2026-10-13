class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i] = -nums[i];
            }
        }
        sort(nums.begin(), nums.end());

        long long sum=0;
        int size = n/2;
        int i;     
        
        for(i=0;i<size;i++){
            sum-= 1LL* nums[i]* nums[i];
        }
        while(i<n){
            sum+= 1LL* nums[i]*nums[i];
            i++;
        }
        return sum;
    }
};