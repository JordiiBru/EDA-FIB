#include <iostream>
#include <vector>
using namespace std;

int n;

void escriure(vector<char>& result){
    for(int i = 0; i < n; ++i) cout << result[i];
    cout << endl;
}

void backtracking(vector<char>& result, int x, int y, int index){
    if(n == index) escriure(result);
    else{
        if(y-1 >= 0){
            result[index] = 'd';
            backtracking(result,x+1,y-1,index+1);
        }
        result[index] = 'h';
        backtracking(result,x+1,y,index+1);
        result[index] = 'u';
        backtracking(result,x+1,y+1,index+1);
    }
}

int main(){
    cin >> n;
    vector<char> result(n);
    backtracking(result,0,0,0);
}