// File name: Label_genrator.cpp
// Purpose: making a label generator
// Author(s): Mohamed Hesham
// ID(s): 20221133
// Section: S21
// Date: 6/12/2023


#include <bits/stdc++.h>
#include <utility>
#define int  long long int
#define ll long long
#define ld long double
#define each const auto &
#define fk(i,n) for(ll i=0;i<ll n;i++)
#define uwu(t) while(t--)
#define endl '\n'
#define coder ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

class  LabelGenerator {
protected:
    string label ;
    int current;
public:
    LabelGenerator (string label , int current) : label(std::move(label)), current(current){}
    virtual  string  nextLabel(){
        cout<<label<<current;
        current++;
        return "";
    }
   [[nodiscard]] int get_label() const{return current;}
};
class FileLabelGenerator :public LabelGenerator{
    vector<string>vec;
    int curr=0;
public:
    FileLabelGenerator (string name,int label ,const string& filename ): LabelGenerator(std::move(name),label) {
        ifstream file;
        string line;
        file.open(filename);
        if(!file.is_open()) {
            cout<<"Error:";
            return;
        }
        while (getline(file,line)) {
            vec.push_back(line);
        }
    }
    string nextLabel() override{
        LabelGenerator::nextLabel();
        cout<<" "<<vec[curr];
        curr++;
        return "";
    }

};
signed main() {

    LabelGenerator figureNumbers("Figure ", 1);

    LabelGenerator pointNumbers("P", 0);

    cout << "Figure numbers: ";

    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << " " << figureNumbers.nextLabel() << ", ";
    }
    cout << endl;

    FileLabelGenerator figureLabels("Figure ", 1, "p1.txt");

    cout << "Figure labels: \n";

    for (int i = 0; i < 3 ; i++) {
        cout << figureLabels.nextLabel() << endl;
    }
    return 0;
}