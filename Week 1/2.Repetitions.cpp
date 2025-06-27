#include<bits/stdc++.h>
using namespace std;

int main(){
    string d;
    cin>>d;
    int len=1;
    int maxl=0;
    for(int i=0;i<d.size();i++)
    if (d[i]==d[i+1])
    len++;
    else{ 
    maxl= max(maxl,len);
    len=1;
    }
    cout<<maxl<<"\n";
}
