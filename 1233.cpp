// LeetCode 1233 - Remove Sub-Folders from the Filesystem
// 🟠 Medium
// This problem requires us to remove subfolders from a list of folder paths.
// why is this medium? The challenge lies in efficiently checking and removing subfolders while 
// maintaining the order of the remaining folders.
// The solution involves sorting the folder paths and uses a two-pointer technique to identify 
// and skip subfolders.
// Time Complexity: O(n log n) for sorting, O(n) for the two-pointer traversal.
// Space Complexity: O(n) for storing the result.
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());       
        int n= folder.size();
        vector<string>res;
        int i=0, j=0;
        while(i<n){
            string cur= folder[i];
            int cur_size= cur.size();
            j=i+1;
            while(j<n && folder[j].size() > cur_size && cur== folder[j].substr(0,cur_size)&& folder[j][cur_size]=='/'){
                j++;
            }
            res.push_back(folder[i]);
            i=j;
        }        
        return res;
    }
};