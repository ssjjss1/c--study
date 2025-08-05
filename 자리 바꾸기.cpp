#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    if(n%2&&m%2) {
        cout<<"No";
        return 0;
    }

    int d[n][m]={0,};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
        }
    }

    for(int i=0;i<n-1;i+=2){
        for(int j=0;j<m-1;j+=2){
            swap(d[i][j], d[i][j+1]);
            swap(d[i+1][j], d[i+1][j+1]);
        }
        if(m%2){
            swap(d[i][m-1], d[i+1][m-1]);
        }
    }

    if(n%2){
        for(int j=0;j<m-1;j+=2){
            swap(d[n-1][j], d[n-1][j+1]);
        }
    }

    cout<<"Yes\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
}