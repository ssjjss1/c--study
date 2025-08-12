#include<bits/stdc++.h>
using namespace std;

const int INF=1e7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> visited(INF+4, 0);
    vector<long long> primes;
    for(int i=2; i<=INF; i++) {
        if(!visited[i]) {
            primes.push_back(i);
            for(int j=i*2; j<=INF; j+=i) {
                visited[j]=1;
            }
        }
    }

    int sz=primes.size();
    vector<long long> sum(sz+14, 0); 
    for(int i=1; i<=sz; i++) {
        sum[i] = sum[i-1] + primes[i-1];
    }

    int tc;
    cin >> tc;
    for(int t=1; t<=tc; t++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<int>());

        for(int i=0; i + a[0] <= sz; i++) {
            int idx = i;
            bool flag = true;
            long long target = sum[i + a[0]] - sum[i]; 
            if(visited[target] || target < 2) continue;
            for(int j=1; j<n; j++) {
                while(idx + a[j] <= sz && (sum[idx + a[j]] - sum[idx]) < target) {
                    idx++;
                }
                if(idx + a[j] > sz || (sum[idx + a[j]] - sum[idx]) != target) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << "Scenario " << t << ":\n" << target << "\n\n";
                break;
            }
        }
    }
}