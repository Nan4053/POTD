// 1353. Maximum Number of Events That Can Be Attended
// 🟠 Medium
// why it is medium? // This problem is considered medium because it requires a good understanding of greedy algorithms and priority queues.
// The challenge lies in efficiently managing overlapping events and maximizing the number of events attended without conflicts.
// why we are sorting the events? // We sort the events by their start times to facilitate the management of overlapping events.
// why we are using priority queue? // We use a priority queue to efficiently manage the end times of events, allowing us to quickly determine which events can be attended on a given day.
// why we are using greedy algorithm? // The greedy approach is used to always attend the earliest available event, maximizing the number of events attended without conflicts.

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int index=0, result=0, day=0, n = events.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        while(!pq.empty() || index<n){
            if(pq.empty()){
                day= events[index][0];
            }
            while(index<n && events[index][0]<=day){
                pq.push(events[index][1]);
                index++;

            }
            pq.pop();
            result++;
            day++;
            while(!pq.empty() && pq.top()<day){
                pq.pop();

            }

        }
        return result;
    }
};
