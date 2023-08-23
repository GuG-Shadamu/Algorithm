/*
 * @Author: Tairan Gao
 * @Date:   2023-06-12 13:34:17
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-12 14:19:19
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <limits>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> dp(triangle.size(), numeric_limits<int>::max());
        dp[0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); i++)
        {
            auto row = triangle[i];
            vector<int> track(dp);
            for (int j = 0; j < row.size(); j++)
            {
                if (j == 0)
                {
                    dp[j] = (long)row[j] + (long)track[j];
                }
                else
                {
                    dp[j] = (long)row[j] + (long)min(track[j], track[j - 1]);
                }
            }
        }
        int res = numeric_limits<int>::max();
        for (int i = 0; i < dp.size(); i++)
        {
            res = min(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> triangle = {{-1}};
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}