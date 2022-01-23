#include <iostream>
#include <vector>
using namespace std;


int s,n;

void escriure(vector<int>& nums,vector<bool>& used){
    bool first = true;
    cout << '{';
    for(int i = 0; i < n; ++i){
        if(used[i]){
            if(first) first = false;
            else cout << ',';
            cout << nums[i];
        }
    }
    cout << '}' << endl;
}



void back(vector<int>& nums, vector<bool>& used, int count, int restante, int index){
    if(count > s) return;
    if(count + restante < s) return;
    if(index == n) escriure(nums,used);
    else{
        used[index] = false;
        back(nums,used,count,restante-nums[index],index+1);
        used[index] = true;
        back(nums,used,count+nums[index],restante-nums[index],index+1);
    }
}

int main(){
    cin >> s >> n;
    vector<int> nums(n);
    vector<bool> used(n,false);
    int count = 0;
    for(int i = 0; i < n; ++i) {cin >> nums[i]; count = count + nums[i];}
    back(nums,used,0,count,0);
}