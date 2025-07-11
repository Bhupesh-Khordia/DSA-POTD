// https://leetcode.com/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2025-07-11

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> rooms;
        for(int i = 0; i < n; i++) {
            rooms.push(i);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> endTimes;

        sort(meetings.begin(), meetings.end());

        vector<int> cnt (n, 0);

        for(int i = 0; i < meetings.size(); i++) {
            long long st = meetings[i][0];
            long long et = meetings[i][1];
            long long duration = et - st;

            while(!endTimes.empty() && endTimes.top().first <= st) {
                rooms.push(endTimes.top().second);
                endTimes.pop();
            }

            if(rooms.empty()) {
                int room = endTimes.top().second;
                long long freeTime = endTimes.top().first;
                endTimes.pop();

                endTimes.push({freeTime + duration, room});
                cnt[room]++;
            } else {
                int room = rooms.top();
                rooms.pop();

                endTimes.push({et, room});
                cnt[room]++;
            }
        }

        int maxi = INT_MIN, ans = -1;
        for(int i = 0; i < n; i++) {
            if(cnt[i] > maxi) {
                maxi = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};
