// 3201. Find the Maximum Length of Valid Subsequence I
// 🟠 Medium
// why is this medium? From the problem description, it seems like a simple counting problem.
// Traverse the array and count the number of even, odd numbers and alternating even-odd pairs, then return the maximum length
// of the valid subsequence based on the parity of the first element.
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n= nums.size();
        int count=0, count_even=0, count_odd=0;
        bool flag= nums[0]%2==1;
        for(int num:nums){           
            if(num%2==0){  
                if (!flag)            
                {
                    flag= !flag;
                    count++;
                } 
                count_even++;              
            }else{                
                if (flag)            
                {
                    flag= !flag;
                    count++;
                } 
                count_odd++;
            }
        }
        return max({count_odd, count_even, count});
    }
};