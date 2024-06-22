//https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/541304595/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        size_t len = 0;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum >= target)
            {
                sum -= nums[left];
                if (len == 0) len = (right - left + 1);
                else len = (right - left + 1) < len ? (right - left + 1) : len;
                if (left < nums.size() - 1)
                    left++;
            }
            right++;
        }
        return len;
    }
};