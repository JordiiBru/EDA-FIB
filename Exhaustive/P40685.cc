#include <iostream>
#include <vector>
using namespace std;

int n;
int s;
vector<int> nums;

void escriu_final(const vector<int>& sol_parcial){
    cout << "{";
    for(int i = 0; i < sol_parcial.size(); ++i){
        cout << (i == 0 ? "" : ",") << sol_parcial[i]; //si es el princioi printa un espai i sino una coma
    }
    cout << '}' << endl;
}


void escriu_solucio(vector<int>& sol_parcial, int suma_parcial, int index){
    if(index == n){
        if(suma_parcial == s) escriu_final(sol_parcial);
    }
    else{
        //aqui no afageixo el nou num
        escriu_solucio(sol_parcial,suma_parcial,index+1);
        //aqui si
        sol_parcial.push_back(nums[index]);
        escriu_solucio(sol_parcial,suma_parcial + nums[index],index+1);
        sol_parcial.pop_back();
    }
}



void escriu_suma(){
    vector<int> sol_parcial;
    int suma_parcial = 0;
    int index = 0;
    escriu_solucio(sol_parcial,suma_parcial,index);
}




int main(){
    cin >> s >> n;
    nums = vector<int>(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    escriu_suma();
}