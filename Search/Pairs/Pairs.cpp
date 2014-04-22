#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int pairs(vector <int> a,int k) {
    sort(a.begin(), a.end());

    int from = 0, ans = 0;

    for(int i = 0; i < a.size(); ++i) {
        int pos = lower_bound(a.begin() + from, a.end(), a[i] + k) - a.begin();

        if(pos < a.size() && a[pos] == a[i] + k) {
            ++ans;
            from = pos + 1;
        }
    }

    return ans;
}

/* Tail starts here */
int main() {
    int res;

    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = pairs(_a,_k);
    cout << res;

    return 0;
}
