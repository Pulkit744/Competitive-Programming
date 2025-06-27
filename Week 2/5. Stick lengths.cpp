#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long> a(n);
    for (int i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    long long e=a[n/2];
    long long s=0;
    for (int i=0;i<n/2;i++) 
    s = s+ (e-a[i]);
    for (int i=n/2;i<n;i++)
    s= s + a[i]-e;
    cout<<s<<'\n';
}