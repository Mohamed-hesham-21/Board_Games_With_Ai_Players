//
// Created by mohamed on 12/7/2023.
//
#include <bits//stdc++.h>
#include <fstream>
#include <utility>
using namespace std;
class task{

public:
    string image_name ,PID , memory ,session_hash ,session,usage;
    task(string image_name, string id,string memory,string  session_hash,string  session,string usage ):usage(std::move(usage)),image_name(std::move(image_name)),memory(std::move(memory)),session(std::move(session)),PID(std::move(id)),session_hash(std::move(session_hash)){

    }
    void print_task() const {
        cout << image_name;

        if (sizeof("                        ") - image_name.size() < sizeof("========================= ")) {
            for (int i = 0; i < sizeof("                        ") - image_name.size(); ++i) {
                cout << " ";
                if (i == size("                        ")) break;
            }

        }
        if(sizeof("       0") -PID.size()<sizeof ("       0")){
            for (int i = 0; i < sizeof("       0") - PID.size(); ++i) {
                cout << " ";
                if (i == size("       0")) break;
            }

        }
        cout << PID << " "<<session<<"        ";
        if (sizeof("          0") - session_hash.size() < sizeof("        0")) {
            for (int i = 0; i < sizeof("          0") -session_hash.size(); ++i) {
                cout << " ";
                if (i == size("          0")) break;
            }

        }
        cout<<session_hash<<" ";
        if(PID.size()<sizeof ("         8 K")){
            for (int i = 0; i < sizeof("         8 K") - PID.size(); ++i) {
                cout << " ";
                if (i == size("         8 K")) break;
            }

        }
        cout<<memory<<" "<<usage<<endl;
    }

};
istream& line_x (istream& is, string& str , string& delim){
    str="";
    char ch;
    while(is.get(ch)){
        str.push_back(ch);
        if(str.find(delim)!=string::npos){
            break;
        }

    }
    return is;
}
vector<task >tasks;
bool by_name(const task &a, const task &b){
    return a.image_name>b.image_name;
}
bool by_session(const task &a, const task &b){
    return a.session>b.session;
}
bool by_memory(const task &a, const task &b){
   string mem1, mem2;
    for (char i : a.memory) {
        if(isdigit(i)) mem1.push_back(i);
    }

    for (char i : b.memory) {
        if(isdigit(i)) mem2.push_back(i);
    }


    return stoi(mem1)>stoi(mem2);
}
bool by_id(const task &s,const task &b){
    string id1,id2;
    for (char i : s.PID) {
        id1.push_back(i);
    }
    for (char i : b.PID) {
        id2.push_back(i);
    }
    return  stoi(id1)> stoi(id2);
}
bool by_session_hash (const task &a,const task &b){
    return a.session_hash > a.session_hash;
}
void getTasks(){
    ifstream input;
    string name,memory,usage,session_hash,session,id,delim="  ";
    system("tasklist > input.txt");
    input.open("input.txt");
    getline(input,name);
    getline(input,memory);
    getline(input,id);
    while(input.good()) {
        line_x(input, name, delim);
        input>>id>>session>>session_hash>>memory>>usage;
        tasks.push_back({name,id,memory,session_hash,session,usage});
    }
}

int main()
{

    cout<<"--------Task Manager--------\n"
          "1.run once\n"
          "2.run  forever\n"
          "3.Exit\n"
          "-----------------------------\n";
    int op;
    while(1) {
cout<<"choice : ";
        cin >>op;
        if(op <4 && op >=1)break;
    }
    if(op ==1){
         cout<<"---------------------\n"
                   "1.sort by name\n"
                   "2.sort by id\n"
                   "3.sort by session\n"
               "4.sort by session#\n"
               "5.sort by memory\n"
                   "-----------------------------\n";
        while(true) {
            cout<<"choice : ";
            cin >>op;
            if(op <6 && op >=1)break;
        }
        getTasks();
        cout<<endl;
        switch (op) {
            case 1: {

                    sort(tasks.begin(),tasks.end(), by_name);
                break;
                }
            case 2 :{
                sort(tasks.begin(),tasks.end(), by_id);
                break;

            }
            case 3 :{
                sort(tasks.begin(),tasks.end(), by_session);
            break;
            }
            case 4:{
                sort(tasks.begin(),tasks.end(), by_session_hash);
                break;

            }
            case 5 :{
                sort(tasks.begin(),tasks.end(), by_memory);
            }
        }
        for (const auto& task : tasks) {
            task.print_task();
        }
    }
    else if(op==2){
        cout<<"---------------------\n"
              "1.sort by name\n"
              "2.sort by id\n"
              "3.sort by session\n"
              "4.sort by session#\n"
              "5.sort by memory\n"
              "-----------------------------\n";

        while(true) {
            cout<<"choice : ";
            cin >>op;
            if(op <6 && op >=1)break;
        }
        getTasks();
        switch (op) {
            case 1: {
                while(1){
                    system("cls");
                    getTasks();
                    sort(tasks.begin(),tasks.end(), by_name);
                    for (const auto& task : tasks) {
                        task.print_task();
                    }
                    tasks.clear();
                    break;
                }
            }
            case 2 :{
                while(1){
                    system("cls");
                    getTasks();
                    sort(tasks.begin(),tasks.end(), by_id);
                    for (const auto& task : tasks) {
                        task.print_task();
                    }

                }
                break;

            }
            case 3 :{
                while(1){
                    system("cls");
                    getTasks();
                    sort(tasks.begin(),tasks.end(), by_session);
                    for (const auto& task : tasks) {
                        task.print_task();
                    }
                    break;
                }
            }
            case 4:{
                while(1){
                    system("cls");
                    getTasks();
                    sort(tasks.begin(),tasks.end(), by_session_hash);
                    for (const auto& task : tasks) {
                        task.print_task();
                    }
                    break;
                }
            }
            case 5 :{
                while(1){
                    system("cls");
                    getTasks();
                    sort(tasks.begin(),tasks.end(), by_memory);
                    for (const auto& task : tasks) {
                        task.print_task();
                    }
                    break;
                }
            }
        }
    }




}