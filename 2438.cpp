// 2438. Range Product Queries of Powers
// https://leetcode.com/problems/range-product-queries-of-powers/
// 🟠 Medium
// why it is medium? because it involves bit manipulation and understanding of range queries.

    
    int mod= 1000000007;
   
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> st;
        int i=0;
        while(n>0){
            if(n&1){
                st.push_back(1<<i);
            }
            n= n>>1;
            i++;
        }
        vector<int> res;
        int q= queries.size();
        long long temp=1;
        for(int i=0;i<q;i++){
            temp=1;
            for(int start= queries[i][0]; start<=queries[i][1]; start++ ){
                temp= ((temp%mod )*(st[start]%mod))%mod;
            }
            res.push_back(temp);
        }
        return res;
    }
