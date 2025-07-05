//  Find Lucky Integer in an Array
// https://leetcode.com/problems/find-lucky-integer-in-an-array/description/\
// Microsoft
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq; // Frequency map to count occurrences of each number
        for (int num : arr) {
            freq[num]++; // Increment the count for each number in the array
        }
        int lucky = -1;
        // Check for lucky integers
        for (const auto& [num, count] : freq) {
            if (num == count) {
                lucky = max(lucky, num);
            }
        }
        return lucky;
    }
};
