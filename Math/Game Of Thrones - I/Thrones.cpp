#include <iostream>
#define MAXN 'z' - 'a' + 1

using namespace std;

int a[MAXN];

bool isPossible() {
    bool failed = false;

    for(int i = 0; i < MAXN; ++i)
        if(a[i] & 1) {
            if(failed)
                return false;
            failed = true;
        }

    return true;
}

int main() {
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); ++i)
        ++a[s[i] - 'a'];

    cout << ((isPossible()) ? "YES" : "NO") << endl;
}
