class Solution {
public:
    bool ispos(vector<int> &stalls, int k, int maxpos) {
        int c = 1;
        int lastposi = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if ((stalls[i] - lastposi) >= maxpos) {
                c++;
                lastposi = stalls[i];
            }
            if (c == k) {
                return true;
        } }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int l = 1;
        int r = stalls[stalls.size() - 1] - stalls[0];
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (ispos(stalls, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }}
        return ans;
    }};
