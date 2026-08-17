class KthLargest {
private:
    int kn;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->kn=k;
        for(int num: nums){
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>kn){
            minHeap.pop();
        }
        return minHeap.top();
        
    }
};
