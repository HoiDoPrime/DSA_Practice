#include <bits/stdc++.h>
using namespace std;
bool capdau(char x,char y){
    return (x=='[' && y==']' || x=='{' && y=='}' || x=='(' && y==')');
}
bool check(string s){
    stack<char> st;
    for(char x: s){
        if(x=='(' || x=='{' || x=='['){
            st.push(x);
        }
        else{
            if(st.empty()) return false;
            char y=st.top(); st.pop();
            if(!capdau(y,x)) return false;
            
        }
    }
    return st.empty();
}
int main(){
    string s;cin>>s;
    if(check(s)){
        cout<<"Bieu thuc hop le\n";
    }
    else cout<<"Bieu thuc khong hop le\n";
    return 0;
}
//       ()(())
//       Bieu thuc hop le


//       [{}]
//       Bieu thuc khong hop le