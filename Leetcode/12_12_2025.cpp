class Solution {
public:
    vector<int> countMentions(const int numberOfUsers, const vector<vector<string>>& events) {
        enum {TYPE, TIME, DATA};
        constexpr int period = 60;

        vector<vector<int>> offline(numberOfUsers);

        for(const auto& event : events) {
            if(event[TYPE].front() == 'M') continue;
            int id = stoi(event[DATA]);
            int time = stoi(event[TIME]);
            offline[id].push_back(time + period);
        }

        for(auto& times : offline)
            sort(begin(times), end(times));

        int count_all = 0;
        vector<int> mentioned(numberOfUsers);

        for(const auto& event : events) {
            if(event[TYPE].front() == 'O') continue;

            if(event[DATA].front() == 'A') {
                ++count_all;
                continue;
            }

            if(event[DATA].front() == 'i') {
                string user;
                istringstream is {event[DATA]};
                while(is >> user) {
                    int id = stoi(user.substr(2));
                    ++mentioned[id];
                }
                continue;
            }

            int time = stoi(event[TIME]);
            for(int id = 0; id < numberOfUsers; ++id) {
                size_t pos = distance(begin(offline[id]), upper_bound(begin(offline[id]), end(offline[id]), time));
                if(pos == size(offline[id]) or offline[id][pos] - period > time)
                    ++mentioned[id];
            } 
        }
        
        for_each(begin(mentioned), end(mentioned), [&count_all](int& user) {user += count_all;});

        return mentioned;
    }
};
