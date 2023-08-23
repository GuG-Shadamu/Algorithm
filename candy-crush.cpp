/*
 * @Author: Tairan Gao
 * @Date:   2023-08-22 10:08:28
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-08-22 15:42:39
 */
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <iomanip>
#include <cmath>
#include <unordered_set>
#include <utility>
#include <deque>

using namespace std;
void print2DVector(vector<vector<int>> &board)
{
    size_t maxLen = 0;
    for (auto &row : board)
    {
        for (auto &num : row)
        {
            maxLen = max(maxLen, to_string(num).size());
        }
    }

    for (auto &row : board)
    {
        for (auto &num : row)
        {
            cout << setw(maxLen) << num << " ";
        }
        cout << endl;
    }
    cout << "== == == == ==" << endl;
}

class Solution
{

public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board)
    {
        while (crush(board))
        {
            drop(board);
        }
        return board;
    }

private:
    int crush(vector<vector<int>> &board)
    {
        vector<vector<vector<int>>> dp(board.size(), vector<vector<int>>(board[0].size(), vector<int>(2, 1)));
        // down, right
        int count = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 0)
                    continue;
                // up
                if (i > 0)
                {
                    if (board[i][j] == board[i - 1][j])
                    {
                        dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + 1);
                    }
                }
                // left
                if (j > 0)
                {
                    if (board[i][j] == board[i][j - 1])
                    {
                        dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1] + 1);
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if (dp[i][j][k] >= 4)
                    {
                        board[i][j] = 0;
                        count += 1;
                        continue;
                    }
                    if (dp[i][j][k] == 3)
                    {
                        count += 3;
                        if (k == 0)
                        {
                            board[i][j] = 0;
                            board[i - 1][j] = 0;
                            board[i - 2][j] = 0;
                            continue;
                        }
                        if (k == 1)
                        {
                            board[i][j] = 0;
                            board[i][j - 1] = 0;
                            board[i][j - 2] = 0;
                            continue;
                        }
                    }
                }
            }
        }
        return count;
    };

    void drop(vector<vector<int>> &board)
    {

        for (int j = 0; j < board[0].size(); j++)
        {
            int cur_idx = board.size() - 1;
            for (int i = board.size() - 1; i >= 0; i--)
            {
                if (board[i][j] == 0)
                    continue;
                if (board[cur_idx][j] != 0)
                {
                    cur_idx -= 1;
                    continue;
                }
                board[cur_idx][j] = board[i][j];
                board[i][j] = 0;
                cur_idx -= 1;
            }
        }
    }
    // print 2d board with format, that every element has the same width
};

int main()
{
    Solution s;
    vector<vector<int>> board = {{110, 5, 112, 113, 114}, {210, 211, 5, 213, 214}, {310, 311, 3, 313, 314}, {410, 411, 412, 5, 414}, {5, 1, 512, 3, 3}, {610, 4, 1, 613, 614}, {710, 1, 2, 713, 714}, {810, 1, 2, 1, 1}, {1, 1, 2, 2, 2}, {4, 1, 4, 4, 1014}};
    auto newBoard = s.candyCrush(board);
    return 0;
}