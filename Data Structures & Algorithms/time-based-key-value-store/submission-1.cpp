class TimeMap {
public:
    map<pair<int,string>,string> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[{timestamp,key}] = value;
    }
    
    string get(string key, int timestamp) {
        string ans = "";

        for (auto &it : mp) {
            int t = it.first.first;
            string k = it.first.second;

            if (k == key && t <= timestamp) {
                ans = it.second;
            }
        }

        return ans;
    }
};
