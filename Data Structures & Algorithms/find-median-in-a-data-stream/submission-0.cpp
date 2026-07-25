class MedianFinder {
private:
    priority_queue<int> maxHeap;  // stores the smaller half (max-heap)
    priority_queue<int, vector<int>, greater<int>> minHeap;  // stores the larger half (min-heap)
    
public:
    MedianFinder() {
        // No initialization needed
    }
    
    void addNum(int num) {
        // Step 1: Add to maxHeap first
        maxHeap.push(num);
        
        // Step 2: Move the largest from maxHeap to minHeap to maintain order
        // This ensures all elements in maxHeap <= all elements in minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Step 3: Balance the heaps
        // If minHeap has more elements, move one back to maxHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // If total count is odd, median is the top of maxHeap
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        // If total count is even, median is average of both tops
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};