#include<bits/stdc++.h> //un
#include <vector>

#define ll long long 
using namespace std;

class Console{
    public:
        void log(string s){
           cout<<s<<endl;
        }

        void log(int i){
            cout<<i<<endl;
        }

        void log(vector<int> input){
            for(auto i : input){
                cout<<i<<" ";
            }
            cout<<endl;
        }
};


Console console;
void solve(){
    vector<int> input = {5,3,4}; // 1 3 6 13 18  target
    int target = 8;
    int left = 0;
    int right = 0;
    int sum = 0;
    vector<int> ans;
    for(int i =0;i<input.size();i++){
        sum+= input[i];
        while(sum >= target){
            if(sum == target){
                console.log(left+1);
                console.log(i+1);
                ans.push_back(left+1);
                ans.push_back((i+1));
                break;
            }
            sum -= input[left];
        }
    }
    if(ans.size() == 0){
        ans.push_back(-1);
    }
    console.log(ans);
}  


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    while(t--){

        solve();
    }
    return 0;
}


