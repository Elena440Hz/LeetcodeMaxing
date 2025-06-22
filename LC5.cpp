class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> currentLongestPalindrome = {0, 1}; // [startIdx, endIdx) exclusive

        for (int i = 1; i < s.length(); ++i) {
            vector<int> odd = getLongestPalindrome(s, i - 1, i + 1);
            vector<int> even = getLongestPalindrome(s, i - 1, i);

            cout << "longest odd-length palindrome: [" << odd[0] << ", " << odd[1] 
                 << "], longest even-length palindrome: [" << even[0] << ", " << even[1] << "]" << endl;

            vector<int> potentialLongestPalindrome = 
                (odd[1] - odd[0] > even[1] - even[0]) ? odd : even;

            if (potentialLongestPalindrome[1] - potentialLongestPalindrome[0] > 
                currentLongestPalindrome[1] - currentLongestPalindrome[0]) {
                currentLongestPalindrome = potentialLongestPalindrome;
            }
        }

        return s.substr(currentLongestPalindrome[0], 
                        currentLongestPalindrome[1] - currentLongestPalindrome[0]);
    }

private:
    vector<int> getLongestPalindrome(const string& s, int leftIdx, int rightIdx) {
        while (leftIdx >= 0 && rightIdx < s.length() && s[leftIdx] == s[rightIdx]) {
            --leftIdx;
            ++rightIdx;
        }
        return {leftIdx + 1, rightIdx}; // Note: rightIdx is exclusive
    }
};
