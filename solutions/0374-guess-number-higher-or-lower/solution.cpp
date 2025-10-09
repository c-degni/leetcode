/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if (n == 1) return 1;
        int rn;
        bool f = false;
        gr(1, n, f, rn);
        return rn;
    }
private:
    void gr(int s, int n, bool &f, int &rn) {
        if (f) return;
        int m = (n - s) / 2 + s;
        int a = guess(m);
        if (a == 0) {
            f = true;
            rn = m;
            return;
        } else if (a == 1) {
            if (n - s == 1) {
                f = true;
                rn = n;
                return;
            }  
            gr(m, n, f, rn);
        } else {
            if (n - s == 1) {
                f = true;
                rn = s;
                return;
            }  
            gr(s, m, f, rn);
        }
    } 
};
