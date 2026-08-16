class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
         int zeros=0;
         int ones =0;
         int twos=0;
         for(int i:stones){
            int r = (i%3);
            if(r==0) zeros++;
            else if(r==1) ones ++;
            else twos++;
         }

         if(zeros%2==0) return ones>0 && twos>0;
         return abs(ones-twos)>2;
    }
};