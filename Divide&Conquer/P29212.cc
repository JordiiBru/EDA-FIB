#include <iostream>
using namespace std;


int exp_modular(int n, int k, int m){
    if(k == 0) return 1;
    if(k <= 1) return n%m;
    else{
        int primer = exp_modular(n,k/2,m)%m;
        if(k % 2 == 0) return (primer*primer) % m; //parell x*x
        else return (((primer*primer) % m)*n) % m; //impar x*x*n
    }
}

/*
int exp_mod(int n, int k, int m) {
	if(k == 0) return 1;
	if (k <= 1) return n%m;
	else {
		int x = exp_mod(n, k/2, m)%m;
		if (k%2 == 0) return (x*x)%m;
		else return (((x*x)%m)*n)%m;
	}
}*/


int main(){
    int n,k,m;
    while(cin >> n >> k >> m){
        //n^k mod m ---> 5/2 = 4 ; 5 - 4 = 1 ; 
        int res = exp_modular(n,k,m);
        cout << res << endl;


    }

}