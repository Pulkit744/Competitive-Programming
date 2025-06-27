#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> cols(m, vector<long long>());
        for (int i = 0; i < m; i++)
            cols[i].reserve(n);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                long long x;
                cin >> x;
                cols[j].push_back(x);
            }
        }

        long long answer = 0;
        for (int j = 0; j < m; j++){
            auto &v = cols[j];
            sort(v.begin(), v.end());
            long long prefix = 0;
            for (int i = 0; i < n; i++){
                answer += v[i] * i - prefix;
                prefix += v[i];
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
