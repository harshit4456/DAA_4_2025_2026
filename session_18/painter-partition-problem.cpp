class Solution {
public:
    bool ispos(vector<int>& arr, int k, int maxTime) {
        int painters = 1;
        int time = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (time + arr[i] <= maxTime) {
                time += arr[i];
            }
            else {
                painters++;
                time = arr[i];
            }
        }
        return painters <= k;
    }
    int minTime(vector<int>& arr, int k) {
        int sum = 0;
        int maxVal = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            maxVal = max(maxVal, arr[i]);
        }
        int l = maxVal;
        int r = sum;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ispos(arr, k, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};