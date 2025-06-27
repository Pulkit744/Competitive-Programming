#include<iostream>
using namespace std;

int main(){
    int t;
    long long k,n;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n>>k;
        if (n%2==0) cout<<"YES";
        else if (k%2==0) cout<<"NO";
        else if (n>=k) cout<<"YES";
        else cout<<"NO";
        cout<<"\n";
    }
    
}