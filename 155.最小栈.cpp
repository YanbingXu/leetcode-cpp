/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    MinStack() {
        // if (!sk_common.empty())
        // {
        //     sk_common.clear();
        // }

        // if (!sk_min.empty())
        // {
        //     sk_min.clear();
        // }


    }

    void push(int val) {
        sk_common.push(val);

        if (!sk_min.empty())
        {
            if (sk_min.top() >= val)
            {
                sk_min.push(val);
            }

        }else{
            sk_min.push(val);
        }


    }

    void pop() {
        int top_sk1 = sk_common.top();
        sk_common.pop();
        if (!sk_min.empty())
        {
            if (sk_min.top()>=top_sk1)
            {
                sk_min.pop();
            }
        }




    }

    int top() {
        return sk_common.top();

    }

    int getMin() {
        return sk_min.top();

    }
private:
    stack<int>sk_common;
    stack<int>sk_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

