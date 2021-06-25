class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int val) {
        if (q1.empty()){
            q1.push(val); 
        }else if (val <= q1.top()){
            q1.push(val);
        }else {
            q2.push(val); 
        }

        if (int(q2.size()) - int(q1.size()) > 0){
            int top = q2.top(); q2.pop();
            q1.push(top);
        }
        if (int(q1.size()) - int(q2.size()) > 1){
            int top = q1.top(); q1.pop();
            q2.push(top);
        }
    }
    
    double findMedian() {
        int len = q1.size() + q2.size();
        if (len % 2 == 0){
            return double(q1.top() + q2.top()) / 2;
        }
        return q1.top();
    }
    private:
    priority_queue <int> q1; 
    priority_queue <int, vector <int>, greater<int> > q2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */