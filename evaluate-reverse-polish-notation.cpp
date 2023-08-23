/*
 * @Author: Tairan Gao
 * @Date:   2023-06-07 13:29:57
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-09 13:26:18
 */

#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a + b);
            }
            else if (tokens[i] == "-")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            }
            else if (tokens[i] == "*")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);
            }
            else if (tokens[i] == "/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};

int main()
{
    Solution s;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    auto res = s.evalRPN(tokens);
    cout << res << endl;
    return 0;
}