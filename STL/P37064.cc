
#include <iostream>
#include <set>
using namespace std;

void print_seq(set<string> &seq){
    cout << "tota la seq: ";
    for(set<string>::iterator it = seq.begin(); it != seq.end(); ++it){
        cout << *it << ' ';
    }
    cout << endl;
}

int main(){
    set<string> sequence;
    set<string>::iterator median = sequence.end();
    string word;
    while(cin >> word and word != "END"){
       set<string>::iterator it = sequence.insert(word).first;
		if (median == sequence.end()) median = it;
		else if (sequence.size()%2==0 and word < *median) --median;
		else if (sequence.size()%2!=0 and word > *median) ++median;
		cout << *median << endl;

    }
}