#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define MOD 1000000007ll

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > q;

int main(){
    int t;

    cin >> t;

    while(t--){
        for(;!q.empty();q.pop());

        int n, total = 0;
        long long c, answer = 1ll;

        cin >> n;

        for(int i = 0; i < n; ++i){
            cin >> c;
            q.push(c);
        }

        for(int i = 0; i < n; ++i){
            for(;!q.empty() && q.top() == i; q.pop())
                ++total;
            answer = (answer * total) % MOD;

            --total;
        }

        answer *= q.empty();

        cout << answer << '\n';
    }
}
