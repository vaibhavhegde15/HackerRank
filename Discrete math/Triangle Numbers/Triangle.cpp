#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        if(n < 2)
            cout << -1 << "\n";
        else{
            switch(n % 4ll){
            case 0ll:
                cout << "3\n";
                break;
            case 2ll:
                cout << "4\n";
                break;
            default:
                cout << "2\n";
            }
        }
    }
}
