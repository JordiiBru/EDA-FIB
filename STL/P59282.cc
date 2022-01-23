#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main(){
    cout.setf(ios::fixed);
	cout.precision(4);

    priority_queue<int, vector<int>, greater<int> > cua;
    string command;
    int biggest=0;
    double sum=0;
    while(cin >> command){
        if(command == "number"){
            int n;
            cin >> n;
            if(cua.empty()) biggest = n;
            else{
                if(biggest < n) biggest = n;
            }
            sum = sum + n;
            cua.push(n);
        }
        else if(command == "delete"){
            if(not cua.empty()){
                sum = sum - cua.top();
                cua.pop();
            } 

        }
        if(not cua.empty()){
            cout << "minimum: " << cua.top();
            cout << ", maximum: " << biggest;
            cout << ", average: " << sum/cua.size();
            cout << endl;
        }
        else cout << "no elements" << endl;
    }
    
}