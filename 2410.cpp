// Maximum Matching of Players With Trainers
// 🟠 Medium-easy
// sorting of both arrays and then using two pointers to find matches
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
     sort(players.begin(), players.end());
     sort(trainers.begin(), trainers.end());
     int i=0,j=0;
     int n= players.size(), m= trainers.size();
     int count=0;
     while(i<n && j<m){
        if(players[i]<=trainers[j]){
            count++; i++;j++;
        }
        else {
            j++;
        }
     }
     return count;

    }
};