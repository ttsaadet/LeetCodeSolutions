#include "common.h"

class MinStack {

    
    stack<int> valStack;
    stack<int> minStack;
    int min = 0x7fffffff;
public:
    MinStack() {
        /*speed up io*/
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
    }
    
    void push(int val) {
        if(val < min) min = val;
        valStack.push(val);
        minStack.push(min);
    
    }
    
    void pop() {
        if(!valStack.empty())
            valStack.pop();
        if(!minStack.empty())
        {
            minStack.pop();
        }
        if(!minStack.empty()){
            min = minStack.top();
        }
        else{
            min = 0x7fffffff;
        }
    
    }
    
    int top() {
         if(!valStack.empty())
            return valStack.top();
        else{
            return -1;
        }
    }
    
    int getMin() {
        return min; 
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

int main(){
    MinStack s;
    s.push(2147483646);
    s.push(2147483646);
    s.push(2147483647);
    cout << s.top() << endl;
    s.pop(); 
    
    cout << s.getMin() << endl;
    s.pop(); 
    
    cout << s.getMin() << endl;
    s.pop(); 
    s.push(2147483647);
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    s.push(-2147483648);

        cout << s.top() << endl;
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    
}