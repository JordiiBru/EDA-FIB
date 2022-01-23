#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string,int> bag;
    string command;
    while(cin >> command){
        map<string,int>::iterator it = bag.begin();
        if(command == "minimum?"){
            if(bag.empty()) cout << "indefinite minimum" << endl;
            else{
                it = bag.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if(command == "maximum?"){
            if(bag.empty()) cout << "indefinite maximum" << endl;
            else{
                it = bag.end();
                --it;
                //si no funciona, fer un for fins a la ultima posicio, i quan surti haura guardat lultim pair
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if(command == "store"){
            string word;
            cin >> word;
            it = bag.find(word);
            if(it != bag.end()) bag[word] = it->second + 1;
            else bag.insert(pair<string,int>(word,1));         
        }
        else if(command == "delete"){
            string word;
            cin >> word;
            it = bag.find(word);
            if(it != bag.end()) {
                bag[word] = it->second - 1;
                int times = bag[word];
                if(times == 0){
                    bag.erase(it);
                    it = bag.begin();
                }
            }
        }
    }
}