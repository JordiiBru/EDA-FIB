#include <iostream>
#include <map>
using namespace std;


bool consulta_jugador(map<string,int> &data, string &nom){
    map<string,int>::iterator it = data.find(nom);
    if(it != data.end()) return true;
    else return false;
}

int main(){
    map<string,int> data;
    string username;
    while(cin >> username){
        string command;
        cin >> command;       
        if(command == "enters"){
            if(consulta_jugador(data,username)) cout << username << " is already in the casino" << endl;
            else {data.insert(pair<string,int>(username,0)); }           
        }
        else if(command == "wins"){
            int prize=0;
            cin >> prize;
            if(not consulta_jugador(data,username)) cout << username << " is not in the casino" << endl;
            else{
                int balance_actual = data[username] + prize;
                data[username] = balance_actual;
            }       
        }
        else if(command == "leaves"){
            if(not consulta_jugador(data,username)) cout << username << " is not in the casino" << endl;
            else{
                int cash = data[username];
                cout << username << " has won " << cash << endl;
                auto it = data.find(username);
                data.erase(it);
                it = data.begin();   
            }           
        }
    }
    cout << "----------" << endl;

    for(auto it = data.begin(); it != data.end(); ++it){
        cout << it->first << " is winning " << it->second << endl;
    }
}   