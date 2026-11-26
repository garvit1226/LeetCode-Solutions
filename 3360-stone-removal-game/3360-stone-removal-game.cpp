class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int c= 10;
        int turn =1;
        while(n>=c){
            n-=c;
            c--;
            turn = 1- turn;
        }
        if(turn) return false;
        return true;

    }
};