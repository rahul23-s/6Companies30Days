// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        string ans;
        stack<string> chars;
        stack<int> nums;
        int num = 0 ;
        
        for(char c :s ){
            if(isalpha(c)){
                ans.push_back(c);
            }
            else if(isdigit(c)){
                num = num*10+ c-'0';
            }       
            else if(c =='['){
                chars.push(ans);
                nums.push(num);
                ans="";
                num=0;
            }
            else if(c==']'){
                string temp = ans;
                for(int i=0; i<nums.top()-1 ;i++){
                    ans += temp;
                }
                ans= chars.top()+ans;
                chars.pop();
                nums.pop();
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends