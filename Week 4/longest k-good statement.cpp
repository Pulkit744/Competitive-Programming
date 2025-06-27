#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> cnt(1'000'001, 0);
    int distinct = 0;
    int best_len = 0, best_l = 0, best_r = 0;
    int l = 0;
    for(int r = 0; r < n; r++){
        if(cnt[a[r]]++ == 0){
            distinct++;
        }
        while(distinct > k){
            if(--cnt[a[l]] == 0){
                distinct--;
            }
            l++;
        }
        int cur_len = r - l + 1;
        if(cur_len > best_len){
            best_len = cur_len;
            best_l = l;
            best_r = r;
        }
    }
    cout << (best_l + 1) << " " << (best_r + 1) << "\n";
    return 0;
}
