class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd = INT_MAX;
        for(int i:nums1){
            if(i%2){
                minodd = min(minodd,i);
            }
        }

        for(int i:nums1){
            if(i%2==0 && minodd!=INT_MAX && i<minodd){
                return false;
            }
        }
        return true;
    }
};