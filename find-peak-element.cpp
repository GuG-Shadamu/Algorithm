/*
 * @Author: Tairan Gao
 * @Date:   2023-06-09 13:26:59
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-09 14:44:28
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + right >> 1;

            if (mid != 0 && nums[mid] < nums[mid - 1]) // less than left
            {
                right = mid - 1;
                continue;
            }
            else if ((mid != nums.size() - 1) && (nums[mid] < nums[mid + 1])) // less than right
            {
                left = mid + 1;
                continue;
            }
            else
            {
                return mid;
            }
        }
        return -1; // should never be here
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1};
    cout << solution.findPeakElement(nums) << endl;

    return 0;
}