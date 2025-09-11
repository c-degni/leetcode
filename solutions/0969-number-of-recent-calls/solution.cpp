class RecentCounter {
private:
    std::queue<int> reqs;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        reqs.push(t);
        if (reqs.size() == 1) return 1;
        while (reqs.front() < t - 3000) reqs.pop();
        return reqs.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
