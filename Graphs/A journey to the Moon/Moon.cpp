#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 100001

using namespace std;

int n, countries[MAXN];
vector<int> a[MAXN];
vector<int> groups;

queue<int> q;

int bfs(int from, int nr){
    q.push(from);
    int total = 0;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        ++total;

        countries[t] = nr;

        for(int i = 0; i < a[t].size(); ++i)
            if(countries[a[t][i]] == -1){
                countries[a[t][i]] = nr;
                q.push(a[t][i]);
            }
    }

    return total;
}

int main() {
    int l;
    fill(countries, countries  +MAXN, -1);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;

    for(int i = 0; i < l; ++i) {
        int from, to;
        cin >> from >> to;

        a[from].push_back(to);
        a[to].push_back(from);
    }

    int g = 0;

    long long answer = 0ll, total = 0ll;

    for(int i = 0; i < n; ++i){
        if(countries[i] == -1){
            long long c = bfs(i, g++);

            answer += total * c;
            total += c;

           // cout << "From counting " << c << " " << total << " " << answer << endl;
        }
    }

   // for(int i = 0; i < n; ++i)
   //     printf("I = %d: %d\n", i, countries[i]);

    cout << answer << endl;

}
