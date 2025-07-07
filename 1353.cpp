// 1353. Maximum Number of Events That Can Be Attended
// 🟠 Medium

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
