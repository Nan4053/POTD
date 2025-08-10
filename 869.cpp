// Reordered Power of 2
// https://leetcode.com/problems/reordered-power-of-2/description/
// 🟠 Medium
// why it is medium: The problem requires checking if a number can be rearranged to form a power of 2, 
// which involves understanding both number properties and string manipulation.
// Time Complexity: O(n log n) for sorting the digits of the number
class Solution {
public:
    unordered_set<string>st;
    void buildSet(){
        for(int i=0; i<=29;i++){
            int num= 1<<i;
            string s=to_string(num);
            sort(s.begin(), s.end());
            st.insert(s);
        }
    }
    bool reorderedPowerOf2(int n) {
        if(st.empty()){
            buildSet();
        }
        string s=to_string(n);
        sort(s.begin(), s.end());
        if(st.count(s)){
            return true;
        }
        return false;
    }
};