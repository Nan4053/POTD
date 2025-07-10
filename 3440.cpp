// 3440. Reschedule Meetings for Maximum Free Time II
// 🟠 Medium
// why it is medium? // This problem is considered medium because it requires understanding of how to 
// efficiently calculate free time between events and handle multiple gaps.
// why we are precomputing maxLeftFree and maxRightFree? // We precompute maxLeftFree and maxRightFree to 
// quickly access the maximum free time available on either side of a given event, allowing us to efficiently 
// determine if an event can be rescheduled without exceeding the maximum free time.


class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray; //store durations of free gaps

        //ith event
        //ith start - i-1th ka end = free gap duration
        freeArray.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            freeArray.push_back(startTime[i] - endTime[i-1]);
        }

        freeArray.push_back(eventTime - endTime[endTime.size()-1]);

        int n = freeArray.size();
        vector<int> maxRightFree(n, 0);
        vector<int> maxLeftFree(n, 0);
        for(int i = n-2; i >= 0; i--) {
            maxRightFree[i] = max(maxRightFree[i+1], freeArray[i+1]);
        }

        for(int i = 1; i < n; i++) {
            maxLeftFree[i] = max(maxLeftFree[i-1], freeArray[i-1]);
        }


        int result = 0;
        for(int i = 1; i < n; i++) {
            int currEventTime = endTime[i-1] - startTime[i-1]; 

            if(currEventTime <= max(maxLeftFree[i-1], maxRightFree[i])) {
                result = max(result, freeArray[i-1] + currEventTime + freeArray[i]);
            }

            result = max(result, freeArray[i-1] + freeArray[i]);
        }

        return result;
    }
};