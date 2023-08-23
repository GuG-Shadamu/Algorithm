/*
 * @Author: Tairan Gao
 * @Date:   2023-06-07 10:55:53
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-09 13:26:18
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int pre = nums[0];
        size_t idx = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] != pre)
            {
                nums[idx] = nums[i];
                pre = nums[i];
                idx += 1;
            }
        }
        return idx;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    s.removeDuplicates(nums);

    return 0;
}