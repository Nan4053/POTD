// 1865. Finding Pairs With a Certain Sum
// 🟠Medium

// So the question is why it is marked as medium?
// The problem is to find pairs of indices (i, j) such that nums1[i] + nums2[j] equals a given total.
// The initial implementation iterates through both arrays for each count query, leading to a time complexity of O(n^2) for each count query, which is inefficient for large arrays.
// The task is to optimize this by using a frequency map for `num2` to count pairs in O(n) time for each `count` query, thus improving the overall efficiency of the solution.

// Gives TLE because for each query we are iterating through both arrays.
// Time complexity: O(n^2) for each count query, where n is the size of the arrays.
// Space complexity: O(n) for storing the arrays.
class FindSumPairs {
    vector<int> num1, num2;
public:
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1= nums1;
        num2= nums2;
    }
    
    void add(int index, int val) {
        num2[index]+= val;
    }
    
    int count(int tot) {
        int res=0;
        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                if(num1[i]+num2[j]== tot) res++;
            }
        }
        return res;
    }
};

/*****************************************************************************/
// Given the TLE issue with the above implementation, we can optimize it using a frequency map for `num2`.
// This will allow us to count pairs in O(n) time for each `count` query
// Time complexity: O(n) for each count query, where n is the size of the arrays.
// Space complexity: O(n) for storing the frequency map of `num2`.
class FindSumPairs {
    vector<int> num1, num2;
    unordered_map<int, int> freq;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
        : num1(nums1), num2(nums2) {

        for (auto num : num2) { 
            freq[num]++; //store frequency of each number in num2
        }
    }
// Add a value to the element at index in num2
    void add(int index, int val) {
        freq[num2[index]]--; // Decrease the frequency of the old value
        num2[index] += val; // Update the value in num2
        freq[num2[index]]++; // Increase the frequency of the new value

    }

    int count(int tot) {
        int result = 0;
        for (int a : num1) {
            int b = tot - a;
            result += freq[b]; // Count how many times b appears in num2 (num1[i] + num2[j] == tot)
        }
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */