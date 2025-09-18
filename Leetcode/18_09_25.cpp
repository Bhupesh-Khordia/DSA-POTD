class TaskManager {
    // taskId -> {userId, priority}
    unordered_map<int, pair<int,int>> taskInfo;
    
    // max-heap: (priority, taskId, userId)
    priority_queue<tuple<int,int,int>> pq;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskInfo[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskInfo[taskId];
        taskInfo[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId}); // push new version
    }
    
    void rmv(int taskId) {
        taskInfo.erase(taskId); // lazy removal
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            pq.pop();
            if (taskInfo.count(taskId) && taskInfo[taskId].second == priority) {
                taskInfo.erase(taskId); // remove after executing
                return userId;
            }
        }
        return -1; // no tasks
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
