#include <bits/stdtr1c++.h>
#define MAXN 51

using namespace std;

int piles[MAXN];
long long p[2];

void printPiles() {
    for(int i = 0; i < 10; ++i)
        cout << piles[i] << " ";
    cout << endl;
}

bool isSet(long long a, int index) {
    return (a & (1ll << index));
}

bool play(bool alice = true) {
    for(int i = 3; i < MAXN; ++i) {
        if(piles[i] > 0 && !isSet(p[alice], i)) {
            for(int j = 1; j < i / 2 + i % 2; ++j) {
                if(isSet(p[alice], j))
                    continue;

                --piles[i];
                ++piles[j];
                ++piles[i - j];
                p[alice] ^= (1ll << i) | (1ll << j);

                bool won = play(alice ^ true);
                p[alice] ^= (1ll << i) | (1ll << j);

                cout << alice << " " << won << " with " <<i << " "<< j << ": " ;
                printPiles();

                ++piles[i];
                --piles[j];
                --piles[i - j];

                if(won == alice)
                    return alice;

            }
        }
    }


    return (alice ^ true);
}

int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        p[0] = p[1] = 0ll;
        fill(piles, piles + MAXN, 0);
        int n;

        cin >> n;

        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            ++piles[x];
        }

        cout << play() << endl;

        /*
                if(!play())
                    cout << "ALICE\n";
                else
                    cout << "BOB\n";
          */
    }



}
