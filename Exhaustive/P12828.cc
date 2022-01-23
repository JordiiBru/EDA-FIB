#include <iostream>
#include <vector>
using namespace std;

int n;

void escriu_seq(vector<int>& nums){
    for(int i = 0; i < nums.size(); ++i){
        if(i == n-1) cout << nums[i] << endl;
        else cout << nums[i] << ' ';
    }
}

void goto_seq(vector<int>& nums, int index){
    if(index == n){
        escriu_seq(nums);
    }
    else{
        nums[index] = 0;
        goto_seq(nums,index+1);
        nums[index] = 1;
        goto_seq(nums,index+1);
    }
}


void crear_seq(){
    int index = 0;
    vector<int> nums(n);
    goto_seq(nums,index);
}


int main(){
    cin >> n;
    crear_seq();
}