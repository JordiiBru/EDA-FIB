#include <iostream>
#include <vector>
using namespace std;

int n;

void escriure(vector<int>& result){
    cout << '(' << result[0];
    for(int i = 1; i < result.size(); ++i) cout << ',' << result[i];
    cout << ')';
    cout << endl;
}

void back(vector<int>& result, vector<bool>& used, int index){
    if(index == n) escriure(result);
    else{
        for(int i = 0; i < n; ++i){
            if(not used[i]){
                if(index != 0 and index != 1){
                    if(result[index-1]*2 >= result[index-2]+i+1){
                        result[index] = i+1;
                        used[i] = true;
                        back(result,used,index+1);
                        used[i] = false;  
                    }
                }
                else{
                    result[index] = i+1;
                    used[i] = true;
                    back(result,used,index+1);
                    used[i] = false;
                }
                
            }
        }
    }
}


int main(){
   cin >> n;
   vector<int> result(n);
   vector<bool> used(n);
   back(result,used,0);
}