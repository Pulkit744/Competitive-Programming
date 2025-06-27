#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
        if (i % k == 0) {
            left[i] = nums[i];
        } else {
            left[i] = max(left[i - 1], nums[i]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 || (i + 1) % k == 0) {
        
            right[i] = nums[i];
        } else {
            right[i] = max(right[i + 1], nums[i]);
        }
    }
    int o = n - k + 1;
    vector<int> ans(o);
    for (int i = 0; i < o; i++) {
        ans[i] = max(right[i], left[i + k - 1]);
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}
