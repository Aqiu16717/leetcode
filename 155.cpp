#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        if (min_stk.empty() || val < min_stk.top()) {
            min_stk.push(val);
        }
        stk.push(val);
    }

    void pop() {
        if (stk.top() == min_stk.top()) {
            min_stk.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }

private:
    stack<int> stk;
    stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    // ["MinStack","push","push","push","getMin","top","pop","getMin"]
    // [[],[-2],[0],[-1],[],[],[],[]]
    // [null,null,null,null,-2,-1,null,-2]
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-1);

    std::cout << "Min: " << obj->getMin() << std::endl;  // Should print -2
    std::cout << "Top: " << obj->top() << std::endl;     // Should print -1

    obj->pop();

    std::cout << "Min after pop: " << obj->getMin()
              << std::endl;  // Should print -2

    // Clean up
    delete obj;
    return 0;
}
