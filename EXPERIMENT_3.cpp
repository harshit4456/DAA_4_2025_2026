#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    char ch; 
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        if (ch == 'P'){
            sum += 1;}
        else{
          sum -= 1;}
        if (mp.find(sum) != mp.end()) {
            int len = i - mp[sum];
            if (len > ans){
                ans = len;}
        } else {
            mp[sum] = i;
        } }
    cout << ans;
    return 0;
}
