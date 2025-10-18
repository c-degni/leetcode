class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1) return true;

        // Populate map
        for (std::vector<int> &p : prerequisites) {
            int parent = p[1];
            int child = p[0];
            if (childMapstoParent(child, parent)) return false;
            map[parent].push_back(child);
            if (!map.contains(child)) map[child].push_back({});
        }
        return true;
    }
private:
    std::map<int, std::vector<int>> map;

    bool childMapstoParent(int child, int parent) {
        if (child == parent) return true;
        // if (!map.contains(child)) return false;

        for (int &c : map[child]) {
            if (childMapstoParent(c, parent)) {
                return true;
            }
        }

        return false;
    }
};
