class MinStack {
public:
    stack<long long> st;
    long long min;

    MinStack() {
        min = LLONG_MAX;
    }

    void push(long long x) {
         if(st.empty()){
            min=x;
            st.push(x);
        }
        else{
            if(x>min)st.push(x);
            else{
                st.push(2*x-min);
                min=x;
            }
        }
    }
    
    void pop() {
        if(st.empty())return ;
        else{
            long long x=st.top();
            st.pop();
            if(x<min)min=2*min-x;
        }
    }
    
    int top() {
        if(st.empty())return 0;
        else{
           long long x=st.top();
            if(min<x)return x;
            else return min;
        }
    }
    
    int getMin() {
         return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */