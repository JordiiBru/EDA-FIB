#include <iostream>
#include <vector>
using namespace std;

int n;

void escriure(vector<char>& result){
    for(int i = 0; i < n; ++i) cout << result[i];
    cout << endl;
}

void backtracking(vector<char>& result, int index){
    if(index == n) escriure(result);
    else{
        result[index] = 'A';
        backtracking(result,index+1);
        result[index] = 'C';
        backtracking(result,index+1);
        result[index] = 'G'; 
        backtracking(result,index+1);
        result[index] = 'T'; 
        backtracking(result,index+1);
    }
}

int main(){
    cin >> n;
    vector<char> result(n);
    backtracking(result,0);
}