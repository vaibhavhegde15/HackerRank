#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <vector>


using namespace std;

vector<string> words;

void replaceWord(string &s) {
    int pos;

    while((pos = s.find("our")) != string::npos){
        s.erase(pos, 3);
        s.insert(pos, "0");
    }

    while((pos = s.find("or")) != string::npos){
        s.erase(pos, 2);
        s.insert(pos, "0");

    }
}

int countWords(string s) {
    int c = 0;

    for(int i = 0; i < words.size(); ++i)
        if(s == words[i])
            ++c;

    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    //freopen("input.txt", "r", stdin);

    int n, t;


    cin >> n;
    cin.ignore(255, '\n');

    while(n--) {
        string s, token;
        getline(cin, s);

        stringstream iss(s);
        while(getline(iss, token, ' ')) {
            replaceWord(token);
            words.push_back(token);
            //cout << token << endl;
        }
    }

    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        replaceWord(s);
        cout << countWords(s) << '\n';

    }


}
