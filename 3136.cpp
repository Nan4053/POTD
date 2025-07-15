// 3136. Valid Word
// 🟢 Easy
// Traverse the string and check for conditions
class Solution {
public:
    bool isValid(string word) {
        bool is_vowel=false, is_const=false;
        int n= word.size();
        
        if(n<3) return false;
        for(int i=0;i<n;i++){
            if(word[i]=='@'|| word[i]=='#'|| word[i]=='$') 
                return false;
            else if(word[i]=='a'||word[i]=='e'||word[i]=='i'||
                    word[i]=='o'||word[i]=='u' ||word[i]=='A'|| 
                    word[i]=='E'|| word[i]=='I'||word[i]=='O'||
                    word[i]=='U'){
                        is_vowel=true;

                }else if((word[i]>='a' && word[i]<='z')||(word[i]>='A' && word[i]<='Z')){
                    is_const=true;
                    
                }
        }
        return is_vowel && is_const;
    }
};