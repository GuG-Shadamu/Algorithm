/*
 * @Author: Tairan Gao
 * @Date:   2023-08-17 10:39:00
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-08-17 10:44:21
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
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int x, y, dis;

        vector<vector<int>> sol(m, vector<int>(n, INT_MAX));
        deque<tuple<int, int, int>> queue;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    queue.push_back({i, j, 0});
                }
            }
        }
        while (!queue.empty())
        {
            tie(x, y, dis) = queue.front();
            if (dis < sol[x][y])
            {
                sol[x][y] = dis;
                if (x > 0)
                {
                    queue.push_back({x - 1, y, dis + 1});
                }
                if (x < m - 1)
                {
                    queue.push_back({x + 1, y, dis + 1});
                }
                if (y > 0)
                {
                    queue.push_back({x, y - 1, dis + 1});
                }
                if (y < n - 1)
                {
                    queue.push_back({x, y + 1, dis + 1});
                }
            }
            queue.pop_front();
        }
        return sol;
    }
};

int main()
{
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution sol;
    vector<vector<int>> res = sol.updateMatrix(mat);
    for (auto row : res)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}