#include <iostream>
#include <vector>
using namespace std;


void escriu_resultat(vector<string>& result){
    cout << '(';
    for(int i = 0; i < result.size(); ++i){
        if(i == result.size()-1) cout << result[i] << ')';
        else cout << result[i] << ',';
    }
    cout << endl;
}

void juga_perm(vector<string>& result, vector<string>& words,vector<bool>& used, int index){
    if(index == words.size()) escriu_resultat(result);
    else{
        int n = words.size();
        for(int i = 0; i < n; ++i){
            if(not used[i]){
                result[index] = words[i];
                used[i] = true;
                juga_perm(result,words,used,index+1);
                used[i] = false;
            }
        }
    }
}



int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; ++i) cin >> words[i];
    vector<string> result(words.size());
    vector<bool> used(words.size(),false);
    juga_perm(result,words,used,0);
}