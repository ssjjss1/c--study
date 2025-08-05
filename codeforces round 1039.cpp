#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        long long ans=1, mx=1, cnt=1;

        for(int i=1;i<n;i++){
            if(v[i-1]>v[i]) {
                cnt+=1;
            } else{
                cnt=0;
            }

            ans+=ans;
            if(cnt>mx){
                mx=cnt;
                ans+=mx;
            }
        }

        cout<<ans;
    }
}