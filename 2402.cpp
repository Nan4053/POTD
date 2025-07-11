// 402. Meeting Rooms III
// 🔴 Hard
// TC(n log n + n^2) INTEGR OVERFLOW
// why it is hard? // This problem is considered hard because it requires efficient scheduling of meetings 
// while managing room availability and ensuring that the maximum number of meetings are booked in each room.
// why we are using priority queues? // We use priority queues to efficiently manage the availability of rooms
// and to quickly find the next available room for a meeting, ensuring optimal scheduling.

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int>count(n,0);
       vector<int> busy(n,0);
       for(auto i: meetings){
        int start= i[0], end= i[1];
        int earliest= INT_MAX;
        int roomIndex=-1;
        bool assigned= false;

        for(int i=0;i<n;i++){
            if(busy[i]<earliest){
                earliest= busy[i];
                roomIndex= i;
            }
            if(busy[i]<= start){
                busy[i]= end;
                count[i]++;
                assigned= true;
                break;
            }
        }
        if(!assigned){
            busy[roomIndex]+=(end-start);
            count[roomIndex]++;
        }
       }
       int res = 0, maxCount = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                res = i;
            }
        }
        return res;
    }
};

/***************************************************************************************************************/
// TC(nlogn + mlogn)
int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<>> freeRooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>> busy;
        for (int i = 0; i < n; ++i)
            freeRooms.push(i);
        for (auto i : meetings) {
            long long start = i[0], end = i[1];

            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }
            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                busy.emplace(end, room);
                count[room]++;
            } else {
                auto [availTime, room] = busy.top();
                busy.pop();
                busy.emplace(availTime + (end - start), room);
                count[room]++;
            }
        }
        return max_element(count.begin(), count.end()) - count.begin();
    }