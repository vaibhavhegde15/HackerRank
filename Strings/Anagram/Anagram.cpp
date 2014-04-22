#include <iostream>
#include <string>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int countDiff(string a, string b) {

    if(a.size() != b.size())
        return -1;

    int needs[512], d = 0;
    fill(needs, needs + 512, 0);

    for(int i = 0; i < a.size(); ++i)
        --needs[a[i]];

    for(int i = 0; i < b.size(); ++i)
        ++needs[b[i]];

    for(int i = 0; i < 512; ++i)
        if(needs[i] > 0)
            d += needs[i];

    return d;
}

int main() {
    int t;
    string s;

    cin >> t;

    while(t--) {
        cin >> s;

        string s1 = s.substr(0, s.size() / 2);
        string s2 = s.substr(s.size() / 2);

        printf("%d\n", countDiff(s1, s2));

    }
}
