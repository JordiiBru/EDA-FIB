#include <iostream>
#include <vector>

using namespace std;

bool position(double x, const vector<double>& v, int left, int right){
    if(right < left) return false;
    int m = (right+left)/2;
    if(v[m] == x) return true;
    if(m > 0 and v[m-1] == x) return true;
    if(m < v.size()-1 and v[m+1] == x) return true;
    if(v[m] > x) return position(x,v,left,m-1);        
    if(v[m] < x) return position(x,v,m+1,right);    
    return true;
}


bool resistant_search(double x, const vector<double>& v){
    return position(x,v,0,v.size()-1);
}
/*
vull trobar  el 2
0 2 4 3 6 8 10
    ^
*/


int main(){
    int n;
    int m;
    cin >> m; //num a buscar
    cin >> n;
    vector<double> v(n);
    
    for(double i = 0; i < n; i++){
        cin >> v[i];
    }
   cout << position(m,v,0,n-1) << endl;
}