class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;

        string vowels = "aeiouAEIOU";

        while (i < j) {

            // Find vowel from left
            while (i < j && vowels.find(s[i]) == string::npos) {
                i++;
            }

            // Find vowel from right
            while (i < j && vowels.find(s[j]) == string::npos) {
                j--;
            }

            // Swap vowels
            swap(s[i], s[j]);

            i++;
            j--;
        }

        return s;
    }
};