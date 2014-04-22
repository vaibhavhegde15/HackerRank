#include <bits/stdc++.h>
#define MAXN 'z' - 'a' + 2

using namespace std;

int h[MAXN];

priority_queue<string, vector<string>, greater<string> > answer;

void solve(string cur = "", int pos = 0){
    if(pos == MAXN - 1){
        if(!cur.empty())
        answer.push(cur);
        return;
    }

    for(int i = 0; i <= h[pos]; ++i)
        solve(cur + string(i, pos + 'a'), pos + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        string s;

        cin >> n >> s;

        fill(h, h + MAXN, 0);

        for(int i = 0; i < s.size(); ++i)
            ++h[s[i] - 'a'];

    solve();

    for(;!answer.empty(); answer.pop())
        printf("%s\n", answer.top().c_str());



    }



}
