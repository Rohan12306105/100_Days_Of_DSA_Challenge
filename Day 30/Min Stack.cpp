/*
https://leetcode.com/problems/min-stack/solutions/1209254/c-simple-code-with-one-stack

https://g.co/gemini/share/ccb49067483b
*/

class MinStack {
public:
    vector<pair<int, int>> s;

    MinStack() {
        //leave this empty
    }
    
    void push(int val) {
        if(s.empty()){ // if no min is presnt ( first element) then push both
            s.push_back({val, val});
        }
        else{ // otherwise find the min then push the min only element
            s.push_back({val, min(s.back(). second, val)});
        }
        
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
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