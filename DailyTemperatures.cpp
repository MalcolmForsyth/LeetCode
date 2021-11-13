/**
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.


Brute Solution: O(n ^ 2)
This Solution: O(n)
*/
#include <vector>
using std::vector;
class DailyTemperatures {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        std::stack<int> s;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            int temp = temperatures.at(i);
            if (s.empty()) {
                s.push(i);
            } else {
                while(!s.empty() && temp >= temperatures.at(s.top())) {
                    s.pop();
                }
                if (s.empty()) {
                    answer.at(i) = 0;
                } else {
                    answer.at(i) = (s.top() - i);
                }
                s.push(i);
            }    
        }
        while (answer.size() < temperatures.size()) {
            answer.push_back(0);
        }
    return answer;
    }
};

