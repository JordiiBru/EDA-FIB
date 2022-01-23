#include <iostream>
#include <vector>
using namespace std;

int n;

void escriure(vector<char>& result){
    for(int i = 0; i < n; ++i){
        cout << result[i];
    }
    cout << endl;
}
void back(vector<char>& result, int counta, int countb, int index){
    if(index == n) escriure(result);
    else{
        if(counta+1 - countb <= 2){
            result[index] = 'a';
            back(result,counta+1,countb,index+1);
        }
        if(countb+1 -counta<= 2){
            result[index] = 'b';
            back(result,counta,countb+1,index+1);
        }
    }
}

int main(){
   cin >> n;
   vector<char> result(n);
   back(result,0,0,0);
  
}