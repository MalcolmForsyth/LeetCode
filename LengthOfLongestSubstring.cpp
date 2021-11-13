/**
Given a string s, find the length of the longest substring without 
repeating characters.

Brute Solution: O(n^3)
This Solution: O(n)
*/

class LongestSubStringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1) {
            return s.length();
        }
        int max_l = 1;
        bool visited[256];
        for (int i = 0; i < 256; i++) {
            visited[i] = false;
        }
        int i = 0;
        int j = 0;
        int n = s.length();
        while (i < n && j < n) {
            if (!visited[s.at(j)]) {
                max_l = std::max(max_l, j - i + 1);
                visited[s.at(j)] = true;
                j++;
            } else {
                visited[s.at(i)] = false;
                i++;
            }
            
        }
        return max_l;
    }
};