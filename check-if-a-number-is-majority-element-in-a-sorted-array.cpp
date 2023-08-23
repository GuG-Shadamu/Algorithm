/*
 * @Author: Tairan Gao
 * @Date:   2023-06-11 01:50:35
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-11 02:01:50
 */
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMajorityElement(vector<int> &nums, int target)
    {
        // find left
        int left, right, mid;
        left = 0;
        right = nums.size() - 1;
        int start = nums.size() + 100;
        int end = -1;

        if (nums[0] == target)
        {
            start = 0;
        }
        else
        {
            while (left <= right)
            {
                mid = (left + right) >> 1;

                if (nums[mid] < target)
                {
                    left = mid + 1;
                    continue;
                }
                if (nums[mid] >= target)
                {
                    if (nums[mid] == target && nums[mid - 1] < target)
                    {
                        start = mid;
                        break;
                    }
                    right = mid - 1;
                    continue;
                }
            }
        }

        left = start;
        right = nums.size() - 1;

        if (nums[nums.size() - 1] == target)
        {
            end = nums.size() - 1;
        }
        else
        {
            while (left <= right)
            {
                mid = (left + right) >> 1;
                if (nums[mid] <= target)
                {
                    if (nums[mid] == target && nums[mid + 1] > target)
                    {
                        end = mid;
                        break;
                    }
                    left = mid + 1;
                    continue;
                }
                if (nums[mid] > target)
                {
                    right = mid - 1;
                    continue;
                }
            }
        }

        return (end - start + 1 > nums.size() / 2);
    }
};

int main()
{
    Solution s;
    // vector<int> nums = {2, 4, 5, 5, 5, 5, 5, 6, 6};

    // cout << s.isMajorityElement(nums, 5) << endl;
    vector<int> nums2 = {10};
    cout << s.isMajorityElement(nums2, 101) << endl;
    return 0;
}