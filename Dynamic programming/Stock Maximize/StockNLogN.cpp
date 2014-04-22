#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#define MAXN 50004

using namespace std;


int n;
long long p[MAXN], profit = 0ll;

multiset<long long> numbers;
priority_queue<long long> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin >> t;

    while(t--) {
        cin >> n;

        profit = 0ll;
        for(int i = 0; i < n; ++i) {
            cin >> p[i];
            numbers.insert(p[i]);
        }

        for(int i = 0; i < n; ++i){
            if(p[i] == *numbers.rbegin())
                for(;!a.empty(); a.pop())
                    profit += p[i] - a.top();

            numbers.erase(numbers.find(p[i]));

            if(!numbers.empty() && p[i] < *numbers.rbegin())
                a.push(p[i]);
            }


            cout << profit << '\n';
    }

}
