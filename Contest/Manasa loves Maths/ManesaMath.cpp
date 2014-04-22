#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <iomanip>


using namespace std;

vector<string> numbers, numbers0;

string toString(int num, bool zeroesFill = false) {
    stringstream ss;

    if(!zeroesFill)
        ss << num;
    else
        ss << setfill('0') << setw(3) << num;


    return ss.str();
}


void precompute() {
    for(int i = 0; i < 1000; i+=8) {
        string s = toString(i);
        sort(s.begin(), s.end());

        numbers.push_back(s);


        numbers0.push_back(toString(i, true));
    }

    sort(numbers.begin(), numbers.end());
}

bool isDivisable(string a) {
   // cout << "IsDivisible: " << a << endl;

    if(a.size() < 4){
       // cout << "Searching with binary " <<
        sort(a.begin(), a.end());
        return binary_search(numbers.begin(), numbers.end(), a);
    }

    bool used[a.size()];

    for(int i = 0; i < numbers0.size(); ++i) {

        fill(used, used + a.size(), false);
        int c = 0;

        for(int j = 0; j < numbers0[i].size(); ++j) {
            for(int u = 0; u < a.size(); ++u) {
                if(!used[u] && a[u] == numbers0[i][j]) {
                    used[u] = true;
                    ++c;
                    break;
                }
            }
        }

        if(c == numbers0[i].size()){
            cout << "Yes with number " << numbers0[i] << endl;
            return true;
        }
    }

    return false;
}


int main() {
    precompute();

    //for(int i = 0; i < numbers0.size(); ++i)
   //     cout << numbers0[i] << endl;

  //  return 0;

    int t;

    cin >> t;

    while(t--) {
        string a;
        cin >> a;

        if(isDivisable(a))
            printf("YES\n");
        else
            printf("NO\n");

    }
}
