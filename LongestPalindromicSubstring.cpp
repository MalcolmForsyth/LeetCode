/**
Given a string s, return the longest palindromic substring in s.

Brute Solution: O(n^3)
This Solution: O(n^2)
*/

class LongestPalindromicSubstring {
public:
    string longestPalindrome(string s) {
        string r = "";
        int max_length = 0;
        if (s.length() == 0 || s.length() == 1) {
            return s;
        }
        for (int i = 0; i < s.length(); i++) {
            int j = i;
            while (s.at(i) == s.at(j) && j < s.length() - 1) {
                j++;
            }
            string maybe = expand(s, i, j - 1);
            if (maybe.length() > max_length) {
                r = maybe;
                max_length = maybe.length();
            }
        }
        return r;
    }
    
    string expand(string s, int begin, int end) {
        while(begin >= 0 && end < s.length() && s.at(begin) == s.at(end)) {
            begin--;
            end++;
        }
        return s.substr(begin + 1, end - begin - 1);
    }
};