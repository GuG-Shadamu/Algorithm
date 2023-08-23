/*
 * @Author: Tairan Gao
 * @Date:   2023-06-11 00:54:57
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-11 01:37:40
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    long long calc_sum(int top, int n, int index)
    {
        long long res = top;
        int left = index;
        int right = n - index - 1;

        if (top - 1 > left)
        {
            res += (long)((top - 1) + (top - left)) * left / 2;
        }
        else
        {
            res += (long)((top - 1) + 1) * (top - 1) / 2 + left - top + 1;
        }
        if (top - 1 > right)
        {
            res += (long)((top - 1) + (top - right)) * right / 2;
        }
        else
        {
            res += (long)((top - 1) + 1) * (top - 1) / 2 + right - top + 1;
        }

        return res;
    }

    int maxValue(int n, int index, int maxSum)
    {
        int small = maxSum / n;
        int large = maxSum;
        int mid = small;
        while (small < large)
        {
            mid = (small + large) >> 1;
            long long cur_sum = calc_sum(mid, n, index);
            if (cur_sum == maxSum)
                return mid;

            if (cur_sum > maxSum)
            {
                large = mid;
                continue;
            }
            if (cur_sum < maxSum)
            {
                if (calc_sum(mid + 1, n, index) > maxSum)
                {
                    return mid;
                }
                small = mid;
                continue;
            }
        }
        return mid;
    }
};

int main()
{
    Solution sol;
    cout << sol.maxValue(4, 0, 4) << endl;
    cout << sol.maxValue(6, 1, 10) << endl;
    cout << sol.maxValue(10, 0, 100) << endl;
    return 0;
}