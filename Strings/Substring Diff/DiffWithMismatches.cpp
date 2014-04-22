#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>
#define MAXS 1502

using namespace std;

int k;
string s1, s2;
int table[MAXS][MAXS], maximum = 0;

void lcs(){
    maximum = 0;
    fill(&table[0][0], &table[MAXS-1][MAXS-1], 0);

    for(int i = 1; i <= s1.size(); ++i)
        for(int j = 1; j <= s2.size(); ++j){
            if(s1[i-1] != s2[j-1])
                table[i][j] = table[i-1][j-1] + 1;
            else
                table[i][j] = min(table[i-1][j], table[i][j-1]);

            if(table[i][j] > k)
                maximum = max(maximum, abs((int) (i-j)));
        }

    for(size_t i = 0; i <= s1.size(); ++i){
        for(size_t j = 0; j <= s2.size(); ++j)
            cout << table[i][j] << " ";
        cout << endl;
    }
    cout << maximum << endl;

}

int main(){
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while(t--){
        cin >> k >> s1 >> s2;
        lcs();
    }
}
