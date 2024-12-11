#include<bits/stdc++.h> 
#include <iostream>
#include <sstream>
#include <vector>


//advent of code day 2 i know I am lame don't need to write that in chat f**kers
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

/*
   The levels are either all increasing or all decreasing. [ check this will that
   make the next one effecient]
   Any two adjacent levels differ by at least one and at most three. []


// check if the array is strictly increasing or decreasing
// check the difference between 2 adj numbers being greater 1 and almost 3 
// diff > 1 && diff <= 3 
// 
*/


bool isIncreasing(vector<int>& vec){ // this only say that it is increasing
    bool ans = true;
    for(int i=1;i<vec.size();i++){
        if(vec[i] > vec[i-1]){
            continue;
        }
        else{
            ans = false;
        }
    }
    return ans;
}

bool isDecreasing(vector<int>& vec){ // this only say that it is increasing
    bool ans = true;
    for(int i=1;i<vec.size();i++){
        if(vec[i] < vec[i-1]){
            continue;
        }
        else{
            ans = false;
        }
    }
    return ans;
}

bool secondTry(vector<int>& vec){
    bool ans = true;
    for(int i=1;i<vec.size();i++){
        int diff = abs(vec[i] - vec[i-1]);
        if(diff >=1 && diff<=3){
            continue;
        }
        else{
            ans = false;
        }
    }
    return ans;
}

bool  goCheckForDiff(vector<int>& vec){
    bool ans = true;
    int number_of_f = 0;
    // 1 3 2 4 8
    // if there is a unsafe rec 1 with 2
    vector<int> sec;
    for(int i=1;i<vec.size();i++){
        int diff = abs(vec[i]-vec[i-1]);
        int backdiff = abs(vec[i+1] - vec[i-1]);
        if(diff >= 1 && diff <=3){
            sec.push_back(vec[i]);
            continue;
        }
        else{
           if(number_of_f<2)  {
               sec.push_back(vec[i]);
           }
           number_of_f++;
        }
    }
    if(number_of_f > 1 && secondTry(sec) == false){
        ans = false;
    }
    return ans;
}

void solve(){

    ifstream inputFile("./smallinput.txt"); // Replace "input.txt" with your file name
    vector<vector<int>> input_value;

    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    vector<int> numbers; // To store integers read from the file
    string line;
    int num;

    // Read integers from the file
    while (getline(inputFile,line)) {
        stringstream ss(line);
        vector<int>row;
        int num;
        while(ss >> num){
            row.push_back(num);
        }
        input_value.push_back(row);
    }

    // Close the file
    inputFile.close();
    int count = 0;
    for(auto i : input_value){
        bool currentRes = isIncreasing(i) || isDecreasing(i);
        if(currentRes){
            console.log("entering here");
            bool ans = goCheckForDiff(i);
            count += ans?1:0;
        }
        
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    // Display the integers
    console.log(count);
    return ;

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


