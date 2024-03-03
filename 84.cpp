#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ret = 0;
        stack<int> st;
        st.push(0);

        int left;
        int mid;
        int right;

        int w;
        int h;

        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        for (int i = 1; i < heights.size(); ++i)
        {
            if (heights[i] > heights[st.top()])
            {
                st.push(i);
            }
            else if (heights[i] == heights[st.top()])
            {
                st.pop();
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[i] < heights[st.top()])
                {
                    mid = st.top();
                    st.pop();
                    if (!st.empty())
                    {
                        left = st.top();
                        right = i;
                        w = right - left - 1;
                        h = heights[mid];
                        ret = max(ret, w * h);
                    }
                }
                st.push(i);
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;

    std::vector<int> v = {2, 1, 5, 6, 2, 3};
    std::cout << s.largestRectangleArea(v) << std::endl;

    v = {2, 4, 6};
    std::cout << s.largestRectangleArea(v) << std::endl;

    v = {6, 4, 2};
    std::cout << s.largestRectangleArea(v) << std::endl;
}