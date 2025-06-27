#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    ll lo = 0, hi = *min_element(k.begin(), k.end()) * t;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        ll produced = 0;
        for (int i = 0; i < n; i++) {
            produced += mid / k[i];
            if (produced >= t) break;
        }
        if (produced >= t) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
}