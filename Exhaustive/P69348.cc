#include <iostream>
#include <vector>
using namespace std;

void escriu_resultat(vector<int>& result){
    cout << '(';
    for(int i = 0; i < result.size(); ++i){
        if(i == result.size()-1) cout << result[i] << ')';
        else cout << result[i] << ',';
    }
    cout << endl;
}

void juga_perm(vector<int>& result, vector<bool>& used, int index){
    if(result.size() == index) escriu_resultat(result);
    else{
        int n = result.size();
        for(int i = 0; i < n; ++i){
            if(not used[i]){
                result[index] = i+1;
                used[i] = true;
                juga_perm(result,used,index+1);
                used[i] = false;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> result(n);
    vector<bool> used(n,false);
    juga_perm(result,used,0);
}