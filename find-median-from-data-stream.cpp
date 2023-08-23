/*
 * @Author: Tairan Gao
 * @Date:   2023-08-18 10:51:27
 * @Last Modified by:   Tairan Gao
 * @Last Modified time: 2023-08-18 11:21:38
 */

#include <limits.h>
#include <tuple>
#include <vector>
#include <iostream>
#include <deque>
#include <set>

using namespace std;

class MedianFinder
{
public:
    MedianFinder() : left(list.cend()), right(list.cbegin()){};

    void addNum(int num)
    {
        if (list.empty())
        {
            left = right = list.insert(num);
            return;
        }
        list.insert(num);
        size_t n = list.size();
        if (n & 1) // odd
        {
            if (num >= *right)
            {
                left = right;
            }
            else
            {
                left = --right;
            }
        }
        else
        {
            if (num >= *right)
            {
                right++;
            }
            else
            {
                left--;
            }
        }
    }

    double findMedian()
    {
        return static_cast<double>(*left + *right) / 2.0;
    }

private:
    multiset<int> list;
    multiset<int>::iterator left;
    multiset<int>::iterator right;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    double param_2 = obj->findMedian();
    std::cout << param_2 << std::endl;
    obj->addNum(3);
    param_2 = obj->findMedian();
    std::cout << param_2 << std::endl;
    return 0;
}
