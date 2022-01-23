#include <iostream>
#include <vector>
using namespace std;

int n;

void escriure(vector<string>& result){
    for(int i = 0; i < result.size(); ++i) cout << result[i];
    cout << endl;
}

void back(vector<string>& result, vector<string>& words, vector<bool>& used, int index){
    if(n == index) escriure(result);
    else{
        for(int i = 0; i < n; ++i){
            if(not used[i]){
                if(index != 0){
                    if(result[index-1][result[index-1].size()-1] != words[i][0]){
                        result[index] = words[i];
                        used[i] = true;
                        back(result,words,used,index+1);
                        used[i] = false;
                    }
                }
                else{
                    result[index] = words[i];
                    used[i] = true;
                    back(result,words,used,index+1);
                    used[i] = false;
                }
                
            }
        }
    }
}


int main(){
    cin >> n;
    vector<string> result(n);
    vector<string> words(n);
    for(int i = 0; i < n; ++i) cin >> words[i];
    vector<bool> used(n,false);
    back(result,words,used,0);
}