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

        vector<long long> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        long long diff=a[2]-a[1];
        bool flag=true;
        for(int i=2;i<n;i++){
            if(diff!=a[i+1]-a[i]) flag=false;
        }

        if(!flag){
            cout<<"NO\n";
            continue;
        }

        long long ans=a[1]+diff*(diff<0?n:-1);
        cout<<(ans%(n+1)==0&&ans>=0?"YES\n":"NO\n");
    }
}