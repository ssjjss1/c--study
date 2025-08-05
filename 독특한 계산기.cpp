#include <bits/stdc++.h>
using namespace std;

long long calc(long long a, char op, long long b) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') return a / b;
	return 0;
}

int getPriority(char op) {
	if (op == '*' || op == '/') return 2;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	deque<long long> num;
	deque<char> op;

	long long idx = 0, n = s.size();
	long long temp = 1;

	if (s[0] == '-') {
		temp = -1;
		idx = 1;
	}

	while (idx < n) {
		int len = 0;
		while (idx + len < n && isdigit(s[idx + len])) len+=1;
		long long val = stoll(s.substr(idx, len)) * temp;
		num.push_back(val);
		idx += len;

		temp = 1;
		if (idx < n) {
			char c = s[idx++];
			op.push_back(c);
		}
	}

    while(!op.empty()){
        long long x1=num[0], x2=num[1], x3=num[num.size()-2], x4=num[num.size()-1];
        char op1=op[0], op2=op[op.size()-1];

        int pri1=getPriority(op1);
        int pri2=getPriority(op2);
        long long res1=calc(x1, op1, x2);
        long long res2=calc(x3, op2, x4);
        if(pri1==pri2){
            if(res1>=res2){
                op.pop_front();
                num.pop_front();
                num.pop_front();
                num.push_front(res1);
            } else{
                op.pop_back();
                num.pop_back();
                num.pop_back();
                num.push_back(res2);
            }
        } else if(pri1>pri2){
            op.pop_front();
            num.pop_front();
            num.pop_front();
            num.push_front(res1);
        } else {
            op.pop_back();
            num.pop_back();
            num.pop_back();
            num.push_back(res2);
        }
    }

    cout<<num[0];
}