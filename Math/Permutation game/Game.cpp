#include <bits/stdtr1c++.h>
#define MAXN 16

using namespace std;

int n, s[MAXN], disabled;

tr1::unordered_map<int, bool> w[2];

bool isIncreasing() {
    int last = -1;
    for(int i = 0; i < n; ++i){
        if(!(disabled & (1 << i))) {

            if(s[i] < last){
                return false;
            }
            last = s[i];
        }
    }

    return true;

}

bool play(int moves = 0, bool alice = true){
    if(w[alice].find(disabled) != w[alice].end())
        return w[alice][disabled];

    if(isIncreasing())
        return (alice ^ true);

    for(int i = 0; i < n; ++i){
        if(!(disabled & (1 << i))){
            disabled ^= 1 << i;
            bool won = play(moves + 1, alice ^ true);
            disabled ^= 1 << i;

            if(alice == won){
                return (w[alice][disabled] = alice);
            }
        }
    }

    return (w[alice][disabled] = (alice ^ true));
}


int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        disabled = 0;
        cin >> n;

        for(int i = 0; i < n; ++i)
            cin >> s[i];

        w[0].clear();
        w[1].clear();

        cout << ((play()) ? "Alice\n" : "Bob\n");
    }
}
