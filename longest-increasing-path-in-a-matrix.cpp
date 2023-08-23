/*
 * @Author: Tairan Gao
 * @Date:   2023-08-17 11:00:55
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-08-17 11:27:09
 */

#include <limits.h>
#include <tuple>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sol(m, vector<int>(n, 0));
        int x, y, pre_v, pre_dis, cur_dis;
        int longest = 0;
        deque<tuple<int, int, long, int>> queue;

        queue.push_back({0, 0, long(matrix[0][0]) + 1, 1});

        while (!queue.empty())
        {
            tie(x, y, pre_v, pre_dis) = queue.front();
            queue.pop_front();

            if (matrix[x][y] > pre_v)
            {
                cur_dis = max(pre_dis + 1, sol[x][y]);
            }
            else
            {
                cur_dis = 1;
            }

            if (cur_dis <= sol[x][y]) // nothing changed
                continue;

            // change
            sol[x][y] = cur_dis;

            if (x > 0)
            {
                queue.push_back({x - 1, y, matrix[x][y], cur_dis});
            }
            if (x < m - 1)
            {
                queue.push_back({x + 1, y, matrix[x][y], cur_dis});
            }
            if (y > 0)
            {
                queue.push_back({x, y - 1, matrix[x][y], cur_dis});
            }
            if (y < n - 1)
            {
                queue.push_back({x, y + 1, matrix[x][y], cur_dis});
            }
        }
        for (auto row : sol)
        {
            for (auto col : row)
            {
                longest = max(col, longest);
            }
        }

        return longest;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1}};
    Solution sol;
    cout << sol.longestIncreasingPath(matrix) << endl;
    return 0;
}