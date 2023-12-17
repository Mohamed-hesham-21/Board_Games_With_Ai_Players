#include <bits/stdc++.h>
#define int  long long int
#define ll long long
#define ld long double
#define each const auto &
#define fk(i,n) for(ll i=0;i<ll n;i++)
#define uwu(t) while(t--)
#define endl '\n'
#define coder ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
map<string, int> mp;
string word_maker(const string& word){
    string temp;
    for (char i : word) {
        if(isalpha(i)||i == '-' || isdigit(i)){
            temp.push_back(i);
        }
        else {
            mp[temp]++;
            temp.clear();
        }
    }
    return temp;

}

signed main() {

    string filename, word;
    cin >> filename;
    ifstream in(filename);
    while (in.good()) {
        in >> word;
        word =word_maker(word);
        mp[word]++;
    }
    for (const auto& it :mp) {
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}