#include<bits/stdc++.h>
using namespace std;

int luck(int x){
    int mn=9,mx=0;
    while(x){
        int d=x%10;
        mn=min(mn,d);
        mx=max(mx,d);
        x=x/10;
        if (mx-mn==9) break;
    }
    return mx-mn;
}

int main(){
    long long t;
    long long l,r;
    cin>>t;
    for(long long i=0;i<t;i++){
        long long m=-10,x=0;
        cin>>l>>r;
        for (long long j=l;j<r+1&& j<l+101;j++){
            int lucky=luck(j);
            if (lucky>m){
            m=lucky;
            x=j;
        }
    }
    cout<<x<<"\n";
}
}