#include <iostream>
#include <vector>
using namespace std;

int n,unos;

void escriure(vector<int>& result){
    cout << result[0];
    for(int i = 1; i < result.size(); ++i) cout << ' ' << result[i];
    cout << endl;
}

void back(vector<int>& result, int count0, int count1, int index){
    if(index == n) escriure(result);
    else{
        if(count0 < n-unos){
            result[index] = 0;
            back(result,count0+1,count1,index+1);
        }
        if(count1 < unos){
            result[index] = 1;
            back(result,count0,count1+1,index+1);
        }
    }
}


int main(){
    cin >> n >> unos;
    vector<int> result(n);
    back(result,0,0,0);
}