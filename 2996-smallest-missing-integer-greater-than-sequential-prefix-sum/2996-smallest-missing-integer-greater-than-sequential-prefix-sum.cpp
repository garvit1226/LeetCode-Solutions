class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        vector<bool>freq(52,false);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]] = true;
        }
        int num=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                num+=nums[i];
            }
            else{
                break;
            }
        }
        if(num>50) return num;
        for(int i=num;i<=52;i++){
            if(!freq[i]){
                return i;
            }
        }
        return 0;
    }
};