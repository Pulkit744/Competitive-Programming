#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }
    vector<long long> v = songs;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
     int m = (int)v.size();
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        int pos = int(lower_bound(v.begin(), v.end(), songs[i]) - v.begin());
        c[i] = pos;
    }
    vector<int> la(m, -1);
    int best = 0;
    int l = 0;  // left pointer of window
    for (int r = 0; r < n; r++) {
        int x = c[r];
        // If x was seen at prev ≥ l, drop everything up to prev.
        if (la[x] >= l) {
            l = la[x] + 1;
        }
        la[x] = r;
        best = max(best, r - l + 1);
    }

    cout << best << "\n";
}
