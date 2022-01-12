class HitCounter {
public:
    deque<int> q;
    int hits=0;
    HitCounter() {
        hits=0;
        q.clear();
    }
    
    void hit(int timestamp) {
        while(!q.empty() && q.front() <= timestamp-300){
            q.pop_front();
            hits--;
        }
        q.push_back(timestamp);
        hits++;
    }
    
    int getHits(int timestamp) {
        while(!q.empty() && q.front() <= timestamp-300){
            q.pop_front();
            hits--;
        }
        return hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */