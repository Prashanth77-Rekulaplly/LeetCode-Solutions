//implementing the Min Heap + Priority Queue approach for K-th Largest Element.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // See we will use min heap and priority Queue

        // Firstly initialize the priority Queue
        priority_queue<int, vector<int>, greater<int>> pq;

        // Now traverse the first k elements and push them into priority Queue
        for(int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        // Now go to the remaining elements
        for(int i = k; i < nums.size(); i++) {

            // There is a condition
            if(nums[i] > pq.top()) {

                pq.pop();

                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};
