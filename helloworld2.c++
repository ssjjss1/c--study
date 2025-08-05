#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> a(n);
    for(auto &i:a) cin>>i;
    
    for(auto i:a) cout<<i<<" ";
}