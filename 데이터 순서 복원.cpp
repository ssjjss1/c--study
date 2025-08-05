#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    
    vector<int> A(n), B(n), C(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    for(int i=0;i<n;i++){
        cin>>B[i];
    }

    for(int i=0;i<n;i++){
        cin>>C[i];
    }

    for(int i=0;i<n;i++){
        int sa=i+1;

        auto ib=find(B.begin(), B.end(), A[i]);
        auto ic=find(C.begin(), C.end(), A[i]);
        int sb=distance(B.begin(), ib)+1;
        int sc=distance(C.begin(), ic)+1;

        //cout<<sa<<" "<<sb<<" "<<sc<<"\n";

        pq.push({sa + sb + sc - min({sa, sb, sc}), A[i]});
    }

    while(!pq.empty()){
        cout<<pq.top().second<<" ";
        pq.pop();
    }
}