#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void printq(priority_queue<int> q){
    priority_queue<int> aux = q;
    while(!aux.empty()){
        cout << aux.top() << ' ';
        aux.pop();
    }
    cout << endl;
}

int main(){
    priority_queue<int> cua;
    char command;
    while(cin >> command){
        int value=0;

        if(command == 'S'){
            cin >> value;
            cua.push(value);
            //cout << cua.top() << endl;
        }
        else if(command == 'A'){
            if(cua.empty()) cout << "error!" << endl;
            else cout << cua.top() << endl;
        }
        else if(command == 'R'){
            if(cua.empty()) cout << "error!" << endl;
            else cua.pop();
            
        }
        else if(command == 'I'){
            cin >> value;
            if(cua.empty()) cout << "error!" << endl;
            else{
                int aux = cua.top();
                cua.pop();
                cua.push(aux+value);
            }
        }
        else if(command == 'D'){
            cin >> value;
            if(cua.empty()) cout << "error!" << endl;
            else{
                int aux = cua.top();
                cua.pop();
                cua.push(aux-value);
            }

        }
        //printq(cua);
       /*if(cua.empty() and command != 'A') cout << "error!" << endl;
        else if(command != 'A') cout << cua.top() << endl;*/
        
    }

}