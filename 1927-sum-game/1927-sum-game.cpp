class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sum1 = 0, ques1 = 0;
        int sum2 = 0, ques2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                ques1++;
            else
                sum1 += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                ques2++;
            else
                sum2 += num[i] - '0';
        }

        int sumdif = sum1 - sum2;
        int quesdif = ques1 - ques2;

        if (quesdif == 0) {
            return sumdif != 0;
        }

        if (quesdif % 2 != 0) {
            return true;
        }

        return sumdif != 9 * (ques2 - ques1) / 2;
    }
};