// Maximum Number of Events That Can Be Attended II
// 🔴 HARD

// why it is hard? // This problem is considered hard because it involves dynamic programming 
// with a binary search optimization, which can be complex to implement correctly. 
// The challenge lies in efficiently managing overlapping events and maximizing the total value while adhering to constraints.

// why we are sorting the events? // We sort the events by their end times to facilitate the binary search for the last non-overlapping event,
// which allows us to efficiently compute the maximum value of attended events without overlaps.

// why we are using binary search? // We use binary search to quickly find the last event that ends before the start of the current event,
// why we are using dynamic programming? we have two choices for each event: either attend it or skip it.
// Dynamic programming helps us build a solution incrementally, storing intermediate results to avoid redundant calculations.

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int prev = binarySearch(events, events[i - 1][0]);

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[prev + 1][j - 1] + events[i - 1][2]);
            }
        }

        return dp[n][k];
    }

private:
    int binarySearch(vector<vector<int>>& events, int currentStart) {
        int left = 0, right = events.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < currentStart) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};