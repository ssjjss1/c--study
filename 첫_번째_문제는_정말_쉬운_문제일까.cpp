#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int mxCnt=0, mnCnt=0;

    int x;
    cin>>x;
    for(int i=1;i<n;i++){
        int y;
        cin>>y;
        if(x>y) mxCnt+=1;
        if(x<y) mnCnt+=1;
    }

    if(mxCnt==0) cout<<"ez";
    else if(mnCnt==0) cout<<"hard";
    else cout<<"?";
}