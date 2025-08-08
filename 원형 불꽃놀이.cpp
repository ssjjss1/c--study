#include <bits/stdc++.h>
using namespace std;

vector<int> a(202020);
int l, r, x1, x2;

void run(int n) {
    l = 1, r = 2;

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());

    int x = v[0], y = v[1];

    for (int i = 1; i <= n; i++) {
        if (a[i] == x) {
            for (int j = 1; j <= n; j++) {
                if (i == j || a[j] != y) continue;
                l = i;
                r = j;
                if (l > r) swap(l, r);
                if (abs(l - r) > 1 && !(abs(l - r) == n - 1)) {
                    return;
                }
            }
        }
    }
}

void calc(int cnt) {
    for (int i = cnt; i >= 1; i--) {
        if (i == 1) {
            x1 -= 1;
            x2 -= 1;
        } else if (x1 >= x2) {
            x1 -= 1;
        } else {
            x2 -= 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    run(n);

    x1 = a[l];
    x2 = a[r];
    int m1 = r - l - 1;
    int m2 = n - (r - l + 1);

    calc(m1);
    calc(m2);

    cout << max(x1, x2);
}