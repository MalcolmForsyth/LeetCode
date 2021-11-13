/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Brute Solution: O(n^2)
This Solutioon: O(n)
*/

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums.at(i);
            if (m.find(complement) != m.end()) {
                return vector<int> {m.find(complement)->second, i};
            } else {
                m.insert(std::pair<int, int> (nums.at(i), i));
            }
        }
        return nums;
    }
};