#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right){
    if(right < left) return -1;
        int m = (right+left)/2;
        if(v[m] > x) return position(x,v,left,m-1);
        if(v[m] < x) return position(x,v,m+1,right);
        return m;
}