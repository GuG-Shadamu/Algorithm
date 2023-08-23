/*
 * @Author: Tairan Gao
 * @Date:   2023-05-24 14:36:07
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-09 13:26:18
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        long long sum = 0;
        long long res = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({nums2[i], nums1[i]});
        }
        sort(arr.rbegin(), arr.rend()); // 降序排列
        int min_val = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            min_val = min(min_val, arr[i].first);
            sum += arr[i].second;
            pq.push(arr[i].second);
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
            {
                res = max(res, sum * min_val);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> num1 = {1, 3, 3, 2};
    vector<int> num2 = {2, 1, 3, 4};

    auto sol = s.maxScore(num1, num2, 3);
    cout << sol << endl;
    return 0;
}