class KthLargest {

private:
// See we  are going to solve by using the min heap and priorityQueue 
int K;
priority_queue<int,vector<int>,greater<int>> pq; 
 
public:
    KthLargest(int k, vector<int>& nums) {
        this-> K = k;

        // first go to  nums size elemnts 
        for(int i = 0; i < nums.size(); i++) {
            // seee we must push only k size elemnts only 
            if(pq.size() < K) {
                pq.push(nums[i]);
            }
            // now we must check that if nums[i]  is greater than my priortity elemnts 
    
            else if(nums[i] > pq.top()) {

                // fristly pop the elements 
                pq.pop();

                pq.push(nums[i]);
            }
        }
        
    }
    
    int add(int val) {

        // now we  must check the size of k  if size of k is lesss than my k value then only push the elemnts 
        if(pq.size() < K) {
            pq.push(val);

            // after pushing return the top of elemnts 
            return pq.top();
        }

        // now we must check the condation is that 
        if(val > pq.top()) {
            pq.pop();

            pq.push(val);
        } 

        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */