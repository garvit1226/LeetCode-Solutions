class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int> , greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);

        while(!right.empty() && left.top()>right.top()){
            int x = left.top();
            left.pop();
            int y = right.top();
            right.pop();

            left.push(y);
            right.push(x);
        }

        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            return (left.top()+ right.top())/2.0;
        }
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */