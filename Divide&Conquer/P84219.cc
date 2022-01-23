#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right){
    if(right < left) return -1;
    int m = (right+left)/2;
    if(v[m] > x) return position(x,v,left,m-1);        
    else if(v[m] < x) return position(x,v,m+1,right);
    else if(v[m] == x and v[m-1] != x) return m; 
    else if(m >= 1 and v[m-1] == x) return position(x,v,left,m-1);
    return m;
}


int first_occurrence(double x, const vector<double>& v){
    return position(x,v,0,v.size()-1);  
}

int main(){
    int n;
    cin >> n;
    vector<double> v(n);
    
    for(double i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << first_occurrence(4,v) << endl;

}