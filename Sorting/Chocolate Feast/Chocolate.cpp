#include <iostream>

using namespace std;

int n, c, m;

int main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--){
        int total = 0, notUsed = 0;
        cin >> n >> c >> m;
        for(int left = n/c; left; ){
            total += left;
            int nUsed =(left + notUsed) % m;

            left = (left + notUsed) / m;
            notUsed = nUsed;

        }

        cout << total << endl;
    }

}
