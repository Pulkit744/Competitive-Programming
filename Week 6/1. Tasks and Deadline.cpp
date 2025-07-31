#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<pair<long long ,long long>>v;
    for (long long i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    long long s=0;
    long long no=0;
    for (const auto& p : v) {
        no=no+p.first;
        s=s+(p.second-no);
    }
    cout<<s<<'\n';
}