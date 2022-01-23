#include <iostream>
#include <vector>
#include <map>
using namespace std;




int main(){
    int n,j;
    while(cin >> n){
        //vector<string> mygames(n);
        map<string,int> mygames;
        for(int i = 0; i < n; ++i){
            string game;
            cin >> game;
            map<string,int>::iterator it = mygames.find(game);
            if(it == mygames.end()){
                mygames.insert(make_pair(game,1)); 
            }
            else{
                it->second = it->second + 1;           
            }      
        }
        cin >> j;
        //vector<string> futuregames(j);
        for(int i = 0; i < j; ++i){
            string game;
            cin >> game;
            map<string,int>::iterator it = mygames.find(game);
            if(it != mygames.end()){
                int times = it->second;
                if(times < n-times){
                    it->second = it->second + 1;
                    ++n;
                }
            }
            else{
                if(0 < n){
                    mygames.insert(make_pair(game,1));
                    ++n;
                }
            }
        }
        for(map<string,int>::iterator it = mygames.begin(); it != mygames.end(); ++it){
            cout << it->first << ' ' << it->second << endl;
        }
        cout << "--------------------" << endl;
    }
}