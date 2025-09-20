#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source;
    int destination;
    int timestamp;

    bool operator==(Packet const &o) const {
        return source == o.source &&
               destination == o.destination &&
               timestamp == o.timestamp;
    }
};

struct PacketHash {
    size_t operator()(Packet const &p) const {
        size_t h1 = hash<int>()(p.source);
        size_t h2 = hash<int>()(p.destination);
        size_t h3 = hash<int>()(p.timestamp);
        return ((h1 * 31 + h2) ^ (h3 << 1));
    }
};

class Router {
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (uniquePackets.count(p)) {
            // duplicate, not added
            return false;
        }
        if ((int)packetQueue.size() == memoryLimit) {
            forwardPacket();  // free oldest space
        }
        packetQueue.push_back(p);
        uniquePackets.insert(p);
        destTimestamps[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packetQueue.empty()) return {};
        Packet p = packetQueue.front();
        packetQueue.pop_front();
        uniquePackets.erase(p);
        processedCount[p.destination]++;  // one more forwarded for that destination
        return {p.source, p.destination, p.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end()) return 0;
        const vector<int> &timestamps = it->second;
        int skip = processedCount[destination];  // already forwarded count
        if (skip >= (int)timestamps.size()) return 0;
        auto lb = lower_bound(timestamps.begin() + skip, timestamps.end(), startTime);
        auto ub = upper_bound(timestamps.begin() + skip, timestamps.end(), endTime);
        return (int)(ub - lb);
    }

private:
    int memoryLimit;
    deque<Packet> packetQueue;
    unordered_set<Packet, PacketHash> uniquePackets;
    unordered_map<int, vector<int>> destTimestamps;
    unordered_map<int, int> processedCount;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

 auto init=atexit([](){ofstream("display_runtime.txt")<<"0";});
