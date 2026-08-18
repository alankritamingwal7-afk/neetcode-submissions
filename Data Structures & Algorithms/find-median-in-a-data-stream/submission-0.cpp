class MedianFinder {
private:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //first will insert in maxheaop
        maxh.push(num);

        //maintain the balance such
        // that all element in maxheap 
        // is less than the minheap maxh<=minh
        if(maxh.size()>0 && minh.size()>0 && maxh.top()>minh.top()){
            // agar max heap ka top bda hota h min heap se 
            //to max heap k element min heap me dadlo 
            int val = maxh.top();
            maxh.pop();
            minh.push(val);
        }

        // second chiz is we have to maintain the size of both
        // maxh.size()-minh.size() <=1
        //incode dubara uski oppsite condition check krni hai 
        if(maxh.size()>minh.size()+1){
            int val = maxh.top();
            maxh.pop();
            minh.push(val);
        }
        if(minh.size()>maxh.size()+1){
            int val = minh.top();
            minh.pop();
            maxh.push(val);
        }
        
    }
    
    double findMedian() {

        // now again in size 
        // agar size equal na ho to bigger size heap ka top is and
        // agar same hai to dono heap k top average 
        int maxi = maxh.size();
        int mini = minh.size();
        if(maxi>mini){
            return maxh.top();
        }
        else if(mini>maxi){
            return minh.top();
        }
        else {
            double med = (maxh.top()+minh.top())/2.0;
            return med;
        }
        
    }
};
