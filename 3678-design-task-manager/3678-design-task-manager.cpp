class TaskManager {
    struct Node { int priority; int taskId; };
    struct cmp {
        bool operator()(const Node& a, const Node& b) const {
            if (a.priority != b.priority) return a.priority > b.priority;
            return a.taskId > b.taskId;
        }
    };
    set<Node, cmp> s;
    unordered_map<int, pair<int,int>> mp;
    unordered_map<int, set<Node,cmp>::iterator> itmp;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            if (mp.count(taskId)) {
                s.erase(itmp[taskId]);
                mp.erase(taskId);
                itmp.erase(taskId);
            }
            Node node{priority, taskId};
            auto res = s.insert(node);
            mp[taskId] = {userId, priority};
            itmp[taskId] = res.first;
        }
    }
    void add(int userId, int taskId, int priority) {
        if (mp.count(taskId)) {
            s.erase(itmp[taskId]);
            mp.erase(taskId);
            itmp.erase(taskId);
        }
        Node node{priority, taskId};
        auto res = s.insert(node);
        mp[taskId] = {userId, priority};
        itmp[taskId] = res.first;
    }
    void edit(int taskId, int newPriority) {
        if (!mp.count(taskId)) return;
        s.erase(itmp[taskId]);
        Node node{newPriority, taskId};
        auto res = s.insert(node);
        itmp[taskId] = res.first;
        mp[taskId].second = newPriority;
    }
    void rmv(int taskId) {
        if (!mp.count(taskId)) return;
        s.erase(itmp[taskId]);
        mp.erase(taskId);
        itmp.erase(taskId);
    }
    int execTop() {
        if (s.empty()) return -1;
        auto it = s.begin();
        int taskId = it->taskId;
        int userId = mp[taskId].first;
        s.erase(it);
        mp.erase(taskId);
        itmp.erase(taskId);
        return userId;
    }
};
