#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <map>
#include<string>
using namespace std;

class Set_String{
protected:
    vector<string> list_of_words;
    map<string, int > freq;
public:
    Set_String(){

    }

    Set_String(const Set_String& s) {

        this->list_of_words= s.list_of_words;
        this->freq= s.freq;
    }
    Set_String(ifstream &Myfile){


        char c ;
        string line ;

        string word="" ;

        while (Myfile>> line)
        {for (int i = 0; i < line.size();i++){
                c = line[i];
                c = tolower(c);
                if (('a'<=c&&'z'>=c))
                {
                    word+=c;
                }
                else if (!word.empty())
                {

                    list_of_words.push_back(word);
                    word="";
                }
            }
            if (!word.empty())
            {
                if (!freq[word]){list_of_words.push_back(word);freq[word]=1;}
                word="";
            }

        }


    }

    Set_String(string line ){
        string word{};
        char c {};
        for (int i = 0; i < line.size();i++){
            c = line[i];
            c = tolower(c);
            if (('a'<=c&&'z'>=c))
            {
                word+=c;
            }
            else if (!word.empty())
            {

                list_of_words.push_back(word);
                word="";
            }
        }
        if (!word.empty())
        {
            if (!freq[word]){list_of_words.push_back(word);freq[word]=1;}
            word="";
        }

    }



    friend void Print(Set_String  a);
    friend void Add(Set_String  a,string s );
    friend void Remove(Set_String  a,string s );
    friend void Clear(Set_String  a);
    friend int No_of_strings(Set_String  a);
    friend double Sim(Set_String a, Set_String b);
    Set_String operator+ (Set_String  a){
        for (size_t i = 0; i < this->list_of_words.size(); i++)
        {string word = this->list_of_words[i];
            if (!a.freq[word]){a.list_of_words.push_back(word);a.freq[word]=1;}
        }
        return a;

    }


    Set_String operator *(Set_String a){

        for (size_t i = 0; i < a.list_of_words.size(); i++)
        {
            string word = a.list_of_words[i];
            if (!this->freq[word]){a.list_of_words.erase(a.list_of_words.begin()+i);i--;}
        }

        return a;
    }


};

void Print(Set_String a){
    for (size_t i = 0; i <a.list_of_words.size()-1; i++)
    {
        cout << a.list_of_words[i]<<" ";
    }
    cout << a.list_of_words[a.list_of_words.size()-1]<<endl;

}

void Add(Set_String a , string s ){
    if (!a.freq[s])
    {a.list_of_words.push_back(s);
        a.freq[s]++;}
}
void Remove(Set_String a , string s){
    for (size_t i = 0; i < a.list_of_words.size(); i++)
    {
        if (a.list_of_words[i]==s)
        {
            a.list_of_words.erase(a.list_of_words.begin()+i);
            a.freq[s]--;
            break;
        }

    }

}
void Clear(Set_String a ){
    a.list_of_words.clear();
    a.freq.clear();
}

int No_of_strings(Set_String a){
    return a.list_of_words.size();
}

double Sim(Set_String a, Set_String b){
int s{} , d{};
for (size_t i = 0; i < a.list_of_words.size(); i++)
{
    string word = a.list_of_words[i];
    if (b.freq[word])
    {
        s++;
    }
    else d++;
}
int sb = b.list_of_words.size();
int sa = a.list_of_words.size();
d +=(sb-s);
double div  = sa*sb;
return (double)((double)s/sqrt(div)); 
 
}

int main (){

    string file1,file2;
    cin >> file1>> file2;
    ifstream Myfile1(file1),Myfile2(file2);

    Set_String a (Myfile1);
    Set_String b (Myfile2);
    string line1 ;
    getline(cin, line1);
    Set_String e (line1);
    Print(a);
    Print(b);
    Print(e);
    Set_String c = a*b;
    Set_String d = a +b;
    Print(d);
    Print(c);
    Print(a);
    Print(b);
    cout << Sim(a,b) << endl;
    



}