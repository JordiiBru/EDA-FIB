#include <iostream>
#include <vector>
using namespace std;

int n,c;

void escriure(vector<char>& result){
    for(int i = 0; i < n; ++i){
        cout << result[i];
    }
    cout << endl;
}

void back(vector<char>& result, int monedas, int acciones, int index){
    if(n == index) escriure(result);
    else{
        if(monedas > 0){
            result[index] = 'b';
            back(result,monedas-1,acciones+1,index+1);
        }
        if(acciones > 0){
            result[index] = 's';
            back(result,monedas+1,acciones-1,index+1);
        }
    }
}

int main(){
    cin >> n >> c;
    vector<char> result(n);
    back(result,c,0,0);
}