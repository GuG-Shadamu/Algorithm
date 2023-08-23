/*
 * @Author: Tairan Gao
 * @Date:   2023-06-07 13:23:21
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-06-07 13:28:49
 */

#include <stack>
#include <utility>
#include <limits>
#include <iostream>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> s;
    int current_min;
    MinStack()
    {
        current_min = numeric_limits<int>::max(); // minimum value
    }

    void push(int val)
    {
        current_min = min(current_min, val);
        s.emplace(val, current_min);
    }

    void pop()
    {
        s.pop();
        if (s.size() == 0)
        {
            current_min = numeric_limits<int>::max();
            return;
        }
        current_min = s.top().second;
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return current_min;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack s;
    s.push(2147483646);
    s.push(2147483646);
    s.push(2147483646);

    s.top();
    s.pop();

    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.push(2147483646);
    s.top();
    s.getMin();
    s.push(-2147483646);
    s.top();
    s.getMin();
    s.pop();
    s.getMin();

    return 0;
}