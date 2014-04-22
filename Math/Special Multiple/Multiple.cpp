#include <iostream>
#include <vector>
#include <algorithm>
#define MAXD 19

using namespace std;

vector<unsigned long long> numbers;

void generateNumbers(unsigned long long number = 9ull, int digits = 1) {
    numbers.push_back(number);
    if(digits == MAXD)
        return;

    generateNumbers(number * 10ull, digits + 1);
    generateNumbers(number * 10ull + 9ull, digits + 1);
}

unsigned long long getMinimumMultiply(unsigned long long number){
    for(unsigned long long n: numbers)
        if(n % number == 0ull)
            return n;

    return 0ull;
}

int main() {
    generateNumbers();
    sort(numbers.begin(), numbers.end());


    int t;

    cin >> t;

    while(t--){
        unsigned long long a;
        cin >> a;

        cout << getMinimumMultiply(a) << '\n';
    }




}
