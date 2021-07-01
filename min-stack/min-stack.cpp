class MinStack {
    private:    
        vector<pair<int,int>> nums;
    public:
    MinStack() {

    }

    int min(int a, int b){
        return a > b ? b : a;
    }
    void push(int val) {
        nums.emplace_back(val, min(val, nums.empty() ? val : nums.back().second));
    }

    int top() {
        return nums.back().first;
    }

    int getMin() {
        return nums.back().second;
    }

    int pop() {
        int last = nums.back().first;
        nums.pop_back();
        return last;
    }
};