#include<bits/stdc++.h>
#define INF (1e6+4)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a2(INF, 0), a5(INF, 0);
    for(int i=2;i<=INF;i++){
        a2[i]=a2[i-1];
        a5[i]=a5[i-1];
        if(i%2==0) {
            int temp=i;
            while(temp%2==0) {
                a2[i]++;
                temp/=2;
            }
        }
        if(i%5==0) {
            int temp=i;
            while(temp%5==0) {
                a5[i]++;
                temp/=5;
            }
        }
    }

    int tc=1;
    while(true){
        int n;
        cin>>n;

        if(n==0) break;

        cout<<"Case #"<<tc++<<": "<<min(a2[n], a5[n])<<"\n";
    }
}