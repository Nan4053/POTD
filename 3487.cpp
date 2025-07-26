// Maximum Unique subarray sum after deletion
// 🟢 Easy
// why it is easy: The problem requires basic 
// understanding of arrays and simple iteration to 
// compute the maximum unique subarray sum.
int maxSum(vector<int>& nums) {
        vector<int>tmp(101, -1);
        int n= nums.size(), maxNeg=INT_MIN, sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=0){
                maxNeg= max(maxNeg, nums[i]);
            }else{
                if(tmp[nums[i]]==-1){
                    sum+= nums[i];
                    tmp[nums[i]]=0;
                }
            }
        }
        return sum==0?maxNeg: sum;
    }