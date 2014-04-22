#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#define MAXN 101

using namespace std;


int n;
vector<string> times[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i) {
        string s;
        int x;
        cin >> x >> s;
        if(i < (n/2))
           s = "-";

        times[x].push_back(s);
    }

    for(int i = 0; i <= 99; ++i)
        for(vector<string>::iterator it = times[i].begin(); it != times[i].end(); ++it)
                printf("%s ", (*it).c_str());
}
