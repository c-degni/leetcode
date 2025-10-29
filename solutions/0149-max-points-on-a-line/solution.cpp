#define INF std::numeric_limits<double>::infinity()

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return 1;
        int m = 0;

        for (int i = 0; i < n; i++) {
            map<double, int> slopes;
            Point p1 = Point(points[i][0], points[i][1]);

            for (int j = i + 1; j < n; j++) {
                Point p2 = Point(points[j][0], points[j][1]);
                double s;
                if (p2.x == p1.x) s = INF;
                else s = double(p2.y - p1.y) / double(p2.x - p1.x);

                if (slopes.count(s)) slopes[s]++;
                else slopes[s] = 2;
                m = std::max(m, slopes[s]);
            }
        }
        return m;
    }
private:
    class Point {
    public:
        int x;
        int y;
        Point(int i, int j) {
            x = i;
            y = j;
        }
    };
};
