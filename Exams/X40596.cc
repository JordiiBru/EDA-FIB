#include <iostream>
#include <vector>
using namespace std;

int n,d;

void escriure(vector<int>& result){
    cout << '(' << result[0];
    for(int i = 1; i < result.size(); ++i){
        cout << ',' << result[i];
    }
    cout << ')' << endl;
}


void back(vector<int>& result, vector<bool>& usado, int index){
    if(index == n) escriure(result);
    else{
        for(int i = 0; i < n; ++i){
            if(not usado[i]){
                if(index != 0){
                    int caso1 = result[index-1]-(i+1);
                    int caso2 = -1*caso1;
                    if((caso1 >= 0 and caso1 <= d) or (caso2 >= 0 and caso2 <= d)){
                        usado[i] = true;
                        result[index] = i+1;
                        back(result,usado,index+1);
                        usado[i] = false;
                    }
                }
                else{
                    usado[i] = true;
                    result[index] = i+1;
                    back(result,usado,index+1);
                    usado[i] = false;
                }
                
            }
        }
    }
}


int main(){
    cin >> n >> d;
    vector<int> result(n);
    vector<bool> usado(n,false);
    back(result,usado,0);
}