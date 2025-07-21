// 1957. delete characters to make fancy string
// 🟢 easy
class Solution {
public:
    string makeFancyString(string s) {
        char c=s[0];
        int count=1;
        string ans="";
        for(int i=1;i<s.size();i++){
            
            if(s[i]!=c){
                ans.push_back(c);
               
                c=s[i];
                count=1;
                
            }else {
                if(count<2){
                ans.push_back(c);
                }
                count++;
                
            }
        }
        ans.push_back(s[s.size()-1]);
        return ans;
    }
};