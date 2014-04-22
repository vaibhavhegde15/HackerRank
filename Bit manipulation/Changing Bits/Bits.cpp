#include <iostream>
#include <bitset>
#include <cstdio>
#include <vector>
#define MAXN 100002


using namespace std;

typedef bitset<MAXN> bs;

int n;

vector<bool> a, b, c;



void updateSum(int from, bool all = false) {
    int ones = 0;
    for(int i = from; i <= n; ++i) {
        int sum = a[i] + b[i] + (ones != 0);

        //cout << "Iteration " << i << ": " << ones << endl;
        c[i] = a[i] ^ b[i] ^ (ones != 0);


        ones = sum / 2;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    string a1, b1;

    cin >> n >> q >> a1 >> b1;
    a.resize(MAXN, false);
    b.resize(MAXN, false);
    c.resize(MAXN, false);

    for(int i = 0; i < a1.size(); ++i)
        a[i] = (a1[i] == '1');

    for(int i = 0; i < b1.size(); ++i)
        b[i] = (b1[i] == '1');

    updateSum(0, true);

    while(q--) {
//        cout << "Before operation: " << c.to_string() << endl;

        string op;
        cin >> op;


        if(op == "set_a") {
            int pos, value;
            cin >> pos >> value;
            a[pos] = value;

            updateSum(pos);
        } else if(op == "set_b") {
            int pos, value;
            cin >> pos >> value;
            b[pos] = value;

            updateSum(pos);
        }else{
            int pos;
            cin >> pos;
            printf("%d", ((c[pos]) ? 1 : 0));
        }

   //     cout << "After operation: " << c.to_string() << endl;
    }







}
